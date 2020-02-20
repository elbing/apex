/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

/* posix */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <signal.h>

/* socket extensions */
#include <sys/uio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>

/* plan 9 */

#include "sys9.h"
#include "priv.h"

extern int64_t	_muxsid;
extern void	_killmuxsid(void);

/*
 * replace the fd with a pipe and start a process to
 * accept calls in.  this is all to make select work.
 */
static int
listenproc(Rock *r, int fd)
{
	Rock *nr;
	char *net;
	int cfd, nfd, dfd;
	int pfd[2];
	struct stat d;
	char *p;
	char listen[Ctlsize];
	char name[Ctlsize];
	void *v;

	switch(r->stype){
	case SOCK_DGRAM:
		net = "udp";
		break;
	case SOCK_STREAM:
		net = "tcp";
		break;
	default:
		net = "gok";
		break;
	}

	strcpy(listen, r->ctl);
	p = strrchr(listen, '/');
	if(p == 0)
		return -1;
	strcpy(p+1, "listen");

	if(pipe(pfd) < 0)
		return -1;

	/* replace fd with a pipe */
	nfd = dup(fd);
	dup2(pfd[0], fd);
	close(pfd[0]);
	fstat(fd, &d);
	r->inode = d.st_ino;
	r->dev = d.st_dev;

	/* start listening process */
	switch(fork()){
	case -1:
		close(pfd[1]);
		close(nfd);
		return -1;
	case 0:
		if(_muxsid == -1) {
			rfork(RFNOTEG);
			_muxsid = getpgrp();
		} else
			setpgid(getpid(), _muxsid);
		while(rendezvous(r, (void*)_muxsid) == (void*)~0)
		break;
	default:
		while((v = rendezvous(r, 0)) == (void*)~0)
			;
		_muxsid = (int64_t)v;
		atexit(_killmuxsid);
		close(pfd[1]);
		close(nfd);
		return 0;
	}

/*	for(fd = 0; fd < 30; fd++)
		if(fd != nfd && fd != pfd[1])
			close(fd); */

	for(;;){
		cfd = open(listen, O_RDWR);
		if(cfd < 0)
			break;

		dfd = _sock_data(cfd, net, r->domain, r->stype, r->protocol, &nr);
		if(dfd < 0)
			break;

		if(write(pfd[1], nr->ctl, strlen(nr->ctl)) < 0)
			break;
		if(read(pfd[1], name, sizeof(name)) <= 0)
			break;

		close(dfd);
	}
	exit(0);
	return 0;
}

int
listen(int fd, int i)
{
	Rock *r;
	int n, cfd;
	char msg[128];
	struct sockaddr_in *lip;
	struct sockaddr_un *lunix;

	r = _sock_findrock(fd, 0);
	if(r == 0){
		errno = ENOTSOCK;
		return -1;
	}

	switch(r->domain){
	case PF_INET:
		cfd = open(r->ctl, O_RDWR);
		if(cfd < 0){
			errno = EBADF;
			return -1;
		}
		lip = (struct sockaddr_in*)&r->addr;
		if(1 || lip->sin_port >= 0) {	/* sin_port is unsigned */
			if(write(cfd, "bind 0", 6) < 0) {
				errno = EGREG;
				close(cfd);
				return -1;
			}
			snprintf(msg, sizeof msg, "announce %d",
				ntohs(lip->sin_port));
		}
		else
			strcpy(msg, "announce *");
		n = write(cfd, msg, strlen(msg));
		if(n < 0){
			errno = EOPNOTSUPP;	/* Improve error reporting!!! */
			close(cfd);
			return -1;
		}
		close(cfd);

		return listenproc(r, fd);
	case PF_UNIX:
		if(r->other < 0){
			errno = EGREG;
			return -1;
		}
		lunix = (struct sockaddr_un*)&r->addr;
		if(_sock_srv(lunix->sun_path, r->other) < 0){
			_syserrno();
			r->other = -1;
			return -1;
		}
		r->other = -1;
		return 0;
	default:
		errno = EAFNOSUPPORT;
		return -1;
	}
}
