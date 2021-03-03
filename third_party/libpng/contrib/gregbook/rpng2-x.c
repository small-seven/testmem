#define PROGNAME  "rpng2-x"
#define LONGNAME  "Progressive PNG Viewer for X"
#define VERSION   "2.04 of 15 June 2014"
#define RESNAME   "rpng2"       /* our X resource application name */
#define RESCLASS  "Rpng"       /* our X resource class name */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <setjmp.h>       /* for jmpbuf declaration in readpng2.h */
#include <time.h>
#include <math.h>         /* only for PvdM background code */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/keysym.h>   /* defines XK_* macros */
#if _POSIX_C_SOURCE >= 199309L /* have nanosleep() */
# undef usleep
# define usleep(usec) {        \
#  endif
#ifndef usleep /* have neither nanosleep() nor usleep() */
#  define usleep(x) sleep(((x)+499999)/1000000)
#endif
#ifdef VMS
#  include <unistd.h>
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
#define QUIT(e,k) ((e.type == ButtonPress && e.xbutton.button == Button1) ||  \
#define NO_24BIT_MASKS /* undef case not fully written--only for redisplay() */
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
#ifdef FEATURE_LOOP
#endif
#ifdef sgi
#endif
#ifdef FEATURE_LOOP
#endif
#if defined(NeXT)
#elif defined(sgi)
#elif defined(Macintosh)
#else
#endif
#ifdef FEATURE_LOOP
#endif
#ifdef FEATURE_LOOP
#endif
#ifdef FEATURE_LOOP
#endif
#ifdef FEATURE_LOOP
#endif /* FEATURE_LOOP */
#ifdef DEBUG
#endif
#ifdef NO_24BIT_MASKS
#else
#endif
#ifdef NO_24BIT_MASKS
#else
#endif
#ifdef FEATURE_LOOP
#endif /* FEATURE_LOOP */
