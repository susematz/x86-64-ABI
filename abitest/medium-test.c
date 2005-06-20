#ifndef T
#define T int
#endif
#ifndef SIZE
#define SIZE 1024*1024*1ll
#endif
#if SIZE < 8
#undef SIZE
#define SIZE 8
#endif
#ifndef NUM_ARRAY
#define NUM_ARRAY 4
#endif
#ifndef NUM_STRUCT
#define NUM_STRUCT 3
#endif
#ifndef STATIC
#define STATIC static
#endif
#ifndef INIT
#define DEFAULT_INIT
#define INIT ={1}
#endif


#define SKIP ((SIZE/8) < (1024*1024*10/sizeof(T)) ? (SIZE/8) : (1024*1024*10/sizeof(T)))
#define NUM_ELEM ((unsigned long)(SIZE / sizeof(T)))

extern void abort (void);

char before;
char before_init = 1;
#if NUM_ARRAY > 0
STATIC T big_ar1[NUM_ELEM] INIT;
#endif
#if NUM_ARRAY > 1
STATIC T big_ar2[NUM_ELEM] INIT;
#endif
#if NUM_ARRAY > 2
STATIC T big_ar3[NUM_ELEM] INIT;
#endif
#if NUM_ARRAY > 3
STATIC T big_ar4[NUM_ELEM] INIT;
#endif

STATIC struct {
  char before;
#if NUM_STRUCT > 0
  T mem1[NUM_ELEM];
#endif
#if NUM_STRUCT > 1
  T mem2[NUM_ELEM];
#endif
#if NUM_STRUCT > 2
  T mem3[NUM_ELEM];
#endif
#if NUM_STRUCT > 3
  T mem4[NUM_ELEM];
#endif
  char after;
} the_struct
#ifdef DEFAULT_INIT
  = { 1,
#if NUM_STRUCT > 0
      { 0 },
#endif
#if NUM_STRUCT > 1
      { 0 },
#endif
#if NUM_STRUCT > 2
      { 0 },
#endif
#if NUM_STRUCT > 3
      { 0 },
#endif

      0 };
#endif
;

char after;
char after_init = 1;

T * some_pointers[] = {
#if NUM_ARRAY > 0
&big_ar1[0],
#endif
#if NUM_ARRAY > 1
&big_ar2[0],
#endif
#if NUM_ARRAY > 2
&big_ar3[0],
#endif
#if NUM_ARRAY > 3
&big_ar4[0],
#endif
#if NUM_STRUCT > 0
  &the_struct.mem1[0],
#endif
#if NUM_STRUCT > 1
  &the_struct.mem2[0],
#endif
#if NUM_STRUCT > 2
  &the_struct.mem3[0],
#endif
#if NUM_STRUCT > 3
  &the_struct.mem4[0],
#endif
};

#define CHECK(N,NUM,INIT) do {\
  unsigned long __i; \
  unsigned char __c = INIT; \
  if (N[0] != __c) \
    abort (); \
  for (__i = SKIP; __i < (NUM); __i += SKIP) \
    if (N[__i] != __c++) \
      abort (); \
  if (__i-SKIP+1 != (NUM) && N[(NUM)-1] != __c++) \
    abort (); \
} while (0)

#define FILL(N,NUM,INIT) do { \
  unsigned long __i; \
  unsigned char __c = INIT; \
  N[0] = __c; \
  for (__i = SKIP; __i < (NUM); __i += SKIP) \
    N[__i] = __c++; \
  if (__i-SKIP+1 != (NUM)) \
    N[(NUM)-1] = __c++; \
} while (0)

void check_ar (T *a, unsigned long n, unsigned char init)
{
  CHECK (a, n, init);
}

void fill_ar (T *a, unsigned long n, unsigned char init)
{
  FILL (a, n, init);
}

int main(void)
{
  unsigned i;
  before = 1;
  after = 1;
  before_init = 2;
  after_init = 2;
  the_struct.before = 3;
  the_struct.after = 3;

  for (i = 0; i < sizeof(some_pointers) / sizeof(some_pointers[0]); i++)
    fill_ar (some_pointers[i], NUM_ELEM, i);

  i = 0;
#if NUM_ARRAY > 0
  CHECK (big_ar1, NUM_ELEM, i);
  i++;
#endif
#if NUM_ARRAY > 1
  CHECK (big_ar2, NUM_ELEM, i);
  i++;
#endif
#if NUM_ARRAY > 2
  CHECK (big_ar3, NUM_ELEM, i);
  i++;
#endif
#if NUM_ARRAY > 3
  CHECK (big_ar4, NUM_ELEM, i);
  i++;
#endif
#if NUM_STRUCT > 0
  CHECK (the_struct.mem1, NUM_ELEM, i);
  i++;
#endif
#if NUM_STRUCT > 1
  CHECK (the_struct.mem2, NUM_ELEM, i);
  i++;
#endif
#if NUM_STRUCT > 2
  CHECK (the_struct.mem3, NUM_ELEM, i);
  i++;
#endif
#if NUM_STRUCT > 3
  CHECK (the_struct.mem4, NUM_ELEM, i);
  i++;
#endif

  return 0;
}
