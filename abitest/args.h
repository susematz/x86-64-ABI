#ifndef INCLUDED_ARGS_H
#define INCLUDED_ARGS_H

/* This defines the calling sequences for integers and floats.  */
#define I0 rdi
#define I1 rsi
#define I2 rdx
#define I3 rcx
#define I4 r8
#define I5 r9
#define F0 xmm0
#define F1 xmm1
#define F2 xmm2
#define F3 xmm3
#define F4 xmm4
#define F5 xmm5
#define F6 xmm6
#define F7 xmm7
#define F8 xmm8
#define F9 xmm9
#define F10 xmm10
#define F11 xmm11
#define F12 xmm12
#define F13 xmm13
#define F14 xmm14
#define F15 xmm15

/* Clear all integer registers.  */
#define clear_int_hardware_registers \
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

/* This is the list of registers available for passing arguments. Not all of
   these are used or even really available.  */
struct IntegerRegisters
{
  long rax, rbx, rcx, rdx, rsi, rdi, r8, r9, r10, r11, r12, r13, r14, r15;
};
struct FloatRegisters
{
  double mm0, mm1, mm2, mm3, mm4, mm5, mm6, mm7, st0, st1, st2, st3, st4, st5,
    st6, st7, xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xmm8, xmm9,
    xmm10, xmm11, xmm12, xmm13, xmm14, xmm15;
};

/* Implemented in scalarargs.c  */
extern struct IntegerRegisters iregs;
extern struct FloatRegisters fregs;

/* This is not nice, but __asm__ statements doesn't like >= 10 args.  */
#define check_int_register_contents \
  __asm__ __volatile__("cmpq %%rax, iregs(%%rip)\n\t" \
		       "jne my_abort\n\t" \
		       "cmpq %%rbx, iregs+8(%%rip)\n\t" \
		       "jne my_abort\n\t" \
		       "cmpq %%rcx, iregs+16(%%rip)\n\t" \
		       "jne my_abort\n\t" \
		       "cmpq %%rdx, iregs+24(%%rip)\n\t" \
		       "jne my_abort\n\t" \
		       "cmpq %%rsi, iregs+32(%%rip)\n\t" \
		       "jne my_abort\n\t" \
		       "cmpq %%rdi, iregs+40(%%rip)\n\t" \
		       "jne my_abort\n\t" \
		       "cmpq %%r8, iregs+48(%%rip)\n\t" \
		       "jne my_abort\n\t" \
		       "cmpq %%r9, iregs+56(%%rip)\n\t" \
		       "jne my_abort\n\t" \
		       "cmpq %%r10, iregs+64(%%rip)\n\t" \
		       "jne my_abort\n\t" \
		       "cmpq %%r11, iregs+72(%%rip)\n\t" \
		       "jne my_abort\n\t" \
		       "cmpq %%r12, iregs+80(%%rip)\n\t" \
		       "jne my_abort\n\t" \
		       "cmpq %%r13, iregs+88(%%rip)\n\t" \
		       "jne my_abort\n\t" \
		       "cmpq %%r14, iregs+96(%%rip)\n\t" \
		       "jne my_abort\n\t" \
		       "cmpq %%r15, iregs+104(%%rip)\n\t" \
		       "jne my_abort\n" ::: "memory"); \
  __asm__ __volatile__("cmpq %%rdi, %0\n\t" \
                       "jne my_abort\n" :: "g" (iregs.rdi) : "memory");

/* Clear register struct.  */
#define clear_struct_registers \
  iregs.rax = iregs.rbx = iregs.rcx = iregs.rdx = iregs.rsi = iregs.rdi \
    = iregs.r8 = iregs.r9 = iregs.r10 = iregs.r11 = iregs.r12 = iregs.r13 \
    = iregs.r14 = iregs.r15 = 0; \
  fregs.mm0 = fregs.mm1 = fregs.mm2 = fregs.mm3 = fregs.mm4 = fregs.mm5 \
    = fregs.mm6 = fregs.mm7 = fregs.st0 = fregs.st1 = fregs.st2 = fregs.st3 \
    = fregs.st4 = fregs.st5 = fregs.st6 = fregs.st7 = fregs.xmm0 = fregs.xmm1 \
    = fregs.xmm2 = fregs.xmm3 = fregs.xmm4 = fregs.xmm5 = fregs.xmm6 \
    = fregs.xmm7 = fregs.xmm8 = fregs.xmm9 = fregs.xmm10 = fregs.xmm11 \
    = fregs.xmm12 = fregs.xmm13 = fregs.xmm14 = fregs.xmm15 = 0;

/* Clear both hardware and register structs for integers.  */
#define clear_int_registers \
  clear_struct_registers \
  clear_int_hardware_registers

/* TODO: Do the checking.  */
#define check_float_register_contents

/* TODO: Do the clearing.  */
#define clear_float_hardware_registers

#define clear_float_registers \
  clear_struct_registers \
  clear_float_hardware_registers



#endif /* INCLUDED_ARGS_H  */
