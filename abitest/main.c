#include "funcs.h"
#include "args.h"

/* ABI testing. The tests are described in the README file.

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
			:: "g" (current_test) : "rcx");
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
  current_test = 1; sizal ();
  current_test = 2; scalarargs ();
  current_test = 3; struniargs ();
  current_test = 4; variargs ();
  current_test = 5; reloc ();
  current_test = 6; returning ();

  return 0;
}
