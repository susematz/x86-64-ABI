#ifndef INCLUDED_ARGS_H
#define INCLUDED_ARGS_H

/* This defines the calling sequence for integers. Floats will come...  */
#define I0 rdi
#define I1 rsi
#define I2 rdx
#define I3 rcx
#define I4 r8
#define I5 r9


/* Clear all registers.  */
#define clear_hardware_registers \
    asm __volatile__ ("xor %%rax, %%rax\n\t" \
                      "xor %%rbx, %%rbx\n\t" \
                      "xor %%rcx, %%rcx\n\t" \
                      "xor %%rdx, %%rdx\n\t" \
                      "xor %%rsi, %%rsi\n\t" \
                      "xor %%rdi, %%rdi\n\t" \
                      "xor %%r8, %%r8\n\t" \
                      "xor %%r9, %%r9\n\t" \
                      "xor %%r10, %%r10\n\t" \
                      "xor %%r11, %%r11\n\t" \
                      "xor %%r12, %%r12\n\t" \
                      "xor %%r13, %%r13\n\t" \
                      "xor %%r14, %%r14\n\t" \
                      "xor %%r15, %%r15\n\t" \
		      ::: "rax", "rbx", "rcx", "rdx", "rsi", "rdi", "r8", \
		      "r9", "r10", "r11", "r12", "r13", "r14", "r15");


struct Registers {
    long rax, rbx, rcx, rdx, rsi, rdi, r8, r9, r10, r11, r12, r13, r14, r15;
};
extern struct Registers regs; /* Implemented in scalarargs.c  */


/* This is not nice, but __asm__ statements doesn't like >= 10 args.  */
#define check_register_contents \
    __asm__ __volatile__("cmpq %%rax, regs(%%rip)\n\t" \
			 "jne my_abort\n\t" \
			 "cmpq %%rbx, regs+8(%%rip)\n\t" \
			 "jne my_abort\n\t" \
			 "cmpq %%rcx, regs+16(%%rip)\n\t" \
			 "jne my_abort\n\t" \
			 "cmpq %%rdx, regs+24(%%rip)\n\t" \
			 "jne my_abort\n\t" \
			 "cmpq %%rsi, regs+32(%%rip)\n\t" \
			 "jne my_abort\n\t" \
			 "cmpq %%rdi, regs+40(%%rip)\n\t" \
			 "jne my_abort\n\t" \
			 "cmpq %%r8, regs+48(%%rip)\n\t" \
			 "jne my_abort\n\t" \
			 "cmpq %%r9, regs+56(%%rip)\n\t" \
			 "jne my_abort\n\t" \
			 "cmpq %%r10, regs+64(%%rip)\n\t" \
			 "jne my_abort\n\t" \
			 "cmpq %%r11, regs+72(%%rip)\n\t" \
			 "jne my_abort\n\t" \
			 "cmpq %%r12, regs+80(%%rip)\n\t" \
			 "jne my_abort\n\t" \
			 "cmpq %%r13, regs+88(%%rip)\n\t" \
			 "jne my_abort\n\t" \
			 "cmpq %%r14, regs+96(%%rip)\n\t" \
			 "jne my_abort\n\t" \
			 "cmpq %%r15, regs+104(%%rip)\n\t" \
			 "jne my_abort\n" ::: "memory");

/* Clear register struct.  */
#define clear_struct_registers \
    regs.rax = regs.rbx = regs.rcx = regs.rdx = regs.rsi = regs.rdi = regs.r8 \
	= regs.r9 = regs.r10 = regs.r11 = regs.r12 = regs.r13 = regs.r14 \
	= regs.r15 = 0;

/* Clear both hardware and register structs.  */
#define clear_registers clear_struct_registers clear_hardware_registers


#endif /* INCLUDED_ARGS_H  */
