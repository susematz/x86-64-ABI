#include "defines.h"
#include "funcs.h"
#include "macros.h"

/* This is a very boring test. It starts by checking that all basic types
   has the correct size, and then starts checking combinations in structs
   and unions. Last it checks that alignments of all types are correct,
   including combinations in structs.  */

void test_scalar_size ();
void test_scalar_alignment ();
void test_simple_structs ();
void test_arrays ();
void test_simple_unions ();
void test_struct_and_unions ();
void test_bitfields ();

void
sizal (void)
{
  test_scalar_size ();
  test_scalar_alignment ();
  test_simple_structs ();
  test_arrays ();
  test_simple_unions ();
  test_struct_and_unions ();
  test_bitfields ();
}


/* Used in size and alignment tests.  */
enum dummytype { enumtype };

/* Test size of all scalar types.  */
void
test_scalar_size ()
{
  /* Integral types.  */
  run_signed_tests2(check_size, char, TYPE_SIZE_CHAR);
  run_signed_tests2(check_size, short, TYPE_SIZE_SHORT);
  run_signed_tests2(check_size, int, TYPE_SIZE_INT);
  run_signed_tests2(check_size, long, TYPE_SIZE_LONG);
  run_signed_tests2(check_size, long long, TYPE_SIZE_LONG_LONG);
#ifdef CHECK_INT128
  run_signed_tests2(check_size, __int128, TYPE_SIZE_INT128);
#endif
  check_size(enumtype, TYPE_SIZE_ENUM);

  /* Floating point types.  */
  check_size(float, TYPE_SIZE_FLOAT);
  check_size(double, TYPE_SIZE_DOUBLE);
#ifdef CHECK_LONG_DOUBLE
  check_size(long double, TYPE_SIZE_LONG_DOUBLE);
#endif
#ifdef CHECK_FLOAT128
  check_size(__float128, TYPE_SIZE_FLOAT128);
#endif

  /* Packed types - MMX, 3DNow!, SSE and SSE2.  */
#ifdef CHECK_M64_M128
  check_size(__m64, TYPE_SIZE_M64);
  check_size(__m128, TYPE_SIZE_M128);
#endif

  /* Pointer types.  */
  check_size(void *, TYPE_SIZE_POINTER);
  check_size(void (*)(), TYPE_SIZE_POINTER);
}

/* Test alignment of all scalar types.  */
void
test_scalar_alignment ()
{
  /* Integral types.  */
  run_signed_tests2(check_align, char, TYPE_ALIGN_CHAR);
  run_signed_tests2(check_align, short, TYPE_ALIGN_SHORT);
  run_signed_tests2(check_align, int, TYPE_ALIGN_INT);
  run_signed_tests2(check_align, long, TYPE_ALIGN_LONG);
  run_signed_tests2(check_align, long long, TYPE_ALIGN_LONG_LONG);
#ifdef CHECK_INT128
  run_signed_tests2(check_align, __int128, TYPE_ALIGN_INT128);
#endif
  check_align(enumtype, TYPE_ALIGN_ENUM);

  /* Floating point types.  */
  check_align(float, TYPE_ALIGN_FLOAT);
  check_align(double, TYPE_ALIGN_DOUBLE);
#ifdef CHECK_LONG_DOUBLE
  check_align(long double, TYPE_ALIGN_LONG_DOUBLE);
#endif
#ifdef CHECK_FLOAT128
  check_align(__float128, TYPE_ALIGN_FLOAT128);
#endif

  /* Packed types - MMX, 3DNow!, SSE and SSE2.  */
#ifdef CHECK_M64_M128
  check_align(__m64, TYPE_ALIGN_M64);
  check_align(__m128, TYPE_ALIGN_M128);
#endif

  /* Pointer types.  */
  check_align(void *, TYPE_ALIGN_POINTER);
  check_align(void (*)(), TYPE_ALIGN_POINTER);
}

/* Test basic structs of one single scalar element.  */
void
test_simple_structs ()
{
  /* Integral types.  */
  run_signed_tests3(check_basic_struct_size_and_align, char, TYPE_SIZE_CHAR, TYPE_ALIGN_CHAR);
  run_signed_tests3(check_basic_struct_size_and_align, short, TYPE_SIZE_SHORT, TYPE_ALIGN_SHORT);
  run_signed_tests3(check_basic_struct_size_and_align, int, TYPE_SIZE_INT, TYPE_ALIGN_INT);
  run_signed_tests3(check_basic_struct_size_and_align, long, TYPE_SIZE_LONG, TYPE_ALIGN_LONG);
  run_signed_tests3(check_basic_struct_size_and_align, long long, TYPE_SIZE_LONG_LONG, TYPE_ALIGN_LONG_LONG);
#ifdef CHECK_INT128
  run_signed_tests3(check_basic_struct_size_and_align, __int128, TYPE_SIZE_INT128, TYPE_ALIGN_INT128);
#endif
  check_basic_struct_size_and_align(enum dummytype, TYPE_SIZE_ENUM, TYPE_ALIGN_ENUM);

  /* Floating point types.  */
  check_basic_struct_size_and_align(float, TYPE_SIZE_FLOAT, TYPE_ALIGN_FLOAT);
  check_basic_struct_size_and_align(double, TYPE_SIZE_DOUBLE, TYPE_ALIGN_DOUBLE);
#ifdef CHECK_LONG_DOUBLE
  check_basic_struct_size_and_align(long double, TYPE_SIZE_LONG_DOUBLE, TYPE_ALIGN_LONG_DOUBLE);
#endif
#ifdef CHECK_FLOAT128
  check_basic_struct_size_and_align(__float128, TYPE_SIZE_FLOAT128, TYPE_ALIGN_FLOAT128);
#endif

  /* Packed types - MMX, 3DNow!, SSE and SSE2.  */
#ifdef CHECK_M64_M128
  check_basic_struct_size_and_align(__m64, TYPE_SIZE_M64, TYPE_ALIGN_M64);
  check_basic_struct_size_and_align(__m128, TYPE_SIZE_M128, TYPE_ALIGN_M128);
#endif

  /* Pointer types. The function pointer doesn't work with these macros.  */
  check_basic_struct_size_and_align(void *, TYPE_SIZE_POINTER, TYPE_ALIGN_POINTER);
}

/* Test arrays of scalars.  */
void
test_arrays ()
{
  /* Integral types.  */
  run_signed_tests3(check_array_size_and_align, char, TYPE_SIZE_CHAR, TYPE_ALIGN_CHAR);
  run_signed_tests3(check_array_size_and_align, short, TYPE_SIZE_SHORT, TYPE_ALIGN_SHORT);
  run_signed_tests3(check_array_size_and_align, int, TYPE_SIZE_INT, TYPE_ALIGN_INT);
  run_signed_tests3(check_array_size_and_align, long, TYPE_SIZE_LONG, TYPE_ALIGN_LONG);
  run_signed_tests3(check_array_size_and_align, long long, TYPE_SIZE_LONG_LONG, TYPE_ALIGN_LONG_LONG);
#ifdef CHECK_INT128
  run_signed_tests3(check_array_size_and_align, __int128, TYPE_SIZE_INT128, TYPE_ALIGN_INT128);
#endif
  check_array_size_and_align(enum dummytype, TYPE_SIZE_ENUM, TYPE_ALIGN_ENUM);

  /* Floating point types.  */
  check_array_size_and_align(float, TYPE_SIZE_FLOAT, TYPE_ALIGN_FLOAT);
  check_array_size_and_align(double, TYPE_SIZE_DOUBLE, TYPE_ALIGN_DOUBLE);
#ifdef CHECK_LONG_DOUBLE
  check_array_size_and_align(long double, TYPE_SIZE_LONG_DOUBLE, TYPE_ALIGN_LONG_DOUBLE);
#endif
#ifdef CHECK_FLOAT128
  check_array_size_and_align(__float128, TYPE_SIZE_FLOAT128, TYPE_ALIGN_FLOAT128);
#endif

  /* Packed types - MMX, 3DNow!, SSE and SSE2.  */
#ifdef CHECK_M64_M128
  check_array_size_and_align(__m64, TYPE_SIZE_M64, TYPE_ALIGN_M64);
  check_array_size_and_align(__m128, TYPE_SIZE_M128, TYPE_ALIGN_M128);
#endif

  /* Pointer types. The function pointer doesn't work with these macros.  */
  check_array_size_and_align(void *, TYPE_SIZE_POINTER, TYPE_ALIGN_POINTER);
}

/* Test of simple unions, size and alignment.  */
void
test_simple_unions ()
{
  /* Integral types.  */
  run_signed_tests3(check_basic_union_size_and_align, char, TYPE_SIZE_CHAR, TYPE_ALIGN_CHAR);
  run_signed_tests3(check_basic_union_size_and_align, short, TYPE_SIZE_SHORT, TYPE_ALIGN_SHORT);
  run_signed_tests3(check_basic_union_size_and_align, int, TYPE_SIZE_INT, TYPE_ALIGN_INT);
  run_signed_tests3(check_basic_union_size_and_align, long, TYPE_SIZE_LONG, TYPE_ALIGN_LONG);
  run_signed_tests3(check_basic_union_size_and_align, long long, TYPE_SIZE_LONG_LONG, TYPE_ALIGN_LONG_LONG);
#ifdef CHECK_INT128
  run_signed_tests3(check_basic_union_size_and_align, __int128, TYPE_SIZE_INT128, TYPE_ALIGN_INT128);
#endif
  check_basic_union_size_and_align(enum dummytype, TYPE_SIZE_ENUM, TYPE_ALIGN_ENUM);

  /* Floating point types.  */
  check_basic_union_size_and_align(float, TYPE_SIZE_FLOAT, TYPE_ALIGN_FLOAT);
  check_basic_union_size_and_align(double, TYPE_SIZE_DOUBLE, TYPE_ALIGN_DOUBLE);
#ifdef CHECK_LONG_DOUBLE
  check_basic_union_size_and_align(long double, TYPE_SIZE_LONG_DOUBLE, TYPE_ALIGN_LONG_DOUBLE);
#endif
#ifdef CHECK_FLOAT128
  check_basic_union_size_and_align(__float128, TYPE_SIZE_FLOAT128, TYPE_ALIGN_FLOAT128);
#endif

  /* Packed types - MMX, 3DNow!, SSE and SSE2.  */
#ifdef CHECK_M64_M128
  check_basic_union_size_and_align(__m64, TYPE_SIZE_M64, TYPE_ALIGN_M64);
  check_basic_union_size_and_align(__m128, TYPE_SIZE_M128, TYPE_ALIGN_M128);
#endif

  /* Pointer types. The function pointer doesn't work with these macros.  */
  check_basic_union_size_and_align(void *, TYPE_SIZE_POINTER, TYPE_ALIGN_POINTER);
}
