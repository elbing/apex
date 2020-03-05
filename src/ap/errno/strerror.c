/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <errno.h>
#include <string.h>
#include "locale_impl.h"

#define EPLAN9  1002

#define E(a,b) ((unsigned char)a),
static const unsigned char errid[] = {
#include "__strerror.h"
};

#undef E
#define E(a,b) b "\0"
static const char errmsg[] =
#include "__strerror.h"
;

extern char _plan9err[];

char *__strerror_l(int e, locale_t loc)
{
	const char *s;
	int i;
	/* mips has one error code outside of the 8-bit range due to a
	 * historical typo, so we just remap it. */
	if (EDQUOT==1133) {
		if (e==109) e=-1;
		else if (e==EDQUOT) e=109;
	}
	for (i=0; errid[i] && errid[i] != e; i++);
	for (s=errmsg; i; s++, i--) for (; *s; s++);
        return (char *)__lctrans_cur(s);
	//return (char *)LCTRANS(s, LC_MESSAGES, loc);
}

char *strerror(int e)
{

    if(e == EPLAN9) {
        return _plan9err;
    }

	return __strerror_l(e, 0/*CURRENT_LOCALE*/);
}

weak_alias(__strerror_l, strerror_l);
