/* This tests passing of structs. Only integers are tested.  */

/* Don't test optimization levels -O1 and -O2.  With optimization the
   test for passing the struct on the stack can't be run because the
   optimization removes the stackpointer setup normally done in a
   function.  */


#include "defines.h"
#include "args.h"

struct IntegerRegisters iregs;
struct FloatRegisters fregs;

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


/* Check that the struct is passed as the individual members in iregs.  */
void
check_struct_passing1 (struct int_struct is)
{
  check_int_register_contents;
}

void
check_struct_passing2 (struct long_struct ls)
{
  check_int_register_contents;
}

void
check_struct_passing3 (struct long2_struct ls)
{
  check_int_register_contents;
}

void
check_struct_passing4 (struct long3_struct ls)
{
  /* Check the passing on the stack by comparing the address of the
     stack elements to the expected place on the stack.  */
  __asm__ __volatile("leaq 16(%%rbp), %%r15\n\t"
		     "cmp %0, %%r15\n\t"
		     "jne abort\n\t"
		     "leaq 24(%%rbp), %%r15\n\t"
		     "cmp %1, %%r15\n\t"
		     "jne abort\n\t"
		     "leaq 32(%%rbp), %%r15\n\t"
		     "cmp %2, %%r15\n\t"
		     "jne abort\n"
		     :: "g" (&ls.l1), "g" (&ls.l2), "g" (&ls.l3) : "r15");
}


int
main (int argc, char **argv)
{
  struct int_struct is = { 48 };
  struct long_struct ls = { 49 };
#ifdef CHECK_LARGER_STRUCTS
  struct long2_struct l2s = { 50, 51 };
  struct long3_struct l3s = { 52, 53, 54 };
#endif

  clear_struct_registers;
  iregs.I0 = is.i;
  clear_int_hardware_registers;
  check_struct_passing1(is);

  clear_struct_registers;
  iregs.I0 = ls.l;
  clear_int_hardware_registers;
  check_struct_passing2(ls);

#ifdef CHECK_LARGER_STRUCTS
  clear_struct_registers;
  iregs.I0 = l2s.l1;
  iregs.I1 = l2s.l2;
  clear_int_hardware_registers;
  check_struct_passing3(l2s);
  check_struct_passing4(l3s);
#endif

  return 0;
}
