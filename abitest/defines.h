#ifndef DEFINED_DEFINES_H
#define DEFINED_DEFINES_H


/* The defines in this file determines what part of the test should be run.
   When GCC implements these parts, the defines should be uncommented to
   enable testing.  */

/* Scalar type __int128.  */
/* #define CHECK_INT128 */

/* Scalar type long double.  */
/* #define CHECK_LONG_DOUBLE */

/* Scalar type __float128.  */
/* #define CHECK_FLOAT128 */

/* Scalar types __m64 and __m128.  */
/* #define CHECK_M64_M128 */

/* Structs with size >= 16.  */
/* #define CHECK_LARGER_STRUCTS */

/* Alignments of arrays with size >= 16.  */
/* #define CHECK_LARGER_ARRAY_ALIGNMENT */

/* Variable args.  */
#define CHECK_VARARGS


#endif /* DEFINED_DEFINES_H */
