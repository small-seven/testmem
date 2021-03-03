#include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */
#ifdef PPM_SUPPORTED
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


/*
 * On most systems, reading individual bytes with getc() is drastically less
 * efficient than buffering a row at a time with fread().  On PCs, we must
 * allocate the buffer in near data space, because we are assuming small-data
 * memory model, wherein fread() can't reach far memory.  If you need to
 * process very wide images on a PC, you might have to compile in large-memory
 * model, or else replace fread() with a getc() loop --- which will be much
 * slower.
 */


/* Private version of data source object */

typedef struct {
  struct cjpeg_source_struct pub; /* public fields */

  U_CHAR *iobuffer;		/* non-FAR pointer to I/O buffer */
  JSAMPROW pixrow;		/* FAR pointer to same */
  size_t buffer_width;		/* width of I/O buffer */
  JSAMPLE *rescale;		/* => maxval-remapping array, or NULL */
  unsigned int maxval;
} ppm_source_struct;
typedef ppm_source_struct * ppm_source_ptr;


LOCAL(int)
pbm_getc (FILE * infile)
/* Read next char, skipping over any comments */
/* A comment/newline sequence is returned as a newline */
{
  register int ch;

  ch = getc(infile);
  if (ch == '#') {
    do {
      ch = getc(infile);
    } while (ch != '\n' && ch != EOF);
#endif /* PPM_SUPPORTED */
