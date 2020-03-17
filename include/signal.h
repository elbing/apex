/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#ifndef __SIGNAL_H
#define __SIGNAL_H

#include <features.h>

#ifdef _GNU_SOURCE
#define __ucontext ucontext
#endif

#define __NEED_size_t
#define __NEED_pid_t
#define __NEED_uid_t
#define __NEED_struct_timespec
#define __NEED_pthread_t
#define __NEED_pthread_attr_t
#define __NEED_time_t
#define __NEED_clock_t
#define __NEED_sigset_t

#include <bits/alltypes.h>

typedef int sig_atomic_t;

/*
 * We don't give arg types for signal handlers, in spite of ANSI requirement
 * that it be 'int' (the signal number), because some programs need an
 * additional context argument.  So the real type of signal handlers is
 *      void handler(int sig, char *, struct Ureg *)
 * where the char * is the Plan 9 message and Ureg is defined in <ureg.h>
 */
#define SIG_DFL ((void (*)())0)
#define SIG_ERR ((void (*)())-1)
#define SIG_IGN ((void (*)())1)

#define	SIGHUP	1	/* hangup */
#define	SIGINT	2	/* interrupt */
#define	SIGQUIT	3	/* quit */
#define	SIGILL	4	/* illegal instruction (not reset when caught)*/
#define SIGABRT 5	/* used by abort */
#define	SIGFPE	6	/* floating point exception */
#define	SIGKILL	7	/* kill (cannot be caught or ignored) */
#define	SIGSEGV	8	/* segmentation violation */
#define	SIGPIPE	9	/* write on a pipe with no one to read it */
#define	SIGALRM	10	/* alarm clock */
#define	SIGTERM	11	/* software termination signal from kill */
#define	SIGUSR1	12	/* user defined signal 1 */
#define	SIGUSR2	13	/* user defined signal 2 */
#define	SIGBUS	14	/* bus error */

/* The following symbols must be defined, but the signals needn't be supported */
#define SIGCHLD	15	/* child process terminated or stopped */
#define SIGCONT 16	/* continue if stopped */
#define SIGSTOP 17	/* stop */
#define SIGTSTP	18	/* interactive stop */
#define SIGTTIN	19	/* read from ctl tty by member of background */
#define SIGTTOU	20	/* write to ctl tty by member of background */

#ifdef _BSD_EXTENSION
#define NSIG 21
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern void (*signal(int, void (*)()))();
extern int raise(int);

#ifdef __cplusplus
}
#endif

#ifdef _POSIX_SOURCE

struct sigaction {
	void		(*sa_handler)();
	sigset_t	sa_mask;
	int		sa_flags;
};
/* values for sa_flags amd64 ¡¡this has to be placed at $ARCH/bits!!!
   After reworking signals in APEX */
#define SA_NOCLDSTOP	1
#define SA_RESETHAND  0x80000000

/* first argument to sigprocmask */
#define SIG_BLOCK	1
#define SIG_UNBLOCK	2
#define SIG_SETMASK	3

#ifdef __cplusplus
extern "C" {
#endif

extern int kill(pid_t, int);
extern int sigemptyset(sigset_t *);
extern int sigfillset(sigset_t *);
extern int sigaddset(sigset_t *, int);
extern int sigdelset(sigset_t *, int);
extern int sigismember(const sigset_t *, int);
extern int sigaction(int, const struct sigaction *, struct sigaction *);
extern int sigprocmask(int, const sigset_t *, sigset_t *);
extern int sigpending(sigset_t *);
extern int sigsuspend(const sigset_t *);

#ifdef __cplusplus
}
#endif

#endif /* _POSIX_SOURCE */

#endif /* __SIGNAL_H */
