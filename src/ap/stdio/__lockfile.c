/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "sys9.h"
#include "stdio_impl.h"
#include "atomic_arch.h"
//#include <sys/wait.h>


/* Crappy, awaiting pthreads implementation */

int __lockfile(FILE *f)
{
/*
	int owner = f->lock; pid_t tid = getpid(); //__pthread_self()->tid;
	if ((owner & ~MAYBE_WAITERS) == tid)
		return 0;
	owner = a_cas(&f->lock, 0, tid);
	if (!owner) return 1;
	while ((owner = a_cas(&f->lock, 0, tid|MAYBE_WAITERS))) {
		if ((owner & MAYBE_WAITERS) ||
		    a_cas(&f->lock, owner, owner|MAYBE_WAITERS)==owner)
			semacquire(&f->waiters, 1); //__futexwait(&f->lock, owner|MAYBE_WAITERS, 1);
	}
	return 1;
*/
    if(adec(&f->lock) < 0)
        while(semacquire(&f->waiters, 1) < 0){
        /* interrupted, retry */
    }
    // FLOCK checks if >=0 for calling this function
    f->lock = -1;
    return 1;
}

void __unlockfile(FILE *f)
{
/*
	if (a_swap(&f->lock, 0) & MAYBE_WAITERS)
		semrelease(&f->waiters, 1); //__wake(&f->lock, 1, 1);
*/
    if(ainc(&f->lock) >= 0)
        semrelease(&f->waiters, 1);
}
