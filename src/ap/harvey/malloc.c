/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <sys/types.h>
#include "lock.h"

enum
{
	MAGIC		= 0xbada110c,
	MAX2SIZE	= 64,
	CUTOFF		= 24,
};

typedef struct Bucket Bucket;
struct Bucket
{
	ssize_t	size;
	ssize_t	magic;
	Bucket	*next;
	ssize_t	pad;
	char	data[1];
};

typedef struct Arena Arena;
struct Arena
{
	Bucket	*btab[MAX2SIZE];
};
static Arena arena;

#define datoff		((ssize_t)((Bucket*)0)->data)

extern	void	*sbrk(uint64_t);
static volatile int lock[1];

void*
malloc(size_t size)
{
	size_t next;
	ssize_t pow, n;
	Bucket *bp, *nbp;

	for(pow = 1; pow < MAX2SIZE; pow++) {
		if(size <= (1<<pow))
			goto good;
	}

	return NULL;
good:
	/* Allocate off this list */
	bp = arena.btab[pow];
	if(bp) {
		arena.btab[pow] = bp->next;

		if(bp->magic != 0)
			abort();

		bp->magic = MAGIC;
		return  bp->data;
	}
	size = sizeof(Bucket)+(1<<pow);
	size += 7;
	size &= ~7;

	if(pow < CUTOFF) {
		n = (CUTOFF-pow)+2;
		bp = sbrk(size*n);
		if((intptr_t)bp == -1) {
			return NULL;
		}

		next = (size_t)bp+size;
		nbp = (Bucket*)next;
		arena.btab[pow] = nbp;
		for(n -= 2; n; n--) {
			next = (size_t)nbp+size;
			nbp->next = (Bucket*)next;
			nbp->size = pow;
			nbp = nbp->next;
		}
		nbp->size = pow;
	}
	else {
		bp = sbrk(size);
		if((intptr_t)bp == -1){
			return NULL;
		}
	}

	bp->size = pow;
	bp->magic = MAGIC;

	return bp->data;
}

void
free(void *ptr)
{
	Bucket *bp, **l;

	if(ptr == NULL)
		return;

	/* Find the start of the structure */
	bp = (Bucket*)((size_t)ptr - datoff);

	if(bp->magic != MAGIC)
		abort();

	bp->magic = 0;
	l = &arena.btab[bp->size];
	bp->next = *l;
	*l = bp;
}

void*
realloc(void *ptr, size_t n)
{
	void *new;
	size_t osize;
	Bucket *bp;

	if(n == 0) {
		free(ptr);
		return NULL;
	}

	if(ptr == NULL)
		return malloc(n);

	/* Find the start of the structure */
	bp = (Bucket*)((size_t)ptr - datoff);

	if(bp->magic != MAGIC)
		abort();

	/* enough space in this bucket */
	osize = 1<<bp->size;
	if(osize >= n)
		return ptr;

	new = malloc(n);
	if(new == NULL)
		return NULL;

	memmove(new, ptr, osize);
	free(ptr);

	return new;
}