#include "defines.h"

/* These defines control the building of the list of types to check. There
   is a string identifying the type (with a comma after), a size of the type
   (also with a comma and an integer for adding to the total amount of types.  
*/
#ifdef CHECK_INT128
#define CI128_S "__int128",
#define CI128_I 16, 
#else
#define CI128_S
#define CI128_I
#endif
#ifdef CHECK_LONG_DOUBLE
#define CLD_S "long double",
#define CLD_I 16, 
#else
#define CLD_S
#define CLD_I
#endif
#ifdef CHECK_FLOAT128
#define CF128_S "__float128",
#define CF128_I 16, 
#else
#define CF128_S
#define CF128_I
#endif
#ifdef CHECK_M64_M128
#define CMM_S "__m64", "__m128",
#define CMM_I 8, 16, 
#else
#define CMM_S
#define CMM_I
#endif


int
max3 (int a, int b, int c)
{
  int max = a > b ? a : b;
  return max > c ? max : c;
}

/* This constructs the test for size of structs and unions with three scalar
   types.  */
int
main (int argc, char **argv)
{
  int i, j, k;
  char *types[] = { "char", "short", "int", "long", "long long",
		    "float", "double", CI128_S CLD_S CF128_S CMM_S };
  int sizes[] = { 1, 2, 4, 8, 8, 4, 8, CI128_I CLD_I CF128_I CMM_I };
  int maxcheck = sizeof(types) / sizeof(types[0]);

  for (i=0; i<maxcheck; i++)
    for (j=0; j<maxcheck; j++)
      for (k=0; k<maxcheck; k++)
	printf("check_struct_and_union3(%s, %s, %s, %d);\n", types[i],
	       types[j], types[k], max3(sizes[i], sizes[j], sizes[k]));

  return 0;
}
