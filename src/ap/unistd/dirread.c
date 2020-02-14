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
#include <sys/stat.h>
#include "sys9.h"
#include "lib.h"
#include "dir.h"

static int
statcheck(char *buf, uint32_t nbuf)
{
	char *ebuf;
	int i;

	ebuf = buf + nbuf;

	buf += STATFIXLEN - 4 * BIT16SZ;

	for(i = 0; i < 4; i++){
		if(buf + BIT16SZ > ebuf)
			return -1;
		buf += BIT16SZ + GBIT16(buf);
	}

	if(buf != ebuf)
		return -1;

	return 0;
}

static
int32_t
_dirpackage(char *buf, int32_t ts, Dir **d)
{
	char *s;
	int32_t ss, i, n, nn, m;

	if(ts == 0){
		*d = nil;
		return 0;
	}

	/*
	 * first find number of all stats, check they look like stats, & size all associated strings
	 */
	ss = 0;
	n = 0;
	for(i = 0; i < ts; i += m){
		m = BIT16SZ + GBIT16(&buf[i]);
		if(statcheck(&buf[i], m) < 0)
			break;
		ss += m;
		n++;
	}

	if(i != ts)
		return -1;

	*d = malloc(n * sizeof(Dir) + ss);
	if(*d == nil)
		return -1;

	/*
	 * then convert all buffers
	 */
	s = (char*)*d + n * sizeof(Dir);
	nn = 0;
	for(i = 0; i < ts; i += m){
		m = BIT16SZ + GBIT16((char*)&buf[i]);
		if(nn >= n || convM2D((unsigned char *)&buf[i], m, *d + nn, s) != m){
			free(*d);
			return -1;
		}
		nn++;
		s += m;
	}

	return nn;
}

int32_t
_dirread(int fd, Dir **d)
{
	char *buf;
	int32_t ts;

	buf = malloc(DIRMAX);
	if(buf == nil)
		return -1;
	ts = __sys_read(fd, buf, DIRMAX);
	if(ts >= 0)
		ts = _dirpackage(buf, ts, d);
	free(buf);
	return ts;
}

int32_t
_dirreadall(int fd, Dir **d)
{
	char *buf, *nbuf;
	int32_t n, ts;

	buf = nil;
	ts = 0;
	for(;;){
		nbuf = realloc(buf, ts+DIRMAX);
		if(nbuf == nil){
			free(buf);
			return -1;
		}
		buf = nbuf;
		n = __sys_read(fd, buf+ts, DIRMAX);
		if(n <= 0)
			break;
		ts += n;
	}
	if(ts >= 0)
		ts = _dirpackage(buf, ts, d);
	free(buf);
	return ts;
}
