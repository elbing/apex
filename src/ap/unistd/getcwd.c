/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "sys9.h"


char*
getcwd(char *buf, size_t len)
{
	int fd;

	fd = __sys_open(".", OREAD);
	if(fd < 0) {
		errno = EACCES;
		return 0;
	}
	if(fd2path(fd, buf, len) < 0) {
		errno = EIO;
		__sys_close(fd);
		return 0;
	}
	__sys_close(fd);

/* RSC: is this necessary? */
	if(buf[0] == '\0')
		strcpy(buf, "/");
	return buf;
}
