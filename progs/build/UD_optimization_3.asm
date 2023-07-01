	.file	"UD_optimization.c"
	.text
	.p2align 4,,15
	.globl	_foo
	.def	_foo;	.scl	2;	.type	32;	.endef
_foo:
LFB24:
	.cfi_startproc
	movl	4(%esp), %eax
	testl	%eax, %eax
	je	L1
	movl	$777, (%eax)
L1:
	rep ret
	.cfi_endproc
LFE24:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB25:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	call	___main
	xorl	%eax, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE25:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
