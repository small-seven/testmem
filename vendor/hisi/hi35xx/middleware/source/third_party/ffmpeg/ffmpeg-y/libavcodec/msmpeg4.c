#include "avcodec.h"
#include "idctdsp.h"
#include "mpegvideo.h"
#include "msmpeg4.h"
#include "libavutil/x86/asm.h"
#include "h263.h"
#include "mpeg4video.h"
#include "msmpeg4data.h"
#include "mpegvideodata.h"
#include "vc1data.h"
#include "libavutil/imgutils.h"
#if CONFIG_VC1_DECODER
#endif
#if ARCH_X86 && HAVE_7REGS && HAVE_EBX_AVAILABLE
#else
#endif
