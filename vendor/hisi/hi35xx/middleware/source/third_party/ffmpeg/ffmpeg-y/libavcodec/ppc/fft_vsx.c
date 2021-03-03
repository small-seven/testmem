#include "config.h"
#include "libavutil/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/fft.h"
#include "libavcodec/fft-internal.h"
#include "fft_vsx.h"
#if HAVE_VSX
#endif /* HAVE_VSX */
