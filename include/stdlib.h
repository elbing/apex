/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef _STDLIB_H
#define _STDLIB_H

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define MB_CUR_MAX 8
#define RAND_MAX (0x7fffffff)

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#ifdef __cplusplus
#ifndef NULL
#define NULL 0L
#endif
#else
#ifndef NULL
#define NULL ((void*)0)
#endif
#endif

#define __NEED_size_t
#define __NEED_wchar_t

#include <bits/alltypes.h>

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;

extern double atof(const char *);
extern int atoi(const char *);
extern long atol(const char *);
extern long long atoll(const char *);
extern double strtod(const char *, char **);
extern long strtol(const char *, char **, int);
extern unsigned long strtoul(const char *, char **, int);
extern long long int strtoll(const char *, char **, int);
extern unsigned long long int strtoull(const char *, char **, int);
extern int rand(void);
extern void srand(unsigned int seed);
extern void *calloc(size_t, size_t);
extern void free(void *);
extern void *malloc(size_t);
extern void *realloc(void *, size_t);
extern void abort(void);
extern int __atexit(void (*func)(void));
#define atexit __atexit
extern void exit(int);
extern char *getenv(const char *);
extern int system(const char *);
extern void *bsearch(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
extern int abs(int);
extern div_t div(int, int);
extern long labs(long);
extern ldiv_t ldiv(long, long);
extern int mblen(const char *, size_t);
extern int mbtowc(wchar_t *, const char *, size_t);
extern int wctomb(char *, wchar_t);
extern size_t mbstowcs(wchar_t *, const char *, size_t);
extern size_t wcstombs(char *, const wchar_t *, size_t);
extern int mkstemp(char *temp);
extern int 	putenv(char*);
extern char	*mktemp(char *);
extern int mkstemp(char *);
extern char	*sys_errlist[];
extern int		sys_nerr;
extern void	bhappy(void*);
extern int	rresvport(int*);
extern int	rcmd(char**, int, char*, char*, char*, int*);

#ifdef __cplusplus
}
#endif

#endif /* __STDLIB_H */
