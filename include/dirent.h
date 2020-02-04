/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef	__DIRENT_H
#define	__DIRENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#define __NEED_ino_t
#define __NEED_off_t
#if defined(_BSD_SOURCE) || defined(_GNU_SOURCE)
#define __NEED_size_t
#endif

#include <bits/alltypes.h>

/*
 * this must be a power of 2 and a multiple of all the ones in the system
 */
#define MAXNAMLEN 255

typedef size_t d_ino;

struct	dirent {
	ino_t d_ino;
	off_t d_off;
	unsigned short d_reclen;
	unsigned char d_type;
	char	d_name[MAXNAMLEN + 1];
};

typedef struct _dirdesc {
	int	dd_fd;		/* file descriptor */
	long	dd_loc;		/* buf offset of entry from last readdir() */
	long	dd_size;	/* amount of valid data in buffer */
	char	*dd_buf;	/* directory data buffer */
	void *dirs;
	int	dirsize;
	int	dirloc;
	volatile int lock[2];
} DIR;

/*
 * functions defined on directories
 */
DIR		*opendir(const char *);
struct dirent	*readdir(DIR *);
int            readdir_r(DIR *__restrict, struct dirent *__restrict, struct dirent **__restrict);
void		rewinddir(DIR *);
int		closedir(DIR *);

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define DT_UNKNOWN 0
#define DT_FIFO 1
#define DT_CHR 2
#define DT_DIR 4
#define DT_BLK 6
#define DT_REG 8
#define DT_LNK 10
#define DT_SOCK 12
#define DT_WHT 14
#define IFTODT(x) ((x)>>12 & 017)
#define DTTOIF(x) ((x)<<12)
int getdents(int, struct dirent *, size_t);
#endif

#ifdef __cplusplus
}
#endif

#endif
