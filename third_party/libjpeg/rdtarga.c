#include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */
#ifdef TARGA_SUPPORTED
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


/* Private version of data source object */

typedef struct _tga_source_struct * tga_source_ptr;

typedef struct _tga_source_struct {
  struct cjpeg_source_struct pub; /* public fields */

  j_compress_ptr cinfo;		/* back link saves passing separate parm */

  JSAMPARRAY colormap;		/* Targa colormap (converted to my format) */

  jvirt_sarray_ptr whole_image;	/* Needed if funny input row order */
  JDIMENSION current_row;	/* Current logical row number to read */

  /* Pointer to routine to extract next Targa pixel from input file */
  JMETHOD(void, read_pixel, (tga_source_ptr sinfo));

  /* Result of read_pixel is delivered here: */
  U_CHAR tga_pixel[4];

  int pixel_size;		/* Bytes per Targa pixel (1 to 4) */
  int cmap_length;		/* colormap length */

  /* State info for reading RLE-coded pixels; both counts must be init to 0 */
  int block_count;		/* # of pixels remaining in RLE block */
  int dup_pixel_count;		/* # of times to duplicate previous pixel */

  /* This saves the correct pixel-row-expansion method for preload_image */
  JMETHOD(JDIMENSION, get_pixel_rows, (j_compress_ptr cinfo,
				       cjpeg_source_ptr sinfo));
} tga_source_struct;
#define get_32bit_row  get_24bit_row
#define GET_2B(offset)	((unsigned int) UCH(targaheader[offset]) + \
#endif /* TARGA_SUPPORTED */
