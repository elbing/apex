/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <stdio.h>

ssize_t getline(char **restrict s, size_t *restrict n, FILE *restrict f)
{
	return getdelim(s, n, '\n', f);
}
