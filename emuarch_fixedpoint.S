	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_mul_fp                 ## -- Begin function mul_fp
	.p2align	4, 0x90
_mul_fp:                                ## @mul_fp
	.cfi_startproc
	movslq	%edi, %rcx
	movslq	%esi, %rax
	imulq	%rcx, %rax
	shrq	$16, %rax
	retq
	.cfi_endproc


                                        ## -- End function
	.globl	_div_fp                 ## -- Begin function div_fp
	.p2align	4, 0x90
_div_fp:                                ## @div_fp
	.cfi_startproc
	movslq	%edi, %rax
	movslq	%esi, %rcx
	shlq	$16, %rax
	cqto
	idivq	%rcx
                                        ## kill: %EAX<def> %EAX<kill> %RAX<kill>
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
