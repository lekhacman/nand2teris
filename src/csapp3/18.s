	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 4
	.globl	_mytest                 ## -- Begin function mytest
	.p2align	4, 0x90
_mytest:                                ## @mytest
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
                                        ## kill: def $dx killed $dx killed $edx
                                        ## kill: def $si killed $si killed $esi
                                        ## kill: def $di killed $di killed $edi
	movw	%di, -2(%rbp)
	movw	%si, -4(%rbp)
	movw	%dx, -6(%rbp)
	movswl	-4(%rbp), %eax
	movswl	-6(%rbp), %ecx
	addl	%ecx, %eax
	movswl	-2(%rbp), %ecx
	subl	%ecx, %eax
                                        ## kill: def $ax killed $ax killed $eax
	movw	%ax, -8(%rbp)
	movswl	-6(%rbp), %ecx
	cmpl	$5, %ecx
	jge	LBB0_5
## %bb.1:
	movswl	-4(%rbp), %eax
	cmpl	$2, %eax
	jge	LBB0_3
## %bb.2:
	movswl	-2(%rbp), %eax
	movswl	-6(%rbp), %ecx
	cltd
	idivl	%ecx
                                        ## kill: def $ax killed $ax killed $eax
	movw	%ax, -8(%rbp)
	jmp	LBB0_4
LBB0_3:
	movswl	-2(%rbp), %eax
	movswl	-4(%rbp), %ecx
	cltd
	idivl	%ecx
                                        ## kill: def $ax killed $ax killed $eax
	movw	%ax, -8(%rbp)
LBB0_4:
	jmp	LBB0_8
LBB0_5:
	movswl	-6(%rbp), %eax
	cmpl	$3, %eax
	jle	LBB0_7
## %bb.6:
	movswl	-6(%rbp), %eax
	movswl	-4(%rbp), %ecx
	cltd
	idivl	%ecx
                                        ## kill: def $ax killed $ax killed $eax
	movw	%ax, -8(%rbp)
LBB0_7:
	jmp	LBB0_8
LBB0_8:
	movswl	-8(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
