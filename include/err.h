/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#ifndef _ERR_H
#define _ERR_H

#include <features.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

void warn(const char *, ...);
void vwarn(const char *, va_list);
void warnx(const char *, ...);
void vwarnx(const char *, va_list);

_Noreturn void err(int, const char *, ...);
_Noreturn void verr(int, const char *, va_list);
_Noreturn void errx(int, const char *, ...);
_Noreturn void verrx(int, const char *, va_list);

#ifdef __cplusplus
}
#endif

#endif
