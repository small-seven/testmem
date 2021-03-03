#include <inttypes.h>
#include "avcodec.h"
#define FRAC_BITS 14
#include "mathops.h"
#include "lsp.h"
#include "libavcodec/mips/lsp_mips.h"
#include "libavutil/avassert.h"
#ifdef G729_BITEXACT
#else
#endif
#ifndef ff_lsp2polyf
#endif /* ff_lsp2polyf */
