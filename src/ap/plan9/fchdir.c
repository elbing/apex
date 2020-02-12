/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
#include <sys9.h>
#include "lib.h"

int
fchdir(int fd)
{
    char buf[_POSIX_PATH_MAX];
    struct stat s;
    int n;

    if(fstat(fd, &s) < 0)
        return -1;
    if(!S_ISDIR(s.st_mode)){
        errno = ENOTDIR;
        return -1;
    }
    if(fd2path(fd, buf, sizeof buf) < 0){
        _syserrno();
        return -1;
    }
    n = chdir(buf);
    if(n < 0)
        _syserrno();
    return n;
}
