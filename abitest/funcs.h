#ifndef FUNCS_H
#define FUNCS_H


/* Test functions.  */
void sizal ();
void scalarargs ();
void struniargs ();
void variargs ();
void reloc ();
void returning ();

void test_bitfields ();

/* Misc functions.  */
void my_abort ();
void assert (int expr);

/* Auto generated tests in sizal2.c.  */
void test_struct_and_unions ();

/* Auto generated tests in scalarargs2.c.  */
void test_ints_on_stack ();
void test_too_many_ints ();
void test_longs_on_stack ();
void test_too_many_longs ();
void test_int128s_on_stack ();
void test_too_many_int128s ();
void test_mixed_integers_on_stack ();
void test_too_many_mixed_integers ();
void test_floats_on_stack ();
void test_too_many_floats ();
void test_doubles_on_stack ();
void test_too_many_doubles ();
void test_long_doubles_on_stack ();
void test_too_many_long_doubles ();
void test_float128s_on_stack ();
void test_too_many_float128s ();
void test_mixed_floats_on_stack ();
void test_too_many_mixed_floats ();
void test_mixed_types_on_stack ();
void test_too_many_mixed_types ();

/* Auto generated tests in returning2.c  */
void test_scalar_returning ();


#endif // FUNCS_H
