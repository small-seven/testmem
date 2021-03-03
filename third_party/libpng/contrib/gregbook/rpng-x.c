#define PROGNAME  "rpng-x"
#define LONGNAME  "Simple PNG Viewer for X"
#define VERSION   "2.02 of 15 June 2014"
#define RESNAME   "rpng"        /* our X resource application name */
#define RESCLASS  "Rpng"        /* our X resource class name */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/keysym.h>
#include "readpng.h"   /* typedefs, common macros, readpng prototypes */
#include "readpng.h"   /* typedefs, common macros, readpng prototypes */


/* could just include png.h, but this macro is the only thing we need
 * (name and typedefs changed to local versions); note that side effects
 * only happen with alpha (which could easily be avoided with
 * "ush acopy = (alpha);") */

#define alpha_composite(composite, fg, alpha, bg) {               \
    ush temp = ((ush)(fg)*(ush)(alpha) +                          \
                (ush)(bg)*(ush)(255 - (ush)(alpha)) + (ush)128);  \
    (composite) = (uch)((temp + (temp >> 8)) >> 8);               \
}
#ifdef sgi
#endif
#if defined(NeXT)
#elif defined(sgi)
#elif defined(Macintosh)
#else
#endif
#ifdef DEBUG
#endif
#if 0
#else
#endif
#define NO_24BIT_MASKS
#ifdef NO_24BIT_MASKS
#else
#endif
#ifdef NO_24BIT_MASKS
#else
#endif
