#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#include "jdct.h"		/* Private declarations for DCT subsystem */
typedef struct {
  struct jpeg_forward_dct pub;	/* public fields */

  /* Pointer to the DCT routine actually in use */
  forward_DCT_method_ptr do_dct[MAX_COMPONENTS];

#ifdef DCT_FLOAT_SUPPORTED
  /* Same as above for the floating-point case. */
  float_DCT_method_ptr do_float_dct[MAX_COMPONENTS];
#endif
} my_fdct_controller;
typedef my_fdct_controller * my_fdct_ptr;


/* The allocated post-DCT divisor tables -- big enough for any
 * supported variant and not identical to the quant table entries,
 * because of scaling (especially for an unnormalized DCT) --
 * are pointed to by dct_table in the per-component comp_info
 * structures.  Each table is given in normal array order.
 */

typedef union {
  DCTELEM int_array[DCTSIZE2];
#ifdef DCT_FLOAT_SUPPORTED
  FAST_FLOAT float_array[DCTSIZE2];
#endif
} divisor_table;
#ifdef DCT_ISLOW_SUPPORTED
#define PROVIDE_ISLOW_TABLES
#else
#ifdef DCT_SCALING_SUPPORTED
#define PROVIDE_ISLOW_TABLES
#endif
#endif
#ifdef FAST_DIVIDE
#define DIVIDE_BY(a,b)	a /= b
#else
#define DIVIDE_BY(a,b)	if (a >= b) a /= b; else a = 0
#endif
#ifdef DCT_FLOAT_SUPPORTED
#endif /* DCT_FLOAT_SUPPORTED */
#ifdef DCT_SCALING_SUPPORTED
#endif
#ifdef DCT_ISLOW_SUPPORTED
#endif
#ifdef DCT_IFAST_SUPPORTED
#endif
#ifdef DCT_FLOAT_SUPPORTED
#endif
#ifdef PROVIDE_ISLOW_TABLES
#endif
#ifdef DCT_IFAST_SUPPORTED
#define CONST_BITS 14
#endif
#ifdef DCT_FLOAT_SUPPORTED
#endif
