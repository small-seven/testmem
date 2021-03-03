#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#include "jmemsys.h"		/* import the system-dependent declarations */
#ifndef HAVE_STDLIB_H		/* <stdlib.h> should declare malloc(),free() */
#endif
#ifndef SEEK_SET		/* pre-ANSI systems may not define this; */
#define SEEK_SET  0		/* if not, assume 0 is correct */
#endif
#ifdef DONT_USE_B_MODE		/* define mode parameters for fopen() */
#define READ_BINARY	"r"
#define RW_BINARY	"w+"
#else
#ifdef VMS			/* VMS is very nonstandard */
#define READ_BINARY	"rb", "ctx=stm"
#define RW_BINARY	"w+b", "ctx=stm"
#else				/* standard ANSI-compliant case */
#define READ_BINARY	"rb"
#define RW_BINARY	"w+b"
#endif
#endif
#ifndef TEMP_DIRECTORY		/* can override from jconfig.h or Makefile */
#define TEMP_DIRECTORY  "/usr/tmp/" /* recommended setting for Unix */
#endif
#ifdef NO_MKTEMP
#ifndef TEMP_FILE_NAME		/* can override from jconfig.h or Makefile */
#define TEMP_FILE_NAME  "%sJPG%03d.TMP"
#endif
#ifndef NO_ERRNO_H
#include <errno.h>		/* to define ENOENT */
#endif
#ifndef errno
#endif
#ifdef ENOENT
#endif
#else /* ! NO_MKTEMP */
#ifndef TEMP_FILE_NAME		/* can override from jconfig.h or Makefile */
#define TEMP_FILE_NAME  "%sJPG%dXXXXXX"
#endif
#endif /* NO_MKTEMP */
#ifndef DEFAULT_MAX_MEM		/* so can override from makefile */
#define DEFAULT_MAX_MEM		1000000L /* default: one megabyte */
#endif
