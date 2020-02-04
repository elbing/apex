/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#ifndef	_CTYPE_H
#define	_CTYPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#ifndef _OLD_APE
int   isalnum(int);
int   isalpha(int);
int   isblank(int);
int   iscntrl(int);
int   isdigit(int);
int   isgraph(int);
int   islower(int);
int   isprint(int);
int   ispunct(int);
int   isspace(int);
int   isupper(int);
int   isxdigit(int);
int   tolower(int);
int   toupper(int);
#endif // _OLD_APE

#ifndef __cplusplus
static __inline int __isspace(int _c)
{
	return _c == ' ' || (unsigned)_c-'\t' < 5;
}

#ifndef _OLD_APE
#define isalpha(a) (0 ? isalpha(a) : (((unsigned)(a)|32)-'a') < 26)
#define isdigit(a) (0 ? isdigit(a) : ((unsigned)(a)-'0') < 10)
#define islower(a) (0 ? islower(a) : ((unsigned)(a)-'a') < 26)
#define isupper(a) (0 ? isupper(a) : ((unsigned)(a)-'A') < 26)
#define isprint(a) (0 ? isprint(a) : ((unsigned)(a)-0x20) < 0x5f)
#define isgraph(a) (0 ? isgraph(a) : ((unsigned)(a)-0x21) < 0x5e)
#define isspace(a) __isspace(a)
#endif // _OLD_APE

#endif

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)

#define __NEED_locale_t
#include <bits/alltypes.h>

int   isalnum_l(int, locale_t);
int   isalpha_l(int, locale_t);
int   isblank_l(int, locale_t);
int   iscntrl_l(int, locale_t);
int   isdigit_l(int, locale_t);
int   isgraph_l(int, locale_t);
int   islower_l(int, locale_t);
int   isprint_l(int, locale_t);
int   ispunct_l(int, locale_t);
int   isspace_l(int, locale_t);
int   isupper_l(int, locale_t);
int   isxdigit_l(int, locale_t);
int   tolower_l(int, locale_t);
int   toupper_l(int, locale_t);

int   isascii(int);
int   toascii(int);
#define _tolower(a) ((a)|0x20)
#define _toupper(a) ((a)&0x5f)
#define isascii(a) (0 ? isascii(a) : (unsigned)(a) < 128)

#endif

// TODO, migrate to standard musl version
#ifdef _OLD_APE
enum
{
  _ISupper = 01,    /* UPPERCASE.  */
  _ISlower = 02,    /* lowercase.  */
  _ISdigit = 04,    /* Numeric.  */
  _ISspace = 010,   /* Whitespace.  */
  _ISpunct = 020,   /* Punctuation.  */
  _IScntrl = 040,   /* Control character.  */
  _ISblank = 0100,  /* Blank (usually SPC and TAB).  */
  _ISxdigit = 0200, /* Hexadecimal numeric.  */
};

extern unsigned char _ctype[];
#define isalnum(c)  (_ctype[(unsigned char)(c)]&(_ISupper|_ISlower|_ISdigit))
#define isalpha(c)  (_ctype[(unsigned char)(c)]&(_ISupper|_ISlower))
#define iscntrl(c)  (_ctype[(unsigned char)(c)]&_IScntrl)
#define isdigit(c)  (_ctype[(unsigned char)(c)]&_ISdigit)
#define isgraph(c)  (_ctype[(unsigned char)(c)]&(_ISpunct|_ISupper|_ISlower|_ISdigit))
#define islower(c)  (_ctype[(unsigned char)(c)]&_ISlower)
#define isprint(c)  (_ctype[(unsigned char)(c)]&(_ISpunct|_ISupper|_ISlower|_ISdigit|_ISblank))
#define ispunct(c)  (_ctype[(unsigned char)(c)]&_ISpunct)
#define isspace(c)  (_ctype[(unsigned char)(c)]&_ISspace)
#define isupper(c)  (_ctype[(unsigned char)(c)]&_ISupper)
#define isxdigit(c) (_ctype[(unsigned char)(c)]&_ISxdigit)
#endif // _OLD_APE

#ifdef __cplusplus
}
#endif

#endif
