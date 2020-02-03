/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "libm.h"

#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
long double frexpl(long double x, int *e)
{
	return frexp(x, e);
}
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
long double frexpl(long double x, int *e)
{
	union ldshape u = {x};
	int ee = u.i.se & 0x7fff;

	if (!ee) {
		if (x) {
			x = frexpl(x*0x1p120, e);
			*e -= 120;
		} else *e = 0;
		return x;
	} else if (ee == 0x7fff) {
		return x;
	}

	*e = ee - 0x3ffe;
	u.i.se &= 0x8000;
	u.i.se |= 0x3ffe;
	return u.f;
}
#endif
