/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"

int (putc_unlocked)(int c, FILE *f)
{
	return putc_unlocked(c, f);
}

weak_alias(putc_unlocked, fputc_unlocked);
