	.file	"point.cpp"
	.text
	.align 2
	.globl	__ZN5Point5shiftEdd
	.def	__ZN5Point5shiftEdd;	.scl	2;	.type	32;	.endef
__ZN5Point5shiftEdd:
LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-4(%ebp), %eax
	fldl	(%eax)
	faddl	-16(%ebp)
	movl	-4(%ebp), %eax
	fstpl	(%eax)
	movl	-4(%ebp), %eax
	fldl	8(%eax)
	faddl	-24(%ebp)
	movl	-4(%ebp), %eax
	fstpl	8(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$16
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
