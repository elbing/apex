/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include "sys9.h"
#include "lock.h"

void
__lock(volatile int *lk)
{
	while(__tas(lk))
		__sys_sleep(0);
}

int
__canlock(volatile int *lk)
{
	if(__tas(lk))
		return 0;
	return 1;
}

void
__unlock(volatile int *lk)
{
	lk[0] = 0;
}
