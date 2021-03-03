#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#if BITS_IN_JSAMPLE == 8
#define MAX_COEF_BITS 10
#else
#define MAX_COEF_BITS 14
#endif
typedef struct {
  unsigned int ehufco[256];	/* code for each symbol */
  char ehufsi[256];		/* length of code for each symbol */
  /* If no code has been allocated for a symbol S, ehufsi[S] contains 0 */
} c_derived_tbl;
typedef struct {
  INT32 put_buffer;		/* current bit-accumulation buffer */
  int put_bits;			/* # of bits now in it */
  int last_dc_val[MAX_COMPS_IN_SCAN]; /* last DC coef for each component */
} savable_state;
#ifndef NO_STRUCT_ASSIGN
#define ASSIGN_STATE(dest,src)  ((dest) = (src))
#else
#if MAX_COMPS_IN_SCAN == 4
#define ASSIGN_STATE(dest,src)  \
#endif
#endif
typedef struct {
  struct jpeg_entropy_encoder pub; /* public fields */

  savable_state saved;		/* Bit buffer & DC state at start of MCU */

  /* These fields are NOT loaded into local working state. */
  unsigned int restarts_to_go;	/* MCUs left in this restart interval */
  int next_restart_num;		/* next restart number to write (0-7) */

  /* Pointers to derived tables (these workspaces have image lifespan) */
  c_derived_tbl * dc_derived_tbls[NUM_HUFF_TBLS];
  c_derived_tbl * ac_derived_tbls[NUM_HUFF_TBLS];

  /* Statistics tables for optimization */
  long * dc_count_ptrs[NUM_HUFF_TBLS];
  long * ac_count_ptrs[NUM_HUFF_TBLS];

  /* Following fields used only in progressive mode */

  /* Mode flag: TRUE for optimization, FALSE for actual data output */
  boolean gather_statistics;

  /* next_output_byte/free_in_buffer are local copies of cinfo->dest fields.
   */
  JOCTET * next_output_byte;	/* => next byte to write in buffer */
  size_t free_in_buffer;	/* # of byte spaces remaining in buffer */
  j_compress_ptr cinfo;		/* link to cinfo (needed for dump_buffer) */

  /* Coding status for AC components */
  int ac_tbl_no;		/* the table number of the single component */
  unsigned int EOBRUN;		/* run length of EOBs */
  unsigned int BE;		/* # of buffered correction bits before MCU */
  char * bit_buffer;		/* buffer for correction bits (1 per char) */
  /* packing correction bits tightly would save some space but cost time... */
} huff_entropy_encoder;
typedef huff_entropy_encoder * huff_entropy_ptr;

/* Working state while writing an MCU (sequential mode).
 * This struct contains all the fields that are needed by subroutines.
 */

typedef struct {
  JOCTET * next_output_byte;	/* => next byte to write in buffer */
  size_t free_in_buffer;	/* # of byte spaces remaining in buffer */
  savable_state cur;		/* Current bit buffer & DC state */
  j_compress_ptr cinfo;		/* dump_buffer needs access to this */
} working_state;
#define MAX_CORR_BITS  1000	/* Max # of correction bits I can buffer */
#ifdef RIGHT_SHIFT_IS_UNSIGNED
#define ISHIFT_TEMPS	int ishift_temp;
#define IRIGHT_SHIFT(x,shft)  \
#else
#define ISHIFT_TEMPS
#define IRIGHT_SHIFT(x,shft)	((x) >> (shft))
#endif
#define emit_byte_s(state,val,action)  \
#define emit_byte_e(entropy,val)  \
#define MAX_CLEN 32		/* assumed maximum initial code length */
#ifndef DONT_USE_FANCY_HUFF_OPT
#endif /* DONT_USE_FANCY_HUFF_OPT */
#ifdef DONT_USE_FANCY_HUFF_OPT
#endif /* DONT_USE_FANCY_HUFF_OPT */
