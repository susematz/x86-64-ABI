/* Tests the passing of structs and basic types to functions.  
   The only thing it actually does is to check if structs gets passed in
   registers or on the stack.  */

#include "defines.h"
#include "args.h"


struct int_struct
{
  int i;
};

struct long_struct
{
  long l;
};

struct long2_struct
{
  long l1, l2;
};

struct long3_struct
{
  long l1, l2, l3;
};


/* Check that the struct is passed as the individual members in regs.  */
void check_struct_passing1 (struct int_struct is)
{
  check_register_contents;
}

void check_struct_passing2 (struct long_struct ls)
{
  check_register_contents;
}

void check_struct_passing3 (struct long2_struct ls)
{
  check_register_contents;
}

void check_struct_passing4 (struct long3_struct ls)
{
  /* Check that no registers are set. (This implies stack passing.)  */
  check_register_contents;

  /* Check the passing on the stack by comparing the address of the
     stack elements to the expected place on the stack. Uses 8(%rsp) as
     temporary space for the calculated address.  */
  __asm__ __volatile("mov %%rbp, 8(%%rsp)\n\t"
		     "add $16, 8(%%rsp)\n\t"
		     "cmp %0, 8(%%rsp)\n\t"
		     "jne my_abort\n\t"
		     "mov %%rbp, 8(%%rsp)\n\t"
		     "add $24, 8(%%rsp)\n\t"
		     "cmp %1, 8(%%rsp)\n\t"
		     "jne my_abort\n\t"
		     "mov %%rbp, 8(%%rsp)\n\t"
		     "add $32, 8(%%rsp)\n\t"
		     "cmp %2, 8(%%rsp)\n\t"
		     "jne my_abort\n"
		     :: "g" (&ls.l1), "g" (&ls.l2), "g" (&ls.l3));
}


void
test_struct_passing (void)
{
  struct int_struct is = { 48 };
  struct long_struct ls = { 49 };
#ifdef CHECK_LARGER_STRUCTS
  struct long2_struct l2s = { 50, 51 };
  struct long3_struct l3s = { 52, 53, 54 };
#endif

  clear_registers;
  regs.I0 = is.i;
  check_struct_passing1(is);

  clear_registers;
  regs.I0 = ls.l;
  check_struct_passing2(ls);

#ifdef CHECK_LARGER_STRUCTS
  clear_struct_registers;
  regs.I0 = l2s.l1;
  regs.I1 = l2s.l2;
  clear_hardware_registers
  check_struct_passing3(l2s);
  clear_registers; check_struct_passing4(l3s);
#endif
}

void
check_mixed_passing1 (char c1, struct int_struct is, char c2)
{
  regs.I0 = c2;
  regs.I1 = is.i;
  regs.I2 = c1;
  clear_registers; 
  check_register_contents;
}

void
check_mixed_passing2 (char c1, struct long3_struct ls, char c2)
{
  regs.I0 = c2;
  regs.I1 = c1;
  clear_registers;
  check_register_contents;

  /* Check the passing on the stack by comparing the address of the
     stack elements to the expected place on the stack. Uses 8(%rsp) as
     temporary space for the calculated address.  */
  __asm__ __volatile("mov %%rbp, 8(%%rsp)\n\t"
		     "add $16, 8(%%rsp)\n\t"
		     "cmp %0, 8(%%rsp)\n\t"
		     "jne my_abort\n\t"
		     "mov %%rbp, 8(%%rsp)\n\t"
		     "add $24, 8(%%rsp)\n\t"
		     "cmp %1, 8(%%rsp)\n\t"
		     "jne my_abort\n\t"
		     "mov %%rbp, 8(%%rsp)\n\t"
		     "add $32, 8(%%rsp)\n\t"
		     "cmp %2, 8(%%rsp)\n\t"
		     "jne my_abort\n"
		     :: "g" (&ls.l1), "g" (&ls.l2), "g" (&ls.l3));
}

void
test_mixed_passing (void)
{
  struct int_struct is = { 64 };
#ifdef CHECK_LARGER_STRUCTS
  struct long3_struct l3s = { 65, 66, 67 };
#endif

  check_mixed_passing1(8, is, 9);

#ifdef CHECK_LARGER_STRUCTS
  check_mixed_passing2(10, l3s, 11);
#endif
}

void
struniargs (void)
{
  test_struct_passing();
  test_mixed_passing();
}
