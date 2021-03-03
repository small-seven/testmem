#define PROGNAME  "wpng"
#define VERSION   "2.00 of 2 June 2007"
#define APPNAME   "Simple PGM/PPM/PAM to PNG Converter"
#if defined(__MSDOS__) || defined(__OS2__)
#  define DOS_OS2_W32
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#  ifndef __GNUC__   /* treat Win32 native ports of gcc as Unix environments */
#    define DOS_OS2_W32
#  endif
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>     /* for jmpbuf declaration in writepng.h */
#include <time.h>
#ifdef DOS_OS2_W32
#  include <io.h>       /* for isatty(), setmode() prototypes */
#  include <fcntl.h>    /* O_BINARY for fdopen() without text translation */
#  ifdef __EMX__
#    ifndef getch
#      define getch() _read_kbd(0, 1, 0)    /* need getche() */
#    endif
#  else /* !__EMX__ */
#    ifdef __GO32__
#      include <pc.h>
#      define getch() getkey()  /* GRR:  need getche() */
#    else
#      include <conio.h>        /* for getche() console input */
#    endif
#  endif /* ?__EMX__ */
#  define FGETS(buf,len,stream)  dos_kbd_gets(buf,len)
#else
#  include <unistd.h>           /* for isatty() prototype */
#  define FGETS fgets
#endif
#include "writepng.h"   /* typedefs, common macros, writepng prototypes */
#include "writepng.h"   /* typedefs, common macros, writepng prototypes */



/* local prototypes */

static int  wpng_isvalid_latin1(uch *p, int len);
static void wpng_cleanup(void);

#ifdef DOS_OS2_W32
   static char *dos_kbd_gets(char *buf, int len);
#endif



static mainprog_info wpng_info;   /* lone global */



int main(int argc, char **argv)
{
#ifndef DOS_OS2_W32
    FILE *keybd;
#endif
#ifdef sgi
    FILE *tmpfile;      /* or we could just use keybd, since no overlap */
    char tmpline[80];
#endif
    char *inname = NULL, outname[256];
    char *p, pnmchar, pnmline[256];
    char *bgstr, *textbuf = NULL;
    ulg rowbytes;
    int rc, len = 0;
    int error = 0;
    int text = FALSE;
    int maxval;
    double LUT_exponent;                /* just the lookup table */
    double CRT_exponent = 2.2;          /* just the monitor */
    double default_display_exponent;    /* whole display system */
    double default_gamma = 0.0;


    wpng_info.infile = NULL;
    wpng_info.outfile = NULL;
    wpng_info.image_data = NULL;
    wpng_info.row_pointers = NULL;
    wpng_info.filter = FALSE;
    wpng_info.interlaced = FALSE;
    wpng_info.have_bg = FALSE;
    wpng_info.have_time = FALSE;
    wpng_info.have_text = 0;
    wpng_info.gamma = 0.0;


    /* First get the default value for our display-system exponent, i.e.,
     * the product of the CRT exponent and the exponent corresponding to
     * the frame-buffer's lookup table (LUT), if any.  If the PNM image
     * looks correct on the user's display system, its file gamma is the
     * inverse of this value.  (Note that this is not an exhaustive list
     * of LUT values--e.g., OpenStep has a lot of weird ones--but it should
     * cover 99% of the current possibilities.  This section must ensure
     * that default_display_exponent is positive.) */

#if defined(NeXT)
    /* third-party utilities can modify the default LUT exponent */
    LUT_exponent = 1.0 / 2.2;
    /*
    if (some_next_function_that_returns_gamma(&next_gamma))
        LUT_exponent = 1.0 / next_gamma;
     */
#elif defined(sgi)
    LUT_exponent = 1.0 / 1.7;
    /* there doesn't seem to be any documented function to
     * get the "gamma" value, so we do it the hard way */
    tmpfile = fopen("/etc/config/system.glGammaVal", "r");
    if (tmpfile) {
        double sgi_gamma;

        fgets(tmpline, 80, tmpfile);
        fclose(tmpfile);
        sgi_gamma = atof(tmpline);
        if (sgi_gamma > 0.0)
            LUT_exponent = 1.0 / sgi_gamma;
    }
#elif defined(Macintosh)
#else
#endif
#ifdef DOS_OS2_W32
#endif
#ifndef DOS_OS2_W32
#endif
#ifdef FORBID_LATIN1_CTRL
#else
#endif
#ifdef FORBID_LATIN1_CTRL
#else
#endif
#ifdef FORBID_LATIN1_CTRL
#else
#endif
#ifdef FORBID_LATIN1_CTRL
#else
#endif
#ifdef FORBID_LATIN1_CTRL
#else
#endif
#ifdef FORBID_LATIN1_CTRL
#else
#endif
#ifndef DOS_OS2_W32
#endif
#ifdef DOS_OS2_W32
#endif /* DOS_OS2_W32 */
