#include "defines.h"
#include "funcs.h"
#include "macros.h"

/* This is a very boring test. It starts by checking that all basic types
   has the correct size, and then starts checking combinations in structs
   and unions. Last it checks that alignments of all types are correct,
   including combinations in structs.
 */

#define check_basic_struct_size_and_align(_type, _size, _align) { \
  struct _str { _type dummy; }; \
  struct _str _t; \
  check_size(_t, _size); \
  check_align(_t, _align); \
}

#define check_array_alignment_and_size(_type, _size, _align) { \
  _type a[1], b[2], c[16]; \
  check_align(a[0], _align); \
  check_size(a, _size); \
  check_size(b, (_size*2)); \
  check_size(c, (_size*16)); \
}

#define check_type(_type, _size, _align) \
  check_size(_type, _size); \
  check_align(_type, _align); \
  check_basic_struct_size_and_align(_type, _size, _align); \
  check_array_alignment_and_size(_type, _size, _align);

#define check_type_with_signs(_type, _size, _align) \
  check_type(_type, _size, _align); \
  check_type(signed _type, _size, _align); \
  check_type(unsigned _type, _size, _align);

void
check_bitfields (void)
{
  /* TODO */
}

/* This function tests things that does not fit in other tests.  */
void
misfits (void)
{
  enum dummytype { enumtype };
  assert(sizeof(enumtype) == 4);
  assert(__alignof__(enumtype) == 4);
}

/* Check size of a struct and a union of three types.  */
#ifdef CHECK_STRUCT_SIZE
#define check_struct_and_union3(_type1, _type2, _type3, _size) \
{ \
  struct _str { _type1 t1; _type2 t2; _type3 t3; }; struct _str _t; \
  check_size(_t, (_size*3)); \
  union _uni { _type1 t1; _type2 t2; _type3 t3; }; union _uni _u; \
 check_size(_u, _size); \
}
#else /* not CHECK_STRUCT_SIZE */
#define check_struct_and_union3(_type1, _type2, _type3, _size) \
{ \
  union _uni { _type1 t1; _type2 t2; _type3 t3; }; union _uni _u; \
  check_size(_u, _size); \
}
#endif /* not CHECK_STRUCT_SIZE */


void
sizal (void)
{
  /* Check size, alignment, basic structs and arrays of simple types.  */
  check_type_with_signs(char, 1, 1);
  check_type_with_signs(short, 2, 2);
  check_type_with_signs(int, 4, 4);
  check_type_with_signs(long, 8, 8);
  check_type_with_signs(long long, 8, 8);
#ifdef CHECK_INT128
  check_type_with_signs(__int128, 16, 8);  */
#endif /* CHECK_INT128 */

  check_type(float, 4, 4);
  check_type(double, 8, 8);
#ifdef CHECK_LONG_DOUBLE
  check_type(long double, 16, 16);
#endif /* CHECK_LONG_DOUBLE */
#ifdef CHECK_FLOAT128
  check_type(__float128, 16, 16);
#endif /* CHECK_FLOAT128 */
#ifdef CHECK_M64_M128
  check_type(__m64, 8, 8);
  check_type(__m128, 16, 16);
#endif /* CHECK_M64_M128 */

  /* Check size and alignment of pointers.  */
  check_size(void *, 8);
  check_align(void *, 8);
  check_size(void (*)(), 8);
  check_align(void (*)(), 8);

  check_bitfields();

  misfits();

  /* Check structs of all permutations of 3 basic types.  */
#include "sizal2.c"
}
