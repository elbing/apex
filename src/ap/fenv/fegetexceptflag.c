/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <fenv.h>

int fegetexceptflag(fexcept_t *fp, int mask)
{
	*fp = fetestexcept(mask);
	return 0;
}
