#include "jinclude.h"
#include "jpeglib.h"
#include "jerror.h"
#ifndef HAVE_STDLIB_H		/* <stdlib.h> should declare malloc(),free() */
#endif
typedef struct {
  struct jpeg_destination_mgr pub; /* public fields */

  FILE * outfile;		/* target stream */
  JOCTET * buffer;		/* start of buffer */
} my_destination_mgr;
typedef my_destination_mgr * my_dest_ptr;

#define OUTPUT_BUF_SIZE  4096	/* choose an efficiently fwrite'able size */


/* Expanded data destination object for memory output */

typedef struct {
  struct jpeg_destination_mgr pub; /* public fields */

  unsigned char ** outbuffer;	/* target buffer */
  size_t * outsize;
  unsigned char * newbuffer;	/* newly allocated buffer */
  JOCTET * buffer;		/* start of buffer */
  size_t bufsize;
} my_mem_destination_mgr;
typedef my_mem_destination_mgr * my_mem_dest_ptr;


/*
 * Initialize destination --- called by jpeg_start_compress
 * before any data is actually written.
 */

METHODDEF(void)
init_destination (j_compress_ptr cinfo)
{
  my_dest_ptr dest = (my_dest_ptr) cinfo->dest;

  /* Allocate the output buffer --- it will be released when done with image */
  dest->buffer = (JOCTET *) (*cinfo->mem->alloc_small)
    ((j_common_ptr) cinfo, JPOOL_IMAGE, OUTPUT_BUF_SIZE * SIZEOF(JOCTET));

  dest->pub.next_output_byte = dest->buffer;
  dest->pub.free_in_buffer = OUTPUT_BUF_SIZE;
}
