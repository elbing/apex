/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"

int (getc_unlocked)(FILE *f)
{
	return getc_unlocked(f);
}

weak_alias (getc_unlocked, fgetc_unlocked);
weak_alias (getc_unlocked, _IO_getc_unlocked);
