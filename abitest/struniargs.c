/* Tests the passing of structs and basic types to functions.  
   The only thing it actually does is to check if structs gets passed in
   registers or on the stack.  
   TODO: Return structs and unions.  */

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

/* Check that the struct is passed as the individual members in iregs.  */
void check_struct_passing1 (struct int_struct is)
{
  check_int_register_contents;
}

void check_struct_passing2 (struct long_struct ls)
{
  check_int_register_contents;
}

void check_struct_passing3 (struct long2_struct ls)
{
  check_int_register_contents;
}

void check_struct_passing4 (struct long3_struct ls)
{
  /* Check the passing on the stack by comparing the address of the
     stack elements to the expected place on the stack.  */
  __asm__ __volatile("leaq 16(%%rbp), %%r15\n\t"
		     "cmp %0, %%r15\n\t"
		     "jne my_abort\n\t"
		     "leaq 24(%%rbp), %%r15\n\t"
		     "cmp %1, %%r15\n\t"
		     "jne my_abort\n\t"
		     "leaq 32(%%rbp), %%r15\n\t"
		     "cmp %2, %%r15\n\t"
		     "jne my_abort\n"
		     :: "g" (&ls.l1), "g" (&ls.l2), "g" (&ls.l3) : "r15");
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
}

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
		     "jne my_abort\n\t"
		     "leaq 24(%%rbp), %%r15\n\t"
		     "cmp %1, %%r15\n\t"
		     "jne my_abort\n\t"
		     "leaq 32(%%rbp), %%r15\n\t"
		     "cmp %2, %%r15\n\t"
		     "jne my_abort\n"
		     :: "g" (&ls.l1), "g" (&ls.l2), "g" (&ls.l3) : "r15");
}

void
test_mixed_passing (void)
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
}

void
check_union_passing1(union un1 u)
{
  check_int_register_contents;
}

void
check_union_passing2(union un2 u)
{
  check_int_register_contents;
}

void
check_union_passing3(union un3 u)
{
  check_int_register_contents;
}

void
test_union_passing (void)
{
  union un1 u1;
#ifdef CHECK_LARGER_UNION_PASSING
  union un2 u2;
  union un3 u3;
  struct int_struct is;
  struct long_struct ls;
#endif /* CHECK_LARGER_UNION_PASSING */

  /* Check a union with char, int.  */
  clear_struct_registers;
  u1.c = 32;
  iregs.I0 = 32;
  clear_int_hardware_registers;
  check_union_passing1(u1);
  u1.i = 33;
  iregs.I0 = 33;
  clear_int_hardware_registers;
  check_union_passing1(u1);

  /* Check a union with char, long, char.  */
#ifdef CHECK_LARGER_UNION_PASSING
  clear_struct_registers;
  u2.c1 = 34;
  iregs.I0 = 34;
  clear_int_hardware_registers;
  check_union_passing2(u2);
  u2.l = 35;
  iregs.I0 = 35;
  clear_int_hardware_registers;
  check_union_passing2(u2);
  u2.c2 = 36;
  iregs.I0 = 36;
  clear_int_hardware_registers;
  check_union_passing2(u2);

  /* check a union containing two structs and a union.  */
  clear_struct_registers;
  is.i = 37;
  u3.is = is;
  iregs.I0 = 37;
  clear_int_hardware_registers;
  check_union_passing3(u3);
  ls.l = 38;
  u3.ls = ls;
  iregs.I0 = 38;
  clear_int_hardware_registers;
  check_union_passing3(u3);
  u1.c = 39;
  u3.un = u1;
  iregs.I0 = 39;
  clear_int_hardware_registers;
  check_union_passing3(u3);
  u1.i = 40;
  u3.un = u1;
  iregs.I0 = 40;
  clear_int_hardware_registers;
  check_union_passing3(u3);
#endif /* CHECK_LARGER_UNION_PASSING */
}

void
struniargs ()
{
  test_struct_passing ();
  test_mixed_passing ();

  /* FIXME: This doesn't work right now??  */
  test_union_passing ();
}
