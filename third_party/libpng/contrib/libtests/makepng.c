#define _ISOC99_SOURCE
#define COPYRIGHT "\251 2013,2015 John Cunningham Bowler"
#define IMAGE_LICENSING "Dedicated to the public domain per Creative Commons "\
#include <stddef.h> /* for offsetof */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>
#include <assert.h>
#include <stdint.h>
#if defined(HAVE_CONFIG_H) && !defined(PNG_NO_CONFIG_H)
#  include <config.h>
#endif
#ifdef PNG_FREESTANDING_TESTS
#  include <png.h>
#else
#  include "../../png.h"
#endif
#include <zlib.h>
typedef struct chunk_insert
{
   struct chunk_insert *next;
   void               (*insert)(png_structp, png_infop, int, png_charpp);
   int                  nparams;
   png_charp            parameters[1];
} chunk_insert;
#              define interp(pos, c1, c2) ((pos * c1) + ((size-pos) * c2))
#              define xyinterp(x, y, c1, c2, c3, c4) (((size * size / 2) +\
#        ifdef PNG_WRITE_INTERLACING_SUPPORTED
#        else /* !WRITE_INTERLACING */
#        endif /* !WRITE_INTERLACING */
#if 0
#endif
#  define CHUNK(a,b,c,d) (((a)<<24)+((b)<<16)+((c)<<8)+(d))
#if 0
#endif
