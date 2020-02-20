/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <sys/stat.h>
#include <errno.h>
#include "sys9.h"

#include "dir.h"

/* fi is non-null if there is an fd associated with s */
void
dirtostat(struct stat *s, Dir *d, Fdinfo *fi)
{
	int num;
	char *nam;

	s->st_dev = (d->type<<8)|(d->dev&0xFF);
	s->st_ino = d->qid.path;
	s->st_mode = d->mode&0777;
	if(fi && (fi->flags&FD_ISTTY))
		s->st_mode |= S_IFCHR;
	else if(d->mode & 0x80000000)
		s->st_mode |= S_IFDIR;
	else if(d->type == '|' || d->type == 's')
		s->st_mode |= S_IFIFO;
	else if(d->type != 'M')
		s->st_mode |= S_IFCHR;
	else
		s->st_mode |= S_IFREG;
	s->st_nlink = 1;
	s->st_uid = 1;
	s->st_gid = 1;
	if(fi && (fi->flags&FD_BUFFERED))
		s->st_size = fi->buf->n;
	else
		s->st_size = d->length;
	s->st_atime = d->atime;
	s->st_mtime = d->mtime;
	s->st_ctime = d->mtime;
	if(fi && fi->uid != -2){
		s->st_uid = fi->uid;
		s->st_gid = fi->gid;
	} else {
		nam = d->uid;
		if(_getpw(&num, &nam, 0))
			s->st_uid = num;
		nam = d->gid;
		if(_getpw(&num, &nam, 0))
			s->st_gid = num;
		if(fi){
			fi->uid = s->st_uid;
			fi->gid = s->st_gid;
		}
	}
}
