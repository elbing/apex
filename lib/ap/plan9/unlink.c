/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include "lib.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sys9.h"
#include "dir.h"


/*
 * BUG: errno mapping
 */

int
unlink(const char *path)
{
	int n, i, fd;
	int64_t nn;
	Dir *db1, *db2, nd;
	Fdinfo *f;
 	char *p, newname[PATH_MAX], newelem[32];

	/* if the file is already open, make it close-on-exec (and rename to qid) */
	if((db1 = _dirstat(path)) == nil) {
		_syserrno();
		return -1;
	}
	fd = -1;
	for(i=0, f = _fdinfo;i < OPEN_MAX; i++, f++) {
		if((f->flags&FD_ISOPEN) && (db2=_dirfstat(i)) != nil) {
			if(db1->qid.path == db2->qid.path &&
			   db1->qid.vers == db2->qid.vers &&
			   db1->type == db2->type &&
			   db1->dev == db2->dev) {
				sprintf(newelem, "%8.8lx%8.8lx", (uintptr_t)(db2->qid.path>>32),
					(uint32_t)db2->qid.path);
				_nulldir(&nd);
				nd.name = newelem;
				if(_dirfwstat(i, &nd) < 0)
					p = (char*)path;
				else {
					p = strrchr(path, '/');
					if(p == 0)
						p = newelem; 
					else {
						memmove(newname, path, p-path);
						newname[p-path] = '/';
						strcpy(newname+(p-path)+1, newelem);
						p = newname;
					}
				}
				/* reopen remove on close */
				fd = open(p, 64|(f->oflags)); 
				if(fd < 0){
					free(db2);
					continue;
				}
				nn = seek(i, 0, 1);
				if(nn < 0)
					nn = 0;
				seek(fd, nn, 0);
				_DUP(fd, i);
				close(fd);
				free(db1);
				return 0;
			}
			free(db2);
		}
	}
	n = 0;
	if(fd == -1)
		if((n=remove(path)) < 0)
			_syserrno();
	free(db1);
	return n;
}
