/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"
#include "atomic_arch.h"
#include <sys/wait.h>

#ifdef __GNUC__
__attribute__((__noinline__))
#endif
static int locking_getc(FILE *f)
{
	if (a_cas(&f->lock, 0, MAYBE_WAITERS-1)) __lockfile(f);
	int c = getc_unlocked(f);
	if (a_swap(&f->lock, 0) & MAYBE_WAITERS)
		f->lock = 1; //__wake(&f->lock, 1, 1); -> FUTEX_WAKE!!!
	return c;
}

static inline int do_getc(FILE *f)
{
	int l = f->lock; pid_t tid = getpid();
	if (l < 0 || l && (l & ~MAYBE_WAITERS) == tid) //__pthread_self()->tid)
		return getc_unlocked(f);
	return locking_getc(f);
}
