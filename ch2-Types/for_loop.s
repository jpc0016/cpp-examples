	.text
	.file	"for_loop.cpp"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	subq	$168, %rsp
	.cfi_offset %rbx, -24
	movl	$0, -76(%rbp)
	movq	$0, -40(%rbp)
	leaq	-128(%rbp), %rdi
	xorl	%esi, %esi
	movl	$40, %edx
	callq	memset
	movq	$10, -128(%rbp)
	movq	$50, -120(%rbp)
	movq	$20, -112(%rbp)
	movq	$40, -104(%rbp)
	movq	$0, -16(%rbp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	cmpq	$5, -16(%rbp)
	jae	.LBB0_6
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	movq	-16(%rbp), %rax
	movq	-128(%rbp,%rax,8), %rax
	cmpq	-40(%rbp), %rax
	jbe	.LBB0_4
# %bb.3:                                #   in Loop: Header=BB0_1 Depth=1
	movq	-16(%rbp), %rax
	movq	-128(%rbp,%rax,8), %rax
	movq	%rax, -40(%rbp)
.LBB0_4:                                #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_5
.LBB0_5:                                #   in Loop: Header=BB0_1 Depth=1
	movq	-16(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	jmp	.LBB0_1
.LBB0_6:
	movq	-40(%rbp), %rsi
	movabsq	$.L.str, %rdi
	movb	$0, %al
	callq	printf
	movq	$0, -32(%rbp)
	leaq	-176(%rbp), %rbx
	movq	%rbx, %rdi
	xorl	%esi, %esi
	movl	$40, %edx
	callq	memset
	movq	$10, -176(%rbp)
	movq	$20, -168(%rbp)
	movq	$60, -160(%rbp)
	movq	$100, -152(%rbp)
	movq	%rbx, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-56(%rbp), %rax
	addq	$40, %rax
	movq	%rax, -72(%rbp)
.LBB0_7:                                # =>This Inner Loop Header: Depth=1
	movq	-24(%rbp), %rax
	cmpq	-72(%rbp), %rax
	je	.LBB0_12
# %bb.8:                                #   in Loop: Header=BB0_7 Depth=1
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jbe	.LBB0_10
# %bb.9:                                #   in Loop: Header=BB0_7 Depth=1
	movq	-48(%rbp), %rax
	movq	%rax, -32(%rbp)
.LBB0_10:                               #   in Loop: Header=BB0_7 Depth=1
	jmp	.LBB0_11
.LBB0_11:                               #   in Loop: Header=BB0_7 Depth=1
	movq	-24(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -24(%rbp)
	jmp	.LBB0_7
.LBB0_12:
	movq	-32(%rbp), %rsi
	movabsq	$.L.str.1, %rdi
	movb	$0, %al
	callq	printf
	movq	$5, -64(%rbp)
	movq	-64(%rbp), %rsi
	movabsq	$.L.str.2, %rdi
	movb	$0, %al
	callq	printf
	xorl	%eax, %eax
	addq	$168, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"The maximum value of values[] is %lu\n"
	.size	.L.str, 38

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"\nThe second maximum value is %lu\n"
	.size	.L.str.1, 34

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"%zd\n"
	.size	.L.str.2, 5


	.ident	"clang version 8.0.0-3 (tags/RELEASE_800/final)"
	.section	".note.GNU-stack","",@progbits
