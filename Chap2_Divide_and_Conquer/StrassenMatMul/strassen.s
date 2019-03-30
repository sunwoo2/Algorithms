	.file	"strassen.c"
	.text
	.globl	NaiveMatMul
	.type	NaiveMatMul, @function
NaiveMatMul:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L2
.L7:
	movl	$0, -8(%rbp)
	jmp	.L3
.L6:
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-8(%rbp), %eax
	cltq
	movl	$0, (%rdx,%rax,4)
	movl	$0, -4(%rbp)
	jmp	.L4
.L5:
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-8(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %esi
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %ecx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx
	movl	-8(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	imull	%eax, %ecx
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	addl	%esi, %ecx
	movl	-8(%rbp), %eax
	cltq
	movl	%ecx, (%rdx,%rax,4)
	addl	$1, -4(%rbp)
.L4:
	cmpl	$4, -4(%rbp)
	jle	.L5
	addl	$1, -8(%rbp)
.L3:
	cmpl	$4, -8(%rbp)
	jle	.L6
	addl	$1, -12(%rbp)
.L2:
	cmpl	$4, -12(%rbp)
	jle	.L7
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	NaiveMatMul, .-NaiveMatMul
	.globl	StrassenMatMul
	.type	StrassenMatMul, @function
StrassenMatMul:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	StrassenMatMul, .-StrassenMatMul
	.section	.rodata
.LC0:
	.string	"%d "
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$352, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, -336(%rbp)
	movl	$2, -332(%rbp)
	movl	$3, -328(%rbp)
	movl	$4, -324(%rbp)
	movl	$5, -320(%rbp)
	movl	$1, -316(%rbp)
	movl	$2, -312(%rbp)
	movl	$3, -308(%rbp)
	movl	$4, -304(%rbp)
	movl	$5, -300(%rbp)
	movl	$1, -296(%rbp)
	movl	$2, -292(%rbp)
	movl	$3, -288(%rbp)
	movl	$4, -284(%rbp)
	movl	$5, -280(%rbp)
	movl	$1, -276(%rbp)
	movl	$2, -272(%rbp)
	movl	$3, -268(%rbp)
	movl	$4, -264(%rbp)
	movl	$5, -260(%rbp)
	movl	$1, -256(%rbp)
	movl	$2, -252(%rbp)
	movl	$3, -248(%rbp)
	movl	$4, -244(%rbp)
	movl	$5, -240(%rbp)
	movl	$1, -224(%rbp)
	movl	$2, -220(%rbp)
	movl	$3, -216(%rbp)
	movl	$4, -212(%rbp)
	movl	$5, -208(%rbp)
	movl	$1, -204(%rbp)
	movl	$2, -200(%rbp)
	movl	$3, -196(%rbp)
	movl	$4, -192(%rbp)
	movl	$5, -188(%rbp)
	movl	$1, -184(%rbp)
	movl	$2, -180(%rbp)
	movl	$3, -176(%rbp)
	movl	$4, -172(%rbp)
	movl	$5, -168(%rbp)
	movl	$1, -164(%rbp)
	movl	$2, -160(%rbp)
	movl	$3, -156(%rbp)
	movl	$4, -152(%rbp)
	movl	$5, -148(%rbp)
	movl	$1, -144(%rbp)
	movl	$2, -140(%rbp)
	movl	$3, -136(%rbp)
	movl	$4, -132(%rbp)
	movl	$5, -128(%rbp)
	leaq	-112(%rbp), %rdx
	leaq	-224(%rbp), %rcx
	leaq	-336(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	NaiveMatMul
	movl	$0, -344(%rbp)
	jmp	.L10
.L13:
	movl	$0, -340(%rbp)
	jmp	.L11
.L12:
	movl	-340(%rbp), %eax
	movslq	%eax, %rcx
	movl	-344(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-112(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -340(%rbp)
.L11:
	cmpl	$4, -340(%rbp)
	jle	.L12
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, -344(%rbp)
.L10:
	cmpl	$4, -344(%rbp)
	jle	.L13
	movl	$0, %eax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L15
	call	__stack_chk_fail@PLT
.L15:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
