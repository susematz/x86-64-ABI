#include "funcs.h"

/* ABI testing is done for the following cases:
   1: Size and alignment -- sizal()
      Tests for correct sizeof of all basic types, structs and arrays. Also
      tests for correct alignment of these.
   2: Passing scalar arguments -- scalarargs()
      Tests that arguments of basic types are passed correctly.
   3: Passing struct and union arguments -- struniargs()
      Tests that arguments of struct and union types are passed correctly.
      Also tests for mixed struct/union/scalar types
   4: Passing a variable number of args -- variargs()
   5: Relocation types -- reloc()
      Tests all relocation types

   For more information on the individual tests, see the file named like
   "testfunction.c".  */

/* Current test is used to perform a very quick "backtrace" to see which
   test failed. Current test holds the number of test as described above.
   If abort is called, the value of current_test is written to register
   %rax.  */
int current_test;

/* Set test number in %eax and exit.  */
void
my_abort (void)
{
    __asm__ __volatile__ ("movl %0, %%ecx\n\t"
			  "jmp abort\n"
			  : /* No output */
			  : "g" (current_test)
			  : "rcx");
}

/* Quick assert function which sets currest test number in %rax and exits.   */
void
assert (int expr)
{
    if (!expr)
	my_abort();
}

int
main (int argc, char **argv)
{
    current_test = 1; sizal();
    current_test = 2; scalarargs();
    current_test = 3; struniargs();
    current_test = 4; variargs();
    current_test = 5; reloc();

    return 0;
}
