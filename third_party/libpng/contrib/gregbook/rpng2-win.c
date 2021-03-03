#define PROGNAME  "rpng2-win"
#define LONGNAME  "Progressive PNG Viewer for Windows"
#define VERSION   "2.02 of 16 March 2008"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>    /* for jmpbuf declaration in readpng2.h */
#include <time.h>
#include <math.h>      /* only for PvdM background code */
#include <windows.h>
#ifdef __CYGWIN__
#include <unistd.h>
#include <termio.h>
#include <sys/ioctl.h>
#define _getch repl_getch
#else
#include <conio.h>     /* only for _getch() */
#endif
#ifndef PI
#  define PI             3.141592653589793238
#endif
#define PI_2             (PI*0.5)
#define INV_PI_360       (360.0 / PI)
#define MAX(a,b)         (a>b?a:b)
#define MIN(a,b)         (a<b?a:b)
#define CLIP(a,min,max)  MAX(min,MIN((a),max))
#define ABS(a)           ((a)<0?-(a):(a))
#define CLIP8P(c)        MAX(0,(MIN((c),255)))   /* 8-bit pos. integer (uch) */
#define ROUNDF(f)        ((int)(f + 0.5))
#define rgb1_max   bg_freq
#define rgb1_min   bg_gray
#define rgb2_max   bg_bsat
#define rgb2_min   bg_brot
#include "readpng2.h"   /* typedefs, common macros, readpng2 prototypes */
#include "readpng2.h"   /* typedefs, common macros, readpng2 prototypes */


/* could just include png.h, but this macro is the only thing we need
 * (name and typedefs changed to local versions); note that side effects
 * only happen with alpha (which could easily be avoided with
 * "ush acopy = (alpha);") */

#define alpha_composite(composite, fg, alpha, bg) {               \
    ush temp = ((ush)(fg)*(ush)(alpha) +                          \
                (ush)(bg)*(ush)(255 - (ush)(alpha)) + (ush)128);  \
    (composite) = (uch)((temp + (temp >> 8)) >> 8);               \
}
#define INBUFSIZE 4096   /* with pseudo-timing on (1 sec delay/block), this
#ifndef __CYGWIN__
#endif
#if defined(NeXT)
#elif defined(sgi)
#elif defined(Macintosh)
#else
#endif
#ifndef __CYGWIN__
#endif
#ifndef __CYGWIN__
#else
#endif
#if (defined(__i386__) || defined(_M_IX86) || defined(__x86_64__)) && \
#endif
#ifndef __CYGWIN__
#endif
#ifndef __CYGWIN__
#endif
#ifndef __CYGWIN__
#endif
#ifndef __CYGWIN__
#endif
#ifndef __CYGWIN__
#else
#endif
