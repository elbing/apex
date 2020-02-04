/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef	__UNISTD_H
#define	__UNISTD_H
#ifndef _POSIX_SOURCE
   This header file is not defined in pure ANSI
#endif

#define _POSIX_VERSION	200809L
#define _POSIX_ASYNC_IO -1
#define _POSIX_CHOWN_RESTRICTED 1
#define _POSIX_NO_TRUNC 1
#define _POSIX_PRIO_IO -1
#define _POSIX_SYNC_IO -1
#define _POSIX_VDISABLE -1

#ifndef NULL
#ifdef __cplusplus
#define NULL 0L
#else
#define NULL ((void *)0)
#endif
#endif

/* access */
#define	R_OK		4
#define	W_OK		2
#define	X_OK		1
#define	F_OK		0	/* test for existence */

/* lockf */
#define	F_ULOCK		0	/* unlock a previously locked region */
#define	F_LOCK		1	/* lock a region for exclusive use */
#define	F_TLOCK		2	/* test and lock a region for exclusive use */
#define	F_TEST		3	/* test a region for a previous lock */

/* lseek */
#ifndef SEEK_SET		/* also defined in stdio.h */
#define	SEEK_SET	0
#define	SEEK_CUR	1
#define	SEEK_END	2
#endif

/* sysconf argument */
#define	_SC_ARG_MAX		1	/* max chars in args to exec */
#define	_SC_CHILD_MAX		2	/* max child process per process */
#define	_SC_CLK_TCK		3	/* number of clock() units per second */
#define	_SC_NGROUPS_MAX		4	/* max supplementary groups per process */
#define	_SC_OPEN_MAX		5
#define _SC_STREAM_MAX		6
#define _SC_TZNAME_MAX		7
#define	_SC_JOB_CONTROL		8	/* posix job control */
#define	_SC_SAVED_IDS		9	/* saved suid/sgid per process */
#define	_SC_VERSION		10	/* this version */
#define _SC_LOGIN_NAME_MAX	11	/* max length of a login name */

/* pathconf argument */
#define _PC_LINK_MAX		1
#define _PC_MAX_CANON		2
#define _PC_MAX_INPUT		3
#define _PC_NAME_MAX		4
#define _PC_PATH_MAX		5
#define _PC_PIPE_BUF		6
#define _PC_CHOWN_RESTRICTED	7
#define _PC_NO_TRUNC		8
#define _PC_VDISABLE		9

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

/* standard filenos */
#define STDIN_FILENO		0
#define STDOUT_FILENO		1
#define STDERR_FILENO		2

#define __NEED_size_t
#define __NEED_ssize_t
#define __NEED_uid_t
#define __NEED_gid_t
#define __NEED_off_t
#define __NEED_pid_t
#define __NEED_intptr_t
#define __NEED_useconds_t

#include <bits/alltypes.h>

/* process primitives */
extern int _execl(const char *, const char * , ...);
#define execl _execl
extern int execv(const char *, char *const *);
extern int execle(const char *, const char *,  ...);
extern int execve(const char *, char *const *, char *const *);
extern int execlp(const char *, const char *, ...);
extern int execvp(const char *, char *const *);
extern void _exit(int);
extern unsigned int __alarm(unsigned int);
#define alarm __alarm
extern int pause(void);
extern unsigned int __sleep(unsigned int);
#define sleep(u) __sleep(u)
extern pid_t _fork(void);
#define fork _fork

/* process environment */
extern char *getlogin(void);
extern char *cuserid(char *);
extern char *ttyname(int);
extern int isatty(int);
extern long sysconf(int);
extern pid_t getpid(void);
extern pid_t getppid(void);
extern uid_t getuid(void);
extern uid_t geteuid(void);
extern gid_t getgid(void);
extern gid_t getegid(void);
extern int setuid(uid_t);
extern int setgid(gid_t);
extern int getgroups(int, gid_t *);
extern pid_t getpgrp(void);
extern int setpgid(pid_t, pid_t);
extern pid_t setsid(void);

/* files and directories */
extern int __chdir(const char *);
#define chdir __chdir
extern int link(const char *, const char *);
extern char *getcwd(char *, size_t);
extern int unlink(const char *);
extern int rmdir(const char *);
extern int access(const char *, int);
extern long pathconf(const char *, int);
extern long fpathconf(int, int);
extern int chown(const char *, uid_t, gid_t);
extern int  symlink(const char *, const char *);
extern ssize_t  readlink(const char *, char*, size_t);

/* input and output primitives */
extern int __pipe(int *);
#define pipe __pipe
extern int __dup(int);
#define dup __dup
extern int dup2(int, int);
extern	int	__close(int);
#define close __close
extern ssize_t __read(int, void *, size_t);
#define read __read
extern ssize_t __write(int, const void *, size_t);
#define write __write
extern int ftruncate(int, off_t);
extern off_t lseek(int, off_t, int);

/* device- and class-specific functions */
extern pid_t tcgetpgrp(int);
extern int tcsetpgrp(int, pid_t);

#ifdef _REENTRANT_SOURCE
extern char *getlogin_r(char *, int);
#endif

/* berkeley specific functions */
extern int	getopt(int, char* const*, const char*);
extern int	opterr;
extern int	optind;
extern int	optopt;
extern char	*optarg;

#ifdef __cplusplus
}
#endif


#endif
