/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#define _GNU_SOURCE
#include <stdio.h>

int getw(FILE *f)
{
	int x;
	return fread(&x, sizeof x, 1, f) ? x : EOF;
}
