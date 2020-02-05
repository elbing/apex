/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2018 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include <stdlib.h>
#include "libc.h"
#include "sys9.h"

static void dummy(void) {}
weak_alias(dummy, _init);
__attribute__((__weak__, __visibility__("hidden")))
extern void (*const __init_array_start)(void), (*const __init_array_end)(void);

static void libc_start_init(void)
{
	_init();
	uintptr_t a = (uintptr_t)&__init_array_start;
	for (; a<(uintptr_t)&__init_array_end; a+=sizeof(void(*)()))
		(*(void (**)())a)();
}

typedef int lsm2_fn(int (*)(int,char **,char **), int, char **);
static lsm2_fn libc_start_main_stage2;

int __libc_start_main(int (*main)(int,char **,char **), int argc, char **argv)
{

    /* Barrier against hoisting application code or anything using ssp
     * or thread pointer prior to its initialization above. */
    lsm2_fn *stage2 = libc_start_main_stage2;
    __asm__ ( "" : "+r"(stage2) : : "memory" );
    return stage2(main, argc, argv);
}

weak_alias(libc_start_init, __libc_start_init);

int libc_start_main_stage2(int (*main)(int,char **,char **), int argc, char **argv)
{
    _envsetup();
    __libc_start_init();

	/* Pass control to the application */
	exit(main(argc, argv, __environ));
	return 0;
}
