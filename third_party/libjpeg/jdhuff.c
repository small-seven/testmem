#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#define HUFF_LOOKAHEAD	8	/* # of bits of lookahead */
typedef struct {
  /* Basic tables: (element [0] of each array is unused) */
  INT32 maxcode[18];		/* largest code of length k (-1 if none) */
  /* (maxcode[17] is a sentinel to ensure jpeg_huff_decode terminates) */
  INT32 valoffset[17];		/* huffval[] offset for codes of length k */
  /* valoffset[k] = huffval[] index of 1st symbol of code length k, less
   * the smallest code of length k; so given a code of length k, the
   * corresponding symbol is huffval[code + valoffset[k]]
   */

  /* Link to public Huffman table (needed only in jpeg_huff_decode) */
  JHUFF_TBL *pub;

  /* Lookahead tables: indexed by the next HUFF_LOOKAHEAD bits of
   * the input data stream.  If the next Huffman code is no more
   * than HUFF_LOOKAHEAD bits long, we can obtain its length and
   * the corresponding symbol directly from these tables.
   */
  int look_nbits[1<<HUFF_LOOKAHEAD]; /* # bits, or 0 if too long */
  UINT8 look_sym[1<<HUFF_LOOKAHEAD]; /* symbol, or unused */
} d_derived_tbl;
typedef INT32 bit_buf_type;	/* type of bit-extraction buffer */
#define BIT_BUF_SIZE  32	/* size of buffer in bits */

/* If long is > 32 bits on your machine, and shifting/masking longs is
 * reasonably fast, making bit_buf_type be long and setting BIT_BUF_SIZE
 * appropriately should be a win.  Unfortunately we can't define the size
 * with something like  #define BIT_BUF_SIZE (sizeof(bit_buf_type)*8)
 * because not all machines measure sizeof in 8-bit bytes.
 */

typedef struct {		/* Bitreading state saved across MCUs */
  bit_buf_type get_buffer;	/* current bit-extraction buffer */
  int bits_left;		/* # of unused bits in it */
} bitread_perm_state;
typedef struct {		/* Bitreading working state within an MCU */
  /* Current data source location */
  /* We need a copy, rather than munging the original, in case of suspension */
  const JOCTET * next_input_byte; /* => next byte to read from source */
  size_t bytes_in_buffer;	/* # of bytes remaining in source buffer */
  /* Bit input buffer --- note these values are kept in register variables,
   * not in this struct, inside the inner loops.
   */
  bit_buf_type get_buffer;	/* current bit-extraction buffer */
  int bits_left;		/* # of unused bits in it */
  /* Pointer needed by jpeg_fill_bit_buffer. */
  j_decompress_ptr cinfo;	/* back link to decompress master record */
} bitread_working_state;
#define BITREAD_STATE_VARS  \
#define BITREAD_LOAD_STATE(cinfop,permstate)  \
#define BITREAD_SAVE_STATE(cinfop,permstate)  \
#define CHECK_BIT_BUFFER(state,nbits,action) \
#define GET_BITS(nbits) \
#define PEEK_BITS(nbits) \
#define DROP_BITS(nbits) \
#define HUFF_DECODE(result,state,htbl,failaction,slowlabel) \
typedef struct {
  unsigned int EOBRUN;			/* remaining EOBs in EOBRUN */
  int last_dc_val[MAX_COMPS_IN_SCAN];	/* last DC coef for each component */
} savable_state;
#ifndef NO_STRUCT_ASSIGN
#define ASSIGN_STATE(dest,src)  ((dest) = (src))
#else
#if MAX_COMPS_IN_SCAN == 4
#define ASSIGN_STATE(dest,src)  \
#endif
#endif
typedef struct {
  struct jpeg_entropy_decoder pub; /* public fields */

  /* These fields are loaded into local variables at start of each MCU.
   * In case of suspension, we exit WITHOUT updating them.
   */
  bitread_perm_state bitstate;	/* Bit buffer at start of MCU */
  savable_state saved;		/* Other state at start of MCU */

  /* These fields are NOT loaded into local working state. */
  boolean insufficient_data;	/* set TRUE after emitting warning */
  unsigned int restarts_to_go;	/* MCUs left in this restart interval */

  /* Following two fields used only in progressive mode */

  /* Pointers to derived tables (these workspaces have image lifespan) */
  d_derived_tbl * derived_tbls[NUM_HUFF_TBLS];

  d_derived_tbl * ac_derived_tbl; /* active table during an AC scan */

  /* Following fields used only in sequential mode */

  /* Pointers to derived tables (these workspaces have image lifespan) */
  d_derived_tbl * dc_derived_tbls[NUM_HUFF_TBLS];
  d_derived_tbl * ac_derived_tbls[NUM_HUFF_TBLS];

  /* Precalculated info set up by start_pass for use in decode_mcu: */

  /* Pointers to derived tables to be used for each block within an MCU */
  d_derived_tbl * dc_cur_tbls[D_MAX_BLOCKS_IN_MCU];
  d_derived_tbl * ac_cur_tbls[D_MAX_BLOCKS_IN_MCU];
  /* Whether we care about the DC and AC coefficient values for each block */
  int coef_limit[D_MAX_BLOCKS_IN_MCU];
} huff_entropy_decoder;
typedef huff_entropy_decoder * huff_entropy_ptr;


static const int jpeg_zigzag_order[8][8] = {
  {  0,  1,  5,  6, 14, 15, 27, 28 },
#ifdef SLOW_SHIFT_32
#define MIN_GET_BITS  15	/* minimum allowable value */
#else
#define MIN_GET_BITS  (BIT_BUF_SIZE-7)
#endif
#ifdef AVOID_TABLES
#define BIT_MASK(nbits)   ((1<<(nbits))-1)
#define HUFF_EXTEND(x,s)  ((x) < (1<<((s)-1)) ? (x) - ((1<<(s))-1) : (x))
#else
#define BIT_MASK(nbits)   bmask[nbits]
#define HUFF_EXTEND(x,s)  ((x) <= bmask[(s) - 1] ? (x) - bmask[s] : (x))
#endif /* AVOID_TABLES */
