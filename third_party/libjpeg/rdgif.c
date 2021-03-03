#include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */
#ifdef GIF_SUPPORTED
#ifdef HAVE_UNSIGNED_CHAR
typedef unsigned char U_CHAR;
#define UCH(x)	((int) (x))
#else /* !HAVE_UNSIGNED_CHAR */
typedef char U_CHAR;
#ifdef CHAR_IS_UNSIGNED
#define UCH(x)	((int) (x))
#else
#define UCH(x)	((int) (x) & 0xFF)
#endif
#endif /* HAVE_UNSIGNED_CHAR */


#define	ReadOK(file,buffer,len)	(JFREAD(file,buffer,len) == ((size_t) (len)))


#define	MAXCOLORMAPSIZE	256	/* max # of colors in a GIF colormap */
#define NUMCOLORS	3	/* # of colors */
#define CM_RED		0	/* color component numbers */
#define CM_GREEN	1
#define CM_BLUE		2

#define	MAX_LZW_BITS	12	/* maximum LZW code size */
#define LZW_TABLE_SIZE	(1<<MAX_LZW_BITS) /* # of possible LZW symbols */

/* Macros for extracting header data --- note we assume chars may be signed */

#define LM_to_uint(array, offset)  ((unsigned int) UCH(array[offset]) + \
				(((unsigned int) UCH(array[offset+1])) << 8))

#define BitSet(byte, bit)	((byte) & (bit))
#define INTERLACE	0x40	/* mask for bit signifying interlaced image */
#define COLORMAPFLAG	0x80	/* mask for bit signifying colormap presence */


/*
 * LZW decompression tables look like this:
 *   symbol_head[K] = prefix symbol of any LZW symbol K (0..LZW_TABLE_SIZE-1)
 *   symbol_tail[K] = suffix byte   of any LZW symbol K (0..LZW_TABLE_SIZE-1)
 * Note that entries 0..end_code of the above tables are not used,
 * since those symbols represent raw bytes or special codes.
 *
 * The stack represents the not-yet-used expansion of the last LZW symbol.
 * In the worst case, a symbol could expand to as many bytes as there are
 * LZW symbols, so we allocate LZW_TABLE_SIZE bytes for the stack.
 * (This is conservative since that number includes the raw-byte symbols.)
 *
 * The tables are allocated from FAR heap space since they would use up
 * rather a lot of the near data space in a PC.
 */


/* Private version of data source object */

typedef struct {
  struct cjpeg_source_struct pub; /* public fields */

  j_compress_ptr cinfo;		/* back link saves passing separate parm */

  JSAMPARRAY colormap;		/* GIF colormap (converted to my format) */

  /* State for GetCode and LZWReadByte */
  U_CHAR code_buf[256+4];	/* current input data block */
  int last_byte;		/* # of bytes in code_buf */
  int last_bit;			/* # of bits in code_buf */
  int cur_bit;			/* next bit index to read */
  boolean first_time;		/* flags first call to GetCode */
  boolean out_of_blocks;	/* TRUE if hit terminator data block */

  int input_code_size;		/* codesize given in GIF file */
  int clear_code, end_code;	/* values for Clear and End codes */

  int code_size;		/* current actual code size */
  int limit_code;		/* 2^code_size */
  int max_code;			/* first unused code value */

  /* Private state for LZWReadByte */
  int oldcode;			/* previous LZW symbol */
  int firstcode;		/* first byte of oldcode's expansion */

  /* LZW symbol table and expansion stack */
  UINT16 FAR *symbol_head;	/* => table of prefix symbols */
  UINT8  FAR *symbol_tail;	/* => table of suffix bytes */
  UINT8  FAR *symbol_stack;	/* => stack for symbol expansions */
  UINT8  FAR *sp;		/* stack pointer */

  /* State for interlaced image processing */
  boolean is_interlaced;	/* TRUE if have interlaced image */
  jvirt_sarray_ptr interlaced_image; /* full image in interlaced order */
  JDIMENSION cur_row_number;	/* need to know actual row number */
  JDIMENSION pass2_offset;	/* # of pixel rows in pass 1 */
  JDIMENSION pass3_offset;	/* # of pixel rows in passes 1&2 */
  JDIMENSION pass4_offset;	/* # of pixel rows in passes 1,2,3 */
} gif_source_struct;
typedef gif_source_struct * gif_source_ptr;


/* Forward declarations */
METHODDEF(JDIMENSION) get_pixel_rows
	JPP((j_compress_ptr cinfo, cjpeg_source_ptr sinfo));
METHODDEF(JDIMENSION) load_interlaced_image
	JPP((j_compress_ptr cinfo, cjpeg_source_ptr sinfo));
METHODDEF(JDIMENSION) get_interlaced_row
	JPP((j_compress_ptr cinfo, cjpeg_source_ptr sinfo));


LOCAL(int)
ReadByte (gif_source_ptr sinfo)
/* Read next byte from GIF file */
{
  register FILE *infile = sinfo->pub.input_file;
  register int c;

  if ((c = getc(infile)) == EOF)
    ERREXIT(sinfo->cinfo, JERR_INPUT_EOF);
  return c;
}
#if BITS_IN_JSAMPLE == 8
#define UPSCALE(x)  (x)
#else
#define UPSCALE(x)  ((x) << (BITS_IN_JSAMPLE-8))
#endif
#endif /* GIF_SUPPORTED */
