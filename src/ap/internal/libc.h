/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#ifndef LIBC_H
#define LIBC_H

#include <stdio.h>

struct __locale_map;

struct __locale_struct {
	const struct __locale_map *volatile cat[6];
};

struct tls_module {
	struct tls_module *next;
	void *image;
	size_t len, size, align, offset;
};

struct __libc {
	int can_do_threads;
	int threaded;
	int secure;
	volatile int threads_minus_1;
	size_t *auxv;
	struct tls_module *tls_head;
	size_t tls_size, tls_align, tls_cnt;
	size_t page_size;
	struct __locale_struct global_locale;
};

#ifndef PAGE_SIZE
#define PAGE_SIZE libc.page_size
#endif

#ifdef __PIC__
#define ATTR_LIBC_VISIBILITY __attribute__((visibility("hidden")))
#else
#define ATTR_LIBC_VISIBILITY
#endif

extern struct __libc __libc ATTR_LIBC_VISIBILITY;
#define libc __libc

extern size_t __hwcap ATTR_LIBC_VISIBILITY;
extern size_t __sysinfo ATTR_LIBC_VISIBILITY;
extern char *__progname, *__progname_full;

/* Designed to avoid any overhead in non-threaded processes */
void __lock(volatile int *) ATTR_LIBC_VISIBILITY;
void __unlock(volatile int *) ATTR_LIBC_VISIBILITY;
int __lockfile(FILE *) ATTR_LIBC_VISIBILITY;
void __unlockfile(FILE *) ATTR_LIBC_VISIBILITY;
#define LOCK(x) __lock(x)
#define UNLOCK(x) __unlock(x)

void __synccall(void (*)(void *), void *);
int __setxid(int, int, int, int);

extern char **__environ;

#undef LFS64_2
#define LFS64_2(x, y) weak_alias(x, y)

#undef LFS64
#define LFS64(x) LFS64_2(x, x##64)

#endif
