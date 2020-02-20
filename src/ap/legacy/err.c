/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <err.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

extern char *__progname;

void vwarn(const char *fmt, va_list ap)
{
	fprintf (stderr, "%s: ", __progname);
	if (fmt) {
		vfprintf(stderr, fmt, ap);
		fputs (": ", stderr);
	}
	perror(0);
}

void vwarnx(const char *fmt, va_list ap)
{
	fprintf (stderr, "%s: ", __progname);
	if (fmt) vfprintf(stderr, fmt, ap);
	putc('\n', stderr);
}

_Noreturn void verr(int status, const char *fmt, va_list ap)
{
	vwarn(fmt, ap);
	exit(status);
}

_Noreturn void verrx(int status, const char *fmt, va_list ap)
{
	vwarnx(fmt, ap);
	exit(status);
}

void warn(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vwarn(fmt, ap);
	va_end(ap);
}

void warnx(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vwarnx(fmt, ap);
	va_end(ap);
}

_Noreturn void err(int status, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	verr(status, fmt, ap);
	va_end(ap);
}

_Noreturn void errx(int status, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	verrx(status, fmt, ap);
	va_end(ap);
}
