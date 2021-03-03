#include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */
#include "jversion.h"		/* for version message */
#include <ctype.h>		/* to declare isprint() */
#ifdef USE_CCOMMAND		/* command-line reader for Macintosh */
#ifdef __MWERKS__
#include <SIOUX.h>              /* Metrowerks needs this */
#include <console.h>		/* ... and this */
#endif
#ifdef THINK_C
#include <console.h>		/* Think declares it here */
#endif
#endif
#define JMESSAGE(code,string)	string ,
#include "cderror.h"
typedef enum {
	FMT_BMP,		/* BMP format (Windows flavor) */
	FMT_GIF,		/* GIF format (LZW compressed) */
	FMT_GIF0,		/* GIF format (uncompressed) */
	FMT_OS2,		/* BMP format (OS/2 flavor) */
	FMT_PPM,		/* PPM/PGM (PBMPLUS formats) */
	FMT_RLE,		/* RLE format */
	FMT_TARGA,		/* Targa format */
	FMT_TIFF		/* TIFF format */
} IMAGE_FORMATS;
#ifndef DEFAULT_FMT		/* so can override from CFLAGS in Makefile */
#define DEFAULT_FMT	FMT_PPM
#endif
#ifdef TWO_FILE_COMMANDLINE
#else
#endif
#ifdef IDCT_SCALING_SUPPORTED
#endif
#ifdef BMP_SUPPORTED
#endif
#ifdef GIF_SUPPORTED
#endif
#ifdef BMP_SUPPORTED
#endif
#ifdef PPM_SUPPORTED
#endif
#ifdef RLE_SUPPORTED
#endif
#ifdef TARGA_SUPPORTED
#endif
#ifdef DCT_ISLOW_SUPPORTED
#endif
#ifdef DCT_IFAST_SUPPORTED
#endif
#ifdef DCT_FLOAT_SUPPORTED
#endif
#ifdef QUANT_2PASS_SUPPORTED
#endif
#ifdef QUANT_1PASS_SUPPORTED
#endif
#ifdef QUANT_2PASS_SUPPORTED	/* otherwise can't quantize to supplied map */
#else
#endif
#ifdef PROGRESS_REPORT
#endif
#ifdef USE_CCOMMAND
#endif
#ifdef NEED_SIGNAL_CATCHER
#endif
#ifdef TWO_FILE_COMMANDLINE
#else
#endif /* TWO_FILE_COMMANDLINE */
#ifdef PROGRESS_REPORT
#endif
#ifdef BMP_SUPPORTED
#endif
#ifdef GIF_SUPPORTED
#endif
#ifdef PPM_SUPPORTED
#endif
#ifdef RLE_SUPPORTED
#endif
#ifdef TARGA_SUPPORTED
#endif
#ifdef PROGRESS_REPORT
#endif
#ifdef PROGRESS_REPORT
#endif
