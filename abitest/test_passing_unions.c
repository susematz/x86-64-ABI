/* This tests passing of structs. Only integers are tested.  */

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

int
main (int argc, char **argv)
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

  return 0;
}
