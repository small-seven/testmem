#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#if 0				/* This table is not actually needed in v6a */
#endif
#ifndef NEED_FAR_POINTERS	/* normal case, same as regular macro */
#define FMEMCOPY(dest,src,size)	MEMCOPY(dest,src,size)
#else				/* 80x86 case, define if we can */
#ifdef USE_FMEM
#define FMEMCOPY(dest,src,size)	_fmemcpy((void FAR *)(dest), (const void FAR *)(src), (size_t)(size))
#else
#endif
#endif
#ifdef FMEMCOPY
#else
#endif
#ifdef FMEMCOPY
#else
#endif
#ifdef FMEMCOPY
#else
#endif
