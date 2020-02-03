/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <fenv.h>

int feholdexcept(fenv_t *envp)
{
	fegetenv(envp);
	feclearexcept(FE_ALL_EXCEPT);
	return 0;
}
