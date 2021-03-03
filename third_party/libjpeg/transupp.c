#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#include "transupp.h"		/* My own external interface */
#include <ctype.h>		/* to declare isdigit() */
#if TRANSFORMS_SUPPORTED
#ifndef DROP_REQUEST_FROM_SRC
#define DROP_REQUEST_FROM_SRC 1		/* 0 disables adaptation */
#endif
#if DROP_REQUEST_FROM_SRC
#endif /* DROP_REQUEST_FROM_SRC */
#ifdef FAST_DIVIDE
#define DIVIDE_BY(a,b)	a /= b
#else
#define DIVIDE_BY(a,b)	if (a >= b) a /= b; else a = 0
#endif
#if DROP_REQUEST_FROM_SRC
#else
#endif
#if DROP_REQUEST_FROM_SRC
#endif
#endif /* TRANSFORMS_SUPPORTED */
#ifdef SAVE_MARKERS_SUPPORTED
#endif /* SAVE_MARKERS_SUPPORTED */
#ifdef NEED_FAR_POINTERS
#else
#endif
