#include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */
#ifdef BMP_SUPPORTED
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

typedef struct _bmp_source_struct * bmp_source_ptr;

typedef struct _bmp_source_struct {
  struct cjpeg_source_struct pub; /* public fields */

  j_compress_ptr cinfo;		/* back link saves passing separate parm */

  JSAMPARRAY colormap;		/* BMP colormap (converted to my format) */

  jvirt_sarray_ptr whole_image;	/* Needed to reverse row order */
  JDIMENSION source_row;	/* Current source row number */
  JDIMENSION row_width;		/* Physical width of scanlines in file */

  int bits_per_pixel;		/* remembers 8-, 24-, or 32-bit format */
  int cmap_length;		/* colormap length */
} bmp_source_struct;
#define GET_2B(array, offset)  ((unsigned int) UCH(array[offset]) + \
#define GET_4B(array, offset)  ((INT32) UCH(array[offset]) + \
#endif /* BMP_SUPPORTED */
