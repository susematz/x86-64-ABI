/* This tests passing of basic types to functions. It does this by comparing
   all registers to their expected values.  
   Macros are used to avoid register clobbering.  
   TODO: mixed scalar types passing and all returning.  */

#include "defines.h"
#include "args.h"
#include "funcs.h"

struct IntegerRegisters iregs;
struct FloatRegisters fregs;

void
scalarargs (void)
{
  test_ints_on_stack ();
  test_too_many_ints ();

  test_longs_on_stack ();
  test_too_many_longs ();

  test_int128s_on_stack ();
  test_too_many_int128s ();

#if 0
  test_mixed_integers_on_stack ();
  test_too_many_mixed_integers ();
#endif

  test_floats_on_stack ();
  test_too_many_floats ();

  test_doubles_on_stack ();
  test_too_many_doubles ();

  test_long_doubles_on_stack ();
  test_too_many_long_doubles ();

  test_float128s_on_stack ();
  test_too_many_float128s ();

#if 0
  test_mixed_floats_on_stack ();
  test_too_many_mixed_floats ();

  test_mixed_types_on_stack ();
  test_too_many_mixed_types ();

  test_returning ();
#endif
}
