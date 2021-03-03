#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
typedef struct {
  struct jpeg_entropy_decoder pub; /* public fields */

  INT32 c;       /* C register, base of coding interval + input bit buffer */
  INT32 a;               /* A register, normalized size of coding interval */
  int ct;     /* bit shift counter, # of bits left in bit buffer part of C */
                                                         /* init: ct = -16 */
                                                         /* run: ct = 0..7 */
                                                         /* error: ct = -1 */
  int last_dc_val[MAX_COMPS_IN_SCAN]; /* last DC coef for each component */
  int dc_context[MAX_COMPS_IN_SCAN]; /* context index for DC conditioning */

  unsigned int restarts_to_go;	/* MCUs left in this restart interval */

  /* Pointers to statistics areas (these workspaces have image lifespan) */
  unsigned char * dc_stats[NUM_ARITH_TBLS];
  unsigned char * ac_stats[NUM_ARITH_TBLS];

  /* Statistics bin for coding with fixed probability 0.5 */
  unsigned char fixed_bin[4];
} arith_entropy_decoder;
typedef arith_entropy_decoder * arith_entropy_ptr;

/* The following two definitions specify the allocation chunk size
 * for the statistics area.
 * According to sections F.1.4.4.1.3 and F.1.4.4.2, we need at least
 * 49 statistics bins for DC, and 245 statistics bins for AC coding.
 *
 * We use a compact representation with 1 byte per statistics bin,
 * thus the numbers directly represent byte sizes.
 * This 1 byte per statistics bin contains the meaning of the MPS
 * (more probable symbol) in the highest bit (mask 0x80), and the
 * index into the probability estimation state machine table
 * in the lower bits (mask 0x7F).
 */

#define DC_STAT_BINS 64
#define AC_STAT_BINS 256


LOCAL(int)
get_byte (j_decompress_ptr cinfo)
/* Read next input byte; we do not support suspension in this module. */
{
  struct jpeg_source_mgr * src = cinfo->src;

  if (src->bytes_in_buffer == 0)
    if (! (*src->fill_input_buffer) (cinfo))
      ERREXIT(cinfo, JERR_CANT_SUSPEND);
  src->bytes_in_buffer--;
  return GETJOCTET(*src->next_input_byte++);
}
