/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"

int fgetc(FILE *f)
{
	int c;
	if (f->lock < 0) // || !__lockfile(f))
		return getc_unlocked(f);
	c = getc_unlocked(f);
	__unlockfile(f);
	return c;
}
