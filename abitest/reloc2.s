	.text
	.align 8
.globl reloc_compile_test
	.type	reloc_compile_test, @function

reloc_compile_test:
	movq aaa@GOTPCREL(%rip), %rax
	movq aaa@GOT(%rip), %rax
	movq aaa@PLT(%rip), %rax

	.globl aaa
aaa:
