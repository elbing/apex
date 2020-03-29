/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2020 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#define _GNU_SOURCE
#include <unistd.h>
#include <sys/utsname.h>
#include <string.h>
#include <errno.h>

int getdomainname(char *name, size_t len)
{
	struct utsname temp;
	uname(&temp);
	if (!len || strlen(temp.domainname) >= len) {
		errno = EINVAL;
		return -1;
	}
	strcpy(name, temp.domainname);
	return 0;
}
