/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef	_STDIO_H_
#define	_STDIO_H_

/*
 * pANS stdio.h
 */

/*
 * According to X3J11, there is only one i/o buffer
 * and it must not be occupied by both input and output data.
 *	If rp<wp, we must have state==RD and
 *	if wp<rp, we must have state==WR, so that getc and putc work correctly.
 *	On open, rp, wp and buf are set to 0, so first getc or putc will call _IO_getc
 *	or _IO_putc, which will allocate the buffer.
 *	If setvbuf(., ., _IONBF, .) is called, bufl is set to 0 and
 *	buf, rp and wp are pointed at unbuf.
 *	If setvbuf(., ., _IOLBF, .) is called, _IO_putc leaves wp and rp pointed at the
 *	end of the buffer so that it can be called on each putc to check whether it's got
 *	a newline.  This nonsense is in order to avoid impacting performance of the other
 *	buffering modes more than necessary -- putting the test in putc adds many
 *	instructions that are wasted in non-_IOLBF mode:
 *	#define putc(c, f)	(_IO_ctmp=(c),\
 *				(f)->wp>=(f)->rp || (f)->flags&LINEBUF && _IO_ctmp=='\n'\
 *					?_IO_putc(_IO_ctmp, f)\
 *					:*(f)->wp++=_IO_ctmp)
 *
 */

#include <features.h>

#define __NEED_FILE
#define __NEED___isoc_va_list
#define __NEED_size_t

#if __STDC_VERSION__ < 201112L
#define __NEED_struct__IO_FILE
#endif

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
#define __NEED_ssize_t
#define __NEED_off_t
#define __NEED_va_list
#endif

#include <bits/alltypes.h>

typedef struct _IO_FILE FILE;

typedef long long fpos_t;
#ifndef NULL
#ifdef __cplusplus
#define NULL 0L
#else
#define NULL ((void *)0)
#endif
#endif
/*
 * Third arg of setvbuf
 */
#define	_IOFBF	0			/* block-buffered */
#define	_IOLBF	1			/* line-buffered */
#define	_IONBF	2			/* unbuffered */
#define	BUFSIZ	1024			/* size of setbuf buffer */
#define	EOF	(-1)			/* returned on end of file */
#define	FOPEN_MAX	1000		/* max files open */
#define	FILENAME_MAX	4096		/* silly filename length */
#define	L_tmpnam	20		/* sizeof "/tmp/abcdefghij9999 */
#define	L_cuserid	32		/* maximum size user name */
#define	L_ctermid	32		/* size of name of controlling tty */
#define	SEEK_CUR	1
#define	SEEK_END	2
#define	SEEK_SET	0
#define	TMP_MAX		64		/* very hard to set correctly */
//#define	stderr	(&_IO_stream[2])
//#define	stdin	(&_IO_stream[0])
//#define	stdout	(&_IO_stream[1])
#define	_IO_CHMASK	0377		/* mask for 8 bit characters */

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;

#define stdin  (stdin)
#define stdout (stdout)
#define stderr (stderr)

#ifdef __cplusplus
extern "C" {
#endif

extern int __remove(const char *);
#define remove __remove
extern int rename(const char *, const char *);
extern FILE *tmpfile(void);
extern char *tmpnam(char *);
extern int fclose(FILE *);
extern int fflush(FILE *);
extern FILE *fopen(const char *, const char *);
extern FILE *freopen(const char *, const char *, FILE *);
extern void setbuf(FILE *, char *);
extern int setvbuf(FILE *, char *, int, size_t);
extern int fprintf(FILE *, const char *, ...);
extern int fscanf(FILE *, const char *, ...);
extern int printf(const char *, ...);
extern int scanf(const char *, ...);
extern int sprintf(char *, const char *, ...);

/*
 * NB: C99 now *requires *snprintf to return the number of characters
 * that would have been written, had there been room.
 */
extern int snprintf(char *, size_t, const char *, ...);
extern int vsnprintf(char *, size_t, const char *, va_list);

extern int sscanf(const char *, const char *, ...);
extern int vfprintf(FILE *, const char *, va_list);
extern int vprintf(const char *, va_list);
extern int vsprintf(char *, const char *, va_list);
extern int vscanf(const char *restrict, va_list);
extern int vsscanf(const char *restrict, const char *format, va_list);
extern int vfscanf(FILE *, const char *, va_list);
extern int asprintf(char **, const char *, ...);
extern int vasprintf(char **, const char *, va_list);
extern int fgetc(FILE *);
extern char *fgets(char *, int, FILE *);
extern int fputc(int, FILE *);
extern int fputs(const char *, FILE *);
extern int getc(FILE *);
//#define	getc(f)	((f)->rp>=(f)->wp?_IO_getc(f):*(f)->rp++&_IO_CHMASK)
//extern int _IO_getc(FILE *f);
extern int getchar(void);
//#define	getchar()	getc(stdin)
extern char *gets(char *);
extern int putc(int, FILE *);
//#define	putc(c, f) ((f)->wp>=(f)->rp?_IO_putc(c, f):(*(f)->wp++=c)&_IO_CHMASK)
//extern int _IO_putc(int, FILE *);
extern int putchar(int);
//#define	putchar(c)	putc(c, stdout)
extern int puts(const char *);
extern int ungetc(int, FILE *);
extern size_t fread(void *, size_t, size_t, FILE *);
extern size_t fwrite(const void *, size_t, size_t, FILE *);
extern int fgetpos(FILE *, fpos_t *);
extern int fseek(FILE *, long, int);
extern int fseeko(FILE *, off_t, int);
extern int fsetpos(FILE *, const fpos_t *);
extern long ftell(FILE *);
extern off_t ftello(FILE *);
extern void rewind(FILE *);
extern void clearerr(FILE *);
extern int feof(FILE *);
extern int ferror(FILE *);
extern void perror(const char *);
//extern FILE _IO_stream[FOPEN_MAX];

#ifdef _POSIX_SOURCE
extern int fileno(FILE *);
extern FILE* fdopen(int, const char*);
extern char *ctermid(char *);
#endif

#ifdef _REENTRANT_SOURCE
extern char *tmpnam_r(char *);
extern char *ctermid_r(char *);
#endif

#ifdef _BSD_EXTENSION
extern FILE *popen(char *, char *);
extern int	pclose(FILE *);
#endif

#ifdef __cplusplus
}
#endif

#endif
