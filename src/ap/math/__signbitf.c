/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "libm.h"

// FIXME: macro in math.h
int __signbitf(float x)
{
	union {
		float f;
		uint32_t i;
	} y = { x };
	return y.i>>31;
}
