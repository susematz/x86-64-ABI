/* This tests passing of structs. Only integers are tested.  */

/* Use -fno-omit-frame-pointer for this.  See test_passing_structs.c
   for an explanation.  */

#include "defines.h"
#include "args.h"

struct IntegerRegisters iregs;
struct FloatRegisters fregs;
unsigned int num_iregs, num_fregs;

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
check_mixed_passing1 (char c1 ATTRIBUTE_UNUSED, struct int_struct is ATTRIBUTE_UNUSED, char c2 ATTRIBUTE_UNUSED)
{
  check_int_arguments;
}

void
check_mixed_passing2 (char c1 ATTRIBUTE_UNUSED, struct long3_struct ls ATTRIBUTE_UNUSED, char c2 ATTRIBUTE_UNUSED)
{
  unsigned int result;
  check_int_arguments;

  /* Check the passing on the stack by comparing the address of the
     stack elements to the expected place on the stack.  */
  __asm__ __volatile("leaq 16(%%rbp), %%r15\n\t"
		     "cmp %1, %%r15\n\t"
		     "jne 1f\n\t"
		     "leaq 24(%%rbp), %%r15\n\t"
		     "cmp %2, %%r15\n\t"
		     "jne 1f\n\t"
		     "leaq 32(%%rbp), %%r15\n\t"
		     "cmp %3, %%r15\n\t"
		     "jne 1f\n\t"
		     "xor %%eax, %%eax\n\t"
		     "jmp 2f\n\t"
		     "1: mov $1, %%al\n\t"
		     "2:\n"
		     : "=a" (result)
		     : "g" (&ls.l1), "g" (&ls.l2), "g" (&ls.l3) : "r15");
  if (result)
    abort ();
}

int
main (void)
{
  struct int_struct is = { 64 };
#ifdef CHECK_LARGER_STRUCTS
  struct long3_struct l3s = { 65, 66, 67 };
#endif

  clear_struct_registers;
  iregs.I0 = 8;
  iregs.I1 = 64;
  iregs.I2 = 9;
  num_iregs = 3;
  clear_int_hardware_registers;
  check_mixed_passing1(8, is, 9);

#ifdef CHECK_LARGER_STRUCTS 
  clear_struct_registers;
  iregs.I0 = 10;
  iregs.I1 = 11;
  num_iregs = 2;
  clear_int_hardware_registers;
  check_mixed_passing2(10, l3s, 11);
#endif

  return 0;
}
