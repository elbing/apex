/*
 * The kernel and the libc use the same constant for TAS
 */
.text
.globl __tas
__tas:
	movl    $0xdeaddead, %eax
	xchgl   %eax, 0(%rdi)            /* lock->key */
	ret

