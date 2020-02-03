/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <math.h>

/* uses LONG_MAX > 2^24, see comments in lrint.c */

long lrintf(float x)
{
	return rintf(x);
}
