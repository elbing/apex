/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#define __NEED_int8_t
#define __NEED_int16_t
#define __NEED_int32_t
#define __NEED_int64_t

#define __NEED_uint8_t
#define __NEED_uint16_t
#define __NEED_uint32_t
#define __NEED_uint64_t

#define __NEED_intptr_t
#define __NEED_uintptr_t

#define __NEED_intmax_t
#define __NEED_uintmax_t

#define __NEED_uid_t
#define	__NEED_gid_t

#define __NEED_sigset_t

#include <bits/alltypes.h>

/* await */
typedef
struct Waitmsg
{
	int pid;	/* of loved one */
	uint32_t time[3];	/* of loved one & descendants */
	char	*msg;
} Waitmsg;

/* stat */
#define	STATMAX	65535U	/* max length of machine-independent stat structure */
#define	DIRMAX	(sizeof(Dir)+STATMAX)	/* max length of Dir structure */
#define	ERRMAX	128	/* max length of error string */

/* open O flags */
#define	OREAD	0	/* open for read */
#define	OWRITE	1	/* write */
#define	ORDWR	2	/* read and write */
#define	OEXEC	3	/* execute, == read but check execute permission */
#define	OTRUNC	16	/* or'ed in (except for exec), truncate file first */
#define	OCEXEC	32	/* or'ed in, close on exec */
#define	ORCLOSE	64	/* or'ed in, remove on close */
#define	OEXCL	0x1000	/* or'ed in, exclusive use (create only) */

/* Noted/notify */
#define	NCONT	0	/* continue after note */
#define	NDFLT	1	/* terminate after note */
#define	NSAVE	2	/* clear note but hold state */
#define	NRSTR	3	/* restore saved state */

/* bits in Qid.type */
#define QTDIR		0x80		/* type bit for directories */
#define QTAPPEND	0x40		/* type bit for append only files */
#define QTEXCL		0x20		/* type bit for exclusive use files */
#define QTMOUNT		0x10		/* type bit for mounted channel */
#define QTFILE		0x00		/* plain file */

/* bits in Dir.mode */
#define DMDIR		0x80000000	/* mode bit for directories */
#define DMAPPEND	0x40000000	/* mode bit for append only files */
#define DMEXCL		0x20000000	/* mode bit for exclusive use files */
#define DMMOUNT		0x10000000	/* mode bit for mounted channel */
#define DMREAD		0x4		/* mode bit for read permission */
#define DMWRITE		0x2		/* mode bit for write permission */
#define DMEXEC		0x1		/* mode bit for execute permission */

/* rfork */
enum
{
	RFNAMEG		= (1<<0),
	RFENVG		= (1<<1),
	RFFDG		= (1<<2),
	RFNOTEG		= (1<<3),
	RFPROC		= (1<<4),
	RFMEM		= (1<<5),
	RFNOWAIT	= (1<<6),
	RFCNAMEG	= (1<<10),
	RFCENVG		= (1<<11),
	RFCFDG		= (1<<12),
	RFREND		= (1<<13),
	RFNOMNT		= (1<<14)
};

/* Harvey syscalls */
extern	int	await(char*, int);
extern	int	create(const char*, int, uint32_t);
extern	int	errstr(char*, uint32_t);
extern	int	exec(const char*, char* const[]);
extern	void	_exits(char *);
extern	int	fd2path(int, char*, int);
extern	int	fauth(int, char*);
extern	int	_fsession(int, char*, int);
extern	int	fwstat(int, unsigned char*, int);
extern	int	mount(int, int, const char*, int, const char*);
extern	int	noted(int);
extern	int	notify(void(*)(void*, char*));
extern	void panic(char *);
extern	int32_t	pread(int, void*, int32_t, int64_t);
extern	int32_t	pwrite(int, const void*, int32_t, int64_t);
extern	void*	rendezvous(void*, void*);
extern	int	rfork(int);
extern	void*	segattach(int, const char*, void*, uint32_t);
extern	void*	rendezvous(void*, void*);
extern	int	segdetach(void*);
extern	int	segflush(void*, uint32_t);
extern	int	segfree(void*, uint32_t);
extern	int64_t	seek(int, int64_t, int);
extern	int	semacquire(int32_t*, int);
extern	int32_t	semrelease(int32_t*, int32_t);
extern	int	tsemacquire(int32_t*, uint32_t);
extern	Waitmsg* _WAIT(void);
extern	int	wstat(const char*, unsigned char*, int);

/*
 * Following Harvey syscalls are used inside their respective ANSI/POSIX
 * functions with the same name, so they have been replaced with private
 * calls to real syscalls through new functions for avoiding collisions.
 */
extern	int64_t	__sys_alarm(uint64_t);
extern	int	__sys_chdir(const char*);
extern	int	__sys_close(int);
extern	int	__sys_dup(int, int);
extern	int	__sys_fstat(int, unsigned char*, int);
extern	int	__sys_open(const char *, int);
extern	int	__sys_pipe(int*);
extern	int32_t	__sys_read(int, void*, int32_t);
extern	int	__sys_remove(const char*);
extern	int	__sys_sleep(int32_t);
extern	int	__sys_stat(const char*, unsigned char*, int);
extern	int32_t	__sys_write(int, const void*, int32_t);


/*
 * atomic (from Harvey)
 */
int32_t	ainc(int32_t*);
int32_t	adec(int32_t*);
int	cas32(uint32_t*, uint32_t, uint32_t);
int	casp(void**, void*, void*);
int	casl(uint32_t*, uint32_t, uint32_t);

/* getenv */
extern void _envsetup(void);

/*
 * synchronization
 * NOT compatible with internal/lock.h
 * Used at stdio/__lockfile.c
 */
typedef struct Lockh {
	int32_t	key;
	int32_t	sem;
} Lockh;

/* Ureg */
typedef struct Ureg Ureg;

/* fdinfo
 * be sure to change _fdinfo[] init
 * in _fdinfo if you change this
 */

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

extern Fdinfo	_fdinfo[];

#define FD_ISOPEN	0x2
#define FD_BUFFERED	0x4
#define FD_BUFFEREDX	0x8
#define FD_ISTTY	0x20

/* Unix signals to noted/notify */
#define MAXSIG SIGUSR2
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
