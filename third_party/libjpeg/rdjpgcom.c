#define JPEG_CJPEG_DJPEG	/* to get the command-line config symbols */
#include "jinclude.h"		/* get auto-config symbols, <stdio.h> */
#ifdef HAVE_LOCALE_H
#include <locale.h>		/* Bill Allombert: use locale for isprint */
#endif
#include <ctype.h>		/* to declare isupper(), tolower() */
#ifdef USE_SETMODE
#include <fcntl.h>		/* to declare setmode()'s parameter macros */
#include <io.h>			/* to declare setmode() */
#endif
#ifdef USE_CCOMMAND		/* command-line reader for Macintosh */
#ifdef __MWERKS__
#include <SIOUX.h>              /* Metrowerks needs this */
#include <console.h>		/* ... and this */
#endif
#ifdef THINK_C
#include <console.h>		/* Think declares it here */
#endif
#endif
#ifdef DONT_USE_B_MODE		/* define mode parameters for fopen() */
#define READ_BINARY	"r"
#else
#ifdef VMS			/* VMS is very nonstandard */
#define READ_BINARY	"rb", "ctx=stm"
#else				/* standard ANSI-compliant case */
#define READ_BINARY	"rb"
#endif
#endif
#ifndef EXIT_FAILURE		/* define exit() codes if not provided */
#define EXIT_FAILURE  1
#endif
#ifndef EXIT_SUCCESS
#ifdef VMS
#define EXIT_SUCCESS  1		/* VMS is very nonstandard */
#else
#define EXIT_SUCCESS  0
#endif
#endif
#define NEXTBYTE()  getc(infile)
#define ERREXIT(msg)  (fprintf(stderr, "%s\n", msg), exit(EXIT_FAILURE))
#define M_SOF0  0xC0		/* Start Of Frame N */
#define M_SOF1  0xC1		/* N indicates which compression process */
#define M_SOF2  0xC2		/* Only SOF0-SOF2 are now in common use */
#define M_SOF3  0xC3
#define M_SOF5  0xC5		/* NB: codes C4 and CC are NOT SOF markers */
#define M_SOF6  0xC6
#define M_SOF7  0xC7
#define M_SOF9  0xC9
#define M_SOF10 0xCA
#define M_SOF11 0xCB
#define M_SOF13 0xCD
#define M_SOF14 0xCE
#define M_SOF15 0xCF
#define M_SOI   0xD8		/* Start Of Image (beginning of datastream) */
#define M_EOI   0xD9		/* End Of Image (end of datastream) */
#define M_SOS   0xDA		/* Start Of Scan (begins compressed data) */
#define M_APP0	0xE0		/* Application-specific marker, type N */
#define M_APP12	0xEC		/* (we don't bother to list all 16 APPn's) */
#define M_COM   0xFE		/* COMment */
#ifdef HAVE_LOCALE_H
#endif
#ifdef HAVE_LOCALE_H
#endif
#ifdef USE_CCOMMAND
#endif
#ifdef USE_SETMODE		/* need to hack file mode? */
#endif
#ifdef USE_FDOPEN		/* need to re-open in binary mode? */
#else
#endif
