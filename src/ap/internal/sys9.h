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

typedef
struct Waitmsg
{
	int pid;	/* of loved one */
	uint32_t time[3];	/* of loved one & descendants */
	char	*msg;
} Waitmsg;

#define	STATMAX	65535U	/* max length of machine-independent stat structure */
#define	DIRMAX	(sizeof(Dir)+STATMAX)	/* max length of Dir structure */
#define	ERRMAX	128	/* max length of error string */

#define	MORDER	0x0003	/* mask for bits defining order of mounting */
#define	MREPL	0x0000	/* mount replaces object */
#define	MBEFORE	0x0001	/* mount goes before others in union directory */
#define	MAFTER	0x0002	/* mount goes after others in union directory */
#define	MCREATE	0x0004	/* permit creation in mounted directory */
#define	MCACHE	0x0010	/* cache some data */
#define	MMASK	0x0007	/* all bits on */

#define	OREAD	0	/* open for read */
#define	OWRITE	1	/* write */
#define	ORDWR	2	/* read and write */
#define	OEXEC	3	/* execute, == read but check execute permission */
#define	OTRUNC	16	/* or'ed in (except for exec), truncate file first */
#define	OCEXEC	32	/* or'ed in, close on exec */
#define	ORCLOSE	64	/* or'ed in, remove on close */
#define	OEXCL	0x1000	/* or'ed in, exclusive use (create only) */

#define	AEXIST	0	/* accessible: exists */
#define	AEXEC	1	/* execute access */
#define	AWRITE	2	/* write access */
#define	AREAD	4	/* read access */

/* Segattch */
#define	SG_RONLY	0040	/* read only */
#define	SG_CEXEC	0100	/* detach on exec */

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

/* Libc needed syscalls */
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
 * Following libc syscalls are used inside their respective ANSI/POSIX
 * functions with the same name, so they have been replaced with private
 * calls to real syscalls through new functions to avoid colliding.
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
 * atomic
 */
int32_t	ainc(int32_t*);
int32_t	adec(int32_t*);
int	cas32(uint32_t*, uint32_t, uint32_t);
int	casp(void**, void*, void*);
int	casl(uint32_t*, uint32_t, uint32_t);

/* getenv */
extern void _envsetup(void);
