/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <math.h>
#include <stdint.h>

float copysignf(float x, float y)
{
	union {float f; uint32_t i;} ux={x}, uy={y};
	ux.i &= 0x7fffffff;
	ux.i |= uy.i & 0x80000000;
	return ux.f;
}
