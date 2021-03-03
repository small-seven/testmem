#include "libavutil/avassert.h"
#include "libavutil/crc.h"
#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/timer.h"
#include "avcodec.h"
#include "internal.h"
#include "get_bits.h"
#include "rangecoder.h"
#include "golomb.h"
#include "mathops.h"
#include "ffv1.h"
#define TYPE int16_t
#define RENAME(name) name
#include "ffv1dec_template.c"
#undef TYPE
#undef RENAME
#define TYPE int32_t
#define RENAME(name) name ## 32
#include "ffv1dec_template.c"
#if HAVE_THREADS
#endif
#if HAVE_THREADS
#endif
