/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"

static int __fflush_unlocked(FILE *f)
{
	/* If writing, flush output */
	if (f->wpos > f->wbase) {
		f->write(f, 0, 0);
		if (!f->wpos) return EOF;
	}

	/* If reading, sync position, per POSIX */
	if (f->rpos < f->rend) f->seek(f, f->rpos-f->rend, SEEK_CUR);

	/* Clear read and write modes */
	f->wpos = f->wbase = f->wend = 0;
	f->rpos = f->rend = 0;

	return 0;
}

/* stdout.c will override this if linked */
static FILE *volatile __stdout_used = 0;

int fflush(FILE *f)
{
	int r;

	if (f) {
		FLOCK(f);
		r = __fflush_unlocked(f);
		FUNLOCK(f);
		return r;
	}

	r = __stdout_used ? fflush(__stdout_used) : 0;

	for (f=*__ofl_lock(); f; f=f->next) {
		FLOCK(f);
		if (f->wpos > f->wbase) r |= __fflush_unlocked(f);
		FUNLOCK(f);
	}
	__ofl_unlock();

	return r;
}

weak_alias(fflush, fflush_unlocked);
