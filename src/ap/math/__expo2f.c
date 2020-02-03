/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "libm.h"

/* k is such that k*ln2 has minimal relative error and x - kln2 > log(FLT_MIN) */
static const int k = 235;
static const float kln2 = 0x1.45c778p+7f;

/* expf(x)/2 for x >= log(FLT_MAX), slightly better than 0.5f*expf(x/2)*expf(x/2) */
float __expo2f(float x)
{
	float scale;

	/* note that k is odd and scale*scale overflows */
	SET_FLOAT_WORD(scale, (uint32_t)(0x7f + k/2) << 23);
	/* exp(x - k ln2) * 2**(k-1) */
	return expf(x - kln2) * scale * scale;
}
