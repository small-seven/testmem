#include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */
#include "jversion.h"		/* for version message */
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
#ifdef TARGA_SUPPORTED
#else
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
#ifdef TWO_FILE_COMMANDLINE
#else
#endif
#ifdef ENTROPY_OPT_SUPPORTED
#endif
#ifdef C_PROGRESSIVE_SUPPORTED
#endif
#ifdef DCT_SCALING_SUPPORTED
#endif
#ifdef TARGA_SUPPORTED
#endif
#ifdef C_ARITH_CODING_SUPPORTED
#endif
#ifdef DCT_SCALING_SUPPORTED
#endif
#if JPEG_LIB_VERSION_MAJOR >= 9
#endif
#ifdef DCT_ISLOW_SUPPORTED
#endif
#ifdef DCT_IFAST_SUPPORTED
#endif
#ifdef DCT_FLOAT_SUPPORTED
#endif
#ifdef INPUT_SMOOTHING_SUPPORTED
#endif
#ifdef C_MULTISCAN_FILES_SUPPORTED
#endif
#ifdef C_ARITH_CODING_SUPPORTED
#else
#endif
#if defined DCT_SCALING_SUPPORTED && JPEG_LIB_VERSION_MAJOR >= 8 && \
#else
#endif
#if JPEG_LIB_VERSION_MAJOR >= 9
#endif
#if JPEG_LIB_VERSION_MAJOR >= 9 && \
#else
#endif
#ifdef ENTROPY_OPT_SUPPORTED
#else
#endif
#ifdef C_PROGRESSIVE_SUPPORTED
#else
#endif
#ifdef C_MULTISCAN_FILES_SUPPORTED
#else
#endif
#ifdef C_PROGRESSIVE_SUPPORTED
#endif
#ifdef C_MULTISCAN_FILES_SUPPORTED
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
#ifdef PROGRESS_REPORT
#endif
