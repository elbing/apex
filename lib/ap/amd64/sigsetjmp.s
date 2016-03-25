/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * William Jolitz.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)setjmp.s	5.1 (Berkeley) 4/23/90"
 */

/*-
 * TODO:
 *	Rename sigsetjmp to __sigsetjmp and siglongjmp to __siglongjmp,
 *	remove the other *jmp functions and define everything in terms
 *	of the renamed functions.  This requires compiler support for
 *	the renamed functions (introduced in gcc-2.5.3; previous versions
 *	only supported *jmp with 0 or 1 leading underscores).
 *
 *	Restore _all_ the registers and the signal mask atomically.  Can
 *	use sigreturn() if sigreturn() works.
 */

.globl sigsetjmp
sigsetjmp:

	movl	%esi,88(%rdi)		/* 11; savemask */
	testl	%esi,%esi
	jz	2f
	pushq	%rdi
	movq	%rdi,%rcx
	movq	$1,%rdi			/* SIG_BLOCK       */
	movq	$0,%rsi			/* (sigset_t*)set  */
	leaq	72(%rcx),%rdx		/* 9,10 (sigset_t*)oset */
	/* stack is 16-byte aligned */
	call	sigprocmask
	popq	%rdi
2:	movq	%rdi,%rcx
	movq	0(%rsp),%rdx		/* retval */
	movq	%rdx, 0(%rcx)		/* 0; retval */
	movq	%rbx, 8(%rcx)		/* 1; rbx */
	movq	%rsp,16(%rcx)		/* 2; rsp */
	movq	%rbp,24(%rcx)		/* 3; rbp */
	movq	%r12,32(%rcx)		/* 4; r12 */
	movq	%r13,40(%rcx)		/* 5; r13 */
	movq	%r14,48(%rcx)		/* 6; r14 */
	movq	%r15,56(%rcx)		/* 7; r15 */
	fnstcw	64(%rcx)		/* 8; fpu cw */
	xorq	%rax,%rax
	ret