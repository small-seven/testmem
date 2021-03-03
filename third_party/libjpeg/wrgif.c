#include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */
#ifdef GIF_SUPPORTED
#define	MAX_LZW_BITS	12	/* maximum LZW code size (4096 symbols) */
typedef INT16 code_int;		/* must hold -1 .. 2**MAX_LZW_BITS */

#define LZW_TABLE_SIZE	((code_int) 1 << MAX_LZW_BITS)

#define HSIZE		5003	/* hash table size for 80% occupancy */

typedef int hash_int;		/* must hold -2*HSIZE..2*HSIZE */

#define MAXCODE(n_bits)	(((code_int) 1 << (n_bits)) - 1)


/*
 * The LZW hash table consists of two parallel arrays:
 *   hash_code[i]	code of symbol in slot i, or 0 if empty slot
 *   hash_value[i]	symbol's value; undefined if empty slot
 * where slot values (i) range from 0 to HSIZE-1.  The symbol value is
 * its prefix symbol's code concatenated with its suffix character.
 *
 * Algorithm:  use open addressing double hashing (no chaining) on the
 * prefix code / suffix character combination.  We do a variant of Knuth's
 * algorithm D (vol. 3, sec. 6.4) along with G. Knott's relatively-prime
 * secondary probe.
 *
 * The hash_value[] table is allocated from FAR heap space since it would
 * use up rather a lot of the near data space in a PC.
 */

typedef INT32 hash_entry;	/* must hold (code_int<<8) | byte */

#define HASH_ENTRY(prefix, suffix)  ((((hash_entry) (prefix)) << 8) | (suffix))


/* Private version of data destination object */

typedef struct {
  struct djpeg_dest_struct pub;	/* public fields */

  j_decompress_ptr cinfo;	/* back link saves passing separate parm */

  /* State for packing variable-width codes into a bitstream */
  int n_bits;			/* current number of bits/code */
  code_int maxcode;		/* maximum code, given n_bits */
  int init_bits;		/* initial n_bits ... restored after clear */
  INT32 cur_accum;		/* holds bits not yet output */
  int cur_bits;			/* # of bits in cur_accum */

  /* LZW string construction */
  code_int waiting_code;	/* symbol not yet output; may be extendable */
  boolean first_byte;		/* if TRUE, waiting_code is not valid */

  /* State for GIF code assignment */
  code_int ClearCode;		/* clear code (doesn't change) */
  code_int EOFCode;		/* EOF code (ditto) */
  code_int free_code;		/* LZW: first not-yet-used symbol code */
  code_int code_counter;	/* not LZW: counts output symbols */

  /* LZW hash table */
  code_int *hash_code;		/* => hash table of symbol codes */
  hash_entry FAR *hash_value;	/* => hash table of symbol values */

  /* GIF data packet construction buffer */
  int bytesinpkt;		/* # of bytes in current packet */
  char packetbuf[256];		/* workspace for accumulating packet */

} gif_dest_struct;
typedef gif_dest_struct * gif_dest_ptr;


/*
 * Routines to package finished data bytes into GIF data blocks.
 * A data block consists of a count byte (1..255) and that many data bytes.
 */

LOCAL(void)
flush_packet (gif_dest_ptr dinfo)
/* flush any accumulated data */
{
  if (dinfo->bytesinpkt > 0) {	/* never write zero-length packet */
    dinfo->packetbuf[0] = (char) dinfo->bytesinpkt++;
    if (JFWRITE(dinfo->pub.output_file, dinfo->packetbuf, dinfo->bytesinpkt)
	!= (size_t) dinfo->bytesinpkt)
      ERREXIT(dinfo->cinfo, JERR_FILE_WRITE);
    dinfo->bytesinpkt = 0;
  }
#define CHAR_OUT(dinfo, c)  \
#endif /* GIF_SUPPORTED */
