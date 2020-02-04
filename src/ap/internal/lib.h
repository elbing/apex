/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <sys/limits.h>
#include <ureg.h>

typedef struct Ureg Ureg;

/* mux buf for selecting (see _buf.c) */
enum {
	READMAX = 8192,			/* read at most this much with _READ */
	PERFDMAX = 2*READMAX,		/* stop _READing an fd when it has this much */
	INITBUFS = 4,			/* allow enough room for this many PERFDMAX */
};

typedef struct Muxbuf {
	int n;				/* # unprocessed chars in buf */
	unsigned char*	putnext;	/* place for copy process to put next data */
	unsigned char*	getnext;	/* place for parent process to get next data */
	char		fd;		/* fd for which this is a buffer */
	unsigned char	eof;		/* true if eof after current data exhausted */
	unsigned char	roomwait;	/* true if copy process is waiting for room */
	unsigned char	datawait;	/* true if parent process is waiting for data */
	int		copypid;	/* pid of copyproc */
	unsigned char	data[PERFDMAX];
} Muxbuf;

/* be sure to change _fdinfo[] init in _fdinfo if you change this */
typedef struct Fdinfo{
	uint32_t	flags;
	uint32_t	oflags;
	uid_t	uid;
	gid_t	gid;
	char		*name;
	/*
	 * the following is used if flags&FD_BUFFERED
	 */
	Muxbuf	*buf;	/* holds buffered data and state */
} Fdinfo;

/* #define FD_CLOEXEC 1 is in fcntl.h */

#define FD_ISOPEN	0x2
#define FD_BUFFERED	0x4
#define FD_BUFFEREDX	0x8
#define FD_ISTTY	0x20

#define MAXSIG SIGUSR2

/* Noted() from libc.h */
#define	NCONT	0	/* continue after note */
#define	NDFLT	1	/* terminate after note */
#define	NSAVE	2	/* clear note but hold state */
#define	NRSTR	3	/* restore saved state */

extern Fdinfo	_fdinfo[];

extern int	_finishing;
extern int	_sessleader;
extern void	(*_sighdlr[])(int, char*, Ureg*);
extern char	*_sigstring(int);
extern int	_stringsig(char *);
extern sigset_t	_psigblocked; // Now sigset_t is an struct so we have to keep old Plan 9 ANSI adapter
extern int	_startbuf(int);
extern int	_selbuf(int);
extern void	_closebuf(int);
extern int _readbuf(int, void*, int, int);
extern void	_detachbuf(void);
extern void	_finish(int, char *);
extern char	*_ultoa(char *, uint32_t);
extern void	_notehandler(void *, char *);
extern void	_notetramp(int, void (*)(int, char*, Ureg*), Ureg*);
extern void	_syserrno(void);
extern int	_getpw(int *, char **, char **);
extern int _isatty(int);
extern void _fdinit(char*, char*);


void checkbug(char *, int);
