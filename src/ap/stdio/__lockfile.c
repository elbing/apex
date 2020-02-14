/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include "sys9.h"
#include "stdio_impl.h"
#include "lock.h"

static volatile int flock[1];

int __lockfile(FILE *f)
{
	if(f->lock > 0)
		return 0;

	flock[0] = f->lock;
	__lock(flock);
	return 1;

}

void __unlockfile(FILE *f)
{
	flock[0] = f->lock;
	__unlock(flock);
}
