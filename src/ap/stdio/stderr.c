/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"

#undef stderr

static unsigned char buf[UNGET];
hidden FILE __stderr_FILE = { 
    .buf = buf+UNGET,
    .buf_size = 0,
    .fd = 2,
    .flags = F_PERM | F_NORD,
    .lbf = -1, 
    .write = __stdio_write,
    .seek = __stdio_seek,
    .close = __stdio_close,
    .lock = -1, 
};
FILE *const stderr = &__stderr_FILE;
FILE *volatile __stderr_used = &__stderr_FILE;

