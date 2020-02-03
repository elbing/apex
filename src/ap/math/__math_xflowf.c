/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "libm.h"

float __math_xflowf(uint32_t sign, float y)
{
	return eval_as_float(fp_barrierf(sign ? -y : y) * y);
}