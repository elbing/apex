/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <stdlib.h>
#include "stdio_impl.h"
#include "libc.h"

//static void dummy(FILE *f) { }

int fclose(FILE *f)
{
	int r;
	int perm;

	FLOCK(f);

	//__unlist_locked_file(f);

	if (!(perm = f->flags & F_PERM)) {
		FILE **head = __ofl_lock();
		if (f->prev) f->prev->next = f->next;
		if (f->next) f->next->prev = f->prev;
		if (*head == f) *head = f->next;
		__ofl_unlock();
	}

	r = fflush(f);
	r |= f->close(f);

	if (f->getln_buf) free(f->getln_buf);
	if (!perm) free(f);
	else FUNLOCK(f);

	return r;
}
