#ifndef TYPELIST_H
#define TYPELIST_H

/* Don't generate returning or passing tests for this type,
   but _do_ generate size and alignment tests.  */
#define NO_AUTORETURN 1

/* This is the list of types to be tested. The content of the list can be
   controlled by the defines in defines.h.  */

extern const char *types[];
extern int sizes[];
extern int aligns[];
extern int typecount;
extern const char *returns[];
extern int testflags[];


/* The following lists are subsets of the above defined.  */

/* int, long, long, __int128  */
extern const char *bigger_int_types[];
extern int bigger_int_sizes[];
extern int bigger_int_aligns[];
extern int bigger_int_typecount;

/* float, double, long double, __float128  */
extern const char *fp_types[];
extern int fp_sizes[];
extern int fp_aligns[];
extern int fp_typecount;

void init_typelist ();


#endif // TYPELIST_H
