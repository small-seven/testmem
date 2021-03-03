#define PROGNAME  "rpng-win"
#define LONGNAME  "Simple PNG Viewer for Windows"
#define VERSION   "2.01 of 16 March 2008"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#ifdef __CYGWIN__
#include <unistd.h>
#include <termio.h>
#include <sys/ioctl.h>
#define _getch repl_getch
#else
#include <conio.h>      /* only for _getch() */
#endif
#include "readpng.h"    /* typedefs, common macros, readpng prototypes */
#include "readpng.h"    /* typedefs, common macros, readpng prototypes */


/* could just include png.h, but this macro is the only thing we need
 * (name and typedefs changed to local versions); note that side effects
 * only happen with alpha (which could easily be avoided with
 * "ush acopy = (alpha);") */

#define alpha_composite(composite, fg, alpha, bg) {               \
    ush temp = ((ush)(fg)*(ush)(alpha) +                          \
                (ush)(bg)*(ush)(255 - (ush)(alpha)) + (ush)128);  \
    (composite) = (uch)((temp + (temp >> 8)) >> 8);               \
}
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
