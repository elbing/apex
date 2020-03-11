/*
 * Copyright (c) 2005-2014 Rich Felker, et al.
 * Copyright (c) 2015-2016 HarveyOS et al.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE.mit file.
 */

#include "stdio_impl.h"

#undef stdout

static unsigned char buf[BUFSIZ+UNGET];
hidden FILE __stdout_FILE = { 
    .buf = buf+UNGET,
    .buf_size = sizeof buf-UNGET,
    .fd = 1,
    .flags = F_PERM | F_NORD,
    .lbf = '\n',
    .write = __stdout_write,
    .seek = __stdio_seek,
    .close = __stdio_close,
    .lock = -1, 
};
FILE *const stdout = &__stdout_FILE;
FILE *volatile __stdout_used = &__stdout_FILE;
