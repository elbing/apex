/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"
#include <limits.h>
#include <string.h>

char *gets(char *s)
{
	size_t i=0;
	int c;
	FLOCK(stdin);
	while ((c=getc_unlocked(stdin)) != EOF && c != '\n') s[i++] = c;
	s[i] = 0;
	if (c != '\n' && (!feof(stdin) || !i)) s = 0;
	FUNLOCK(stdin);
	return s;
}
