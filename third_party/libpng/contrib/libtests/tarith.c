#define _POSIX_SOURCE 1
#define _ISOC99_SOURCE 1
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "../../pngpriv.h"
#define png_error png_warning
#define png_fixed_error png_fixed_warning
#define png_set_error_fn(pp, ep, efp, wfp) ((void)0)
#define png_malloc(pp, s) malloc(s)
#define png_malloc_warn(pp, s) malloc(s)
#define png_malloc_base(pp, s) malloc(s)
#define png_calloc(pp, s) calloc(1, (s))
#define png_free(pp, s) free(s)
#define png_safecat(b, sb, pos, str) (pos)
#define png_format_number(start, end, format, number) (start)
#define crc32(crc, pp, s) (crc)
#define inflateReset(zs) Z_OK
#define png_create_struct(type) (0)
#define png_destroy_struct(pp) ((void)0)
#define png_create_struct_2(type, m, mm) (0)
#define png_destroy_struct_2(pp, f, mm) ((void)0)
#undef PNG_SIMPLIFIED_READ_SUPPORTED
#undef PNG_SIMPLIFIED_WRITE_SUPPORTED
#undef PNG_USER_MEM_SUPPORTED
#include "../../png.c"
typedef enum checkfp_state
{
   start, fraction, exponent, states
} checkfp_state;
typedef struct
{
   char number[1024];  /* Buffer for number being tested */
   int  limit;         /* Command line limit */
   int  verbose;       /* Shadows global variable */
   int  ctimes;        /* Number of numbers tested */
   int  cmillions;     /* Count of millions of numbers */
   int  cinvalid;      /* Invalid strings checked */
   int  cnoaccept;     /* Characters not accepted */
}
typedef struct
{
   int           cnumber;          /* Index into number string */
   checkfp_state check_state;      /* Current number state */
   int           at_start;         /* At start (first character) of state */
   int           cdigits_in_state; /* Digits seen in that state */
   int           limit;            /* Limit on same for checking all chars */
   int           state;            /* Current parser state */
   int           is_negative;      /* Number is negative */
   int           is_zero;          /* Number is (still) zero */
   int           number_was_valid; /* Previous character validity */
}
#ifdef PNG_FLOATING_ARITHMETIC_SUPPORTED
#define LN2 .000010576586617430806112933839 /* log(2)/65536 */
#define L2INV 94548.46219969910586572651    /* 65536/log(2) */
#endif /* FLOATING_ARITHMETIC */
#define COUNT 1000000000
