/* This tests passing of structs. Only integers are tested.  */

/* Don't test optimization levels -O1 and -O2.  See test_passing_structs.c
   for an explanation.  */


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

union un1
{
  char c;
  int i;
};

union un2
{
  char c1;
  long l;
  char c2;
};

union un3
{
  struct int_struct is;
  struct long_struct ls;
  union un1 un;
};


void
check_mixed_passing1 (char c1, struct int_struct is, char c2)
{
  check_int_register_contents;
}

void
check_mixed_passing2 (char c1, struct long3_struct ls, char c2)
{
  check_int_register_contents;

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
  struct int_struct is = { 64 };
#ifdef CHECK_LARGER_STRUCTS
  struct long3_struct l3s = { 65, 66, 67 };
#endif

  clear_struct_registers;
  iregs.I0 = 8;
  iregs.I1 = 64;
  iregs.I2 = 9;
  clear_int_hardware_registers;
  check_mixed_passing1(8, is, 9);

#ifdef CHECK_LARGER_STRUCTS 
  clear_struct_registers;
  iregs.I0 = 10;
  iregs.I1 = 11;
  clear_int_hardware_registers;
  check_mixed_passing2(10, l3s, 11);
#endif

  return 0;
}
