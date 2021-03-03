#include <stdio.h>
#include <stdlib.h>
#include "readpng.h"    /* typedefs, common macros, public prototypes */
#include "readpng.h"    /* typedefs, common macros, public prototypes */


ulg  width, height;
int  bit_depth, color_type, channels;
uch  *image_data = NULL;
FILE *saved_infile;


void readpng_version_info()
{
    fprintf(stderr, "   Compiled without libpng, zlib or PBMPLUS/NetPBM.\n");
}
