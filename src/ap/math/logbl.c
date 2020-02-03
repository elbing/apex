/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <math.h>
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
long double logbl(long double x)
{
	return logb(x);
}
#else
long double logbl(long double x)
{
	if (!isfinite(x))
		return x * x;
	if (x == 0)
		return -1/(x*x);
	return ilogbl(x);
}
#endif
