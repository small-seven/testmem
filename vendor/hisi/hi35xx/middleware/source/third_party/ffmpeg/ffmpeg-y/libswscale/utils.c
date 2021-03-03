#include "config.h"
#define _DEFAULT_SOURCE
#define _SVID_SOURCE // needed for MAP_ANONYMOUS
#define _DARWIN_C_SOURCE // needed for MAP_ANON
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#if HAVE_MMAP
#include <sys/mman.h>
#if defined(MAP_ANON) && !defined(MAP_ANONYMOUS)
#define MAP_ANONYMOUS MAP_ANON
#endif
#endif
#if HAVE_VIRTUALALLOC
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/avutil.h"
#include "libavutil/bswap.h"
#include "libavutil/cpu.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/libm.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/aarch64/cpu.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#undef attribute_deprecated
#define attribute_deprecated
#include "rgb2rgb.h"
#include "swscale.h"
#include "swscale_internal.h"
#if !FF_API_SWS_VECTOR
#endif
#define LICENSE_PREFIX "libswscale license: "
typedef struct FormatEntry {
    uint8_t is_supported_in         :1;
    uint8_t is_supported_out        :1;
    uint8_t is_supported_endianness :1;
} FormatEntry;
typedef struct {
    int flag;                   ///< flag associated to the algorithm
    const char *description;    ///< human-readable description
    int size_factor;            ///< size factor used when initing the filters
} ScaleAlgorithm;
#if HAVE_MMAP && HAVE_MPROTECT && defined(MAP_ANONYMOUS)
#define USE_MMAP 1
#else
#define USE_MMAP 0
#endif
#if HAVE_MMXEXT_INLINE
#if USE_MMAP
#elif HAVE_VIRTUALALLOC
#else
#endif
#ifdef MAP_ANONYMOUS
#else
#endif
#if USE_MMAP
#endif
#endif /* HAVE_MMXEXT_INLINE */
#if HAVE_ALTIVEC
#endif
#ifdef DITHER1XBPP
#else
#endif
#if !FF_API_SWS_VECTOR
#endif
#if !FF_API_SWS_VECTOR
#endif
#if FF_API_SWS_VECTOR
#endif
#if FF_API_SWS_VECTOR
#endif
#if !FF_API_SWS_VECTOR
#endif
#if !FF_API_SWS_VECTOR
#endif
#if FF_API_SWS_VECTOR
#endif
#if !FF_API_SWS_VECTOR
#endif
#if HAVE_ALTIVEC
#endif
#if HAVE_MMX_INLINE
#if USE_MMAP
#elif HAVE_VIRTUALALLOC
#else
#endif
#endif /* HAVE_MMX_INLINE */
