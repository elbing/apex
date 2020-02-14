/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"

static size_t wrap_write(FILE *f, const unsigned char *buf, size_t len)
{
	return __stdio_write(f, buf, len);
}

int vdprintf(int fd, const char *restrict fmt, va_list ap)
{
	FILE f = {
		.fd = fd, .lbf = EOF, .write = wrap_write,
		.buf = (void *)fmt, .buf_size = 0,
		.lock = -1
	};
	return vfprintf(&f, fmt, ap);
}
