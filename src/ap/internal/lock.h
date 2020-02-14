/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef __LOCK_H
#define __LOCK_H


typedef struct
{
	int	val;
} Lock;

#ifdef __cplusplus
extern "C" {
#endif

extern	void	__lock(volatile int *);
extern	void	__unlock(volatile int *);
extern	int	__canlock(volatile int *);
extern	int	__tas(volatile int *);

#define LOCK(x) __lock(x)
#define UNLOCK(x) __unlock(x)

#ifdef __cplusplus
}
#endif

#endif
