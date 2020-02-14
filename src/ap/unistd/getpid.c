/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "sys9.h"
#include "lib.h"

pid_t
getpid(void)
{
	int n, f;
	char pidbuf[15];

	f = __sys_open("#c/pid", 0);
	n = __sys_read(f, pidbuf, sizeof pidbuf);
	if(n < 0)
		_syserrno();
	else
		n = atoi(pidbuf);
	__sys_close(f);
	return n;
}
