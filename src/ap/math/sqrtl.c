/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <math.h>

long double sqrtl(long double x)
{
	/* FIXME: implement in C, this is for LDBL_MANT_DIG == 64 only */
	return sqrt(x);
}
