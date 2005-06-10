#include "typelist.h"
#include "defines.h"


/* All scalar types.  */
const char *types[] = { "char", "short", "int", "long", "long long", "float",
			"double", CI128_STR CLD_STR CF128_STR CMM_STR };
int sizes[] = { 1, 2, 4, 8, 8, 4, 8, CI128_SIZ CLD_SIZ CF128_SIZ CMM_SIZ };
int aligns[] = { 1, 2, 4, 8, 8, 4, 8, CI128_ALI CLD_ALI CF128_ALI CMM_ALI };
const char *returns[] = { "rax", "rax", "rax", "rax", "rax", "xmm_regs[0]._float[0]",
			  "xmm_regs[0]._double[0]", CI128_RET CLD_RET CF128_RET CMM_RET };

int typecount = 1000000; /* This should give an error, if init() wasn't run. */

/* int, long, long, __int128  */
const char *bigger_int_types[] = { "int", "long", "long long", CI128_STR };
int bigger_int_sizes[] = { 4, 8, 8, CI128_SIZ };
int bigger_int_aligns[] = { 4, 8, 8, CI128_ALI };
int bigger_int_typecount = 1000000;

/* float, double, long double, __float128  */
const char *fp_types[] = { "float", "double", CLD_STR CF128_STR };
int fp_sizes[] = { 4, 8, CLD_SIZ CF128_SIZ };
int fp_aligns[] = { 4, 8, CLD_ALI CF128_ALI };
int fp_typecount = 1000000;


/* Initialization function. Must be called before use of the lists.  */
void
init_typelist ()
{
  typecount = sizeof(types) / sizeof(types[0]);
  bigger_int_typecount = sizeof(bigger_int_types)
    / sizeof(bigger_int_types[0]);
  fp_typecount = sizeof(fp_types) / sizeof(fp_types[0]);
}
