/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "sys9.h"
#include "lib.h"

int _finishing = 0;
int _sessleader = 0;

static char exitstatus[ERRMAX];

void
_exit(int status)
{
	_finish(status, 0);
}

void
_finish(int status, char *term)
{
	char *cp;

	if(_finishing)
		_exits(exitstatus);
	_finishing = 1;
	if(status){
		cp = _ultoa(exitstatus, status & 0xFF);
		*cp = 0;
	}else if(term){
		strncpy(exitstatus, term, ERRMAX);
		exitstatus[ERRMAX-1] = '\0';
	}
	if(_sessleader)
		kill(0, SIGTERM);
	_exits(exitstatus);
}

/* emulate: return p+sprintf(p, "%uld", v) */
#define IDIGIT 15
char *
_ultoa(char *p, uint32_t v)
{
	char s[IDIGIT];
	int n, i;

	s[IDIGIT-1] = 0;
	for(i = IDIGIT-2; i; i--){
		n = v % 10;
		s[i] = n + '0';
		v = v / 10;
		if(v == 0)
			break;
	}
	strcpy(p, s+i);
	return p + (IDIGIT-1-i);
}
