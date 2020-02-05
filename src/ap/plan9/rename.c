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
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "sys9.h"
#include "lib.h"
#include "dir.h"

int
rename(const char *from, const char *to)
{
	int n;
	char *f, *t;
	Dir *d, nd;

	if(access(to, 0) >= 0){
		if(__sys_remove(to) < 0){
			_syserrno();
			return -1;
		}
	}
	if((d = _dirstat(to)) != nil){
		free(d);
		errno = EEXIST;
		return -1;
	}
	if((d = _dirstat(from)) == nil){
		_syserrno();
		return -1;
	}
	f = strrchr(from, '/');
	t = strrchr(to, '/');
	f = f? f+1 : (char *)from;
	t = t? t+1 : (char *)to;
	n = 0;
	/* Theorically, due to auth issues, _dirwstat won't work here */
	if(0 && (f-from==t-to && strncmp(from, to, f-from)==0)){
		/* from and to are in same directory (we miss some cases) */
		_nulldir(&nd);
		nd.name = t;
		if(_dirwstat(from, &nd) < 0){
			_syserrno();
			n = -1;
		}
	}else{
		/* different directories: have to copy */
		int ffd, tfd;
		char buf[8192];

		tfd = -1;
		if((ffd = __sys_open(from, 0)) < 0 ||
		   (tfd = create(to, 1, d->mode)) < 0){
			__sys_close(ffd);
			_syserrno();
			n = -1;
		}
		while(n>=0 && (n = __sys_read(ffd, buf, 8192)) > 0)
			if(__sys_write(tfd, buf, n) != n){
				_syserrno();
				n = -1;
			}
		__sys_close(ffd);
		__sys_close(tfd);
		if(n>0)
			n = 0;
		if(n == 0) {
			if(__sys_remove(from) < 0){
				_syserrno();
				return -1;
			}
		}
	}
	free(d);
	return n;
}
