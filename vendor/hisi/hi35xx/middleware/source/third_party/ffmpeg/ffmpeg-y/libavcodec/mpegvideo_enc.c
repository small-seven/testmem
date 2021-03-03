#include <stdint.h>
#include "libavutil/internal.h"
#include "libavutil/intmath.h"
#include "libavutil/mathematics.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "libavutil/timer.h"
#include "avcodec.h"
#include "dct.h"
#include "idctdsp.h"
#include "mpeg12.h"
#include "mpegvideo.h"
#include "mpegvideodata.h"
#include "h261.h"
#include "h263.h"
#include "h263data.h"
#include "mjpegenc_common.h"
#include "mathops.h"
#include "mpegutils.h"
#include "mjpegenc.h"
#include "msmpeg4.h"
#include "pixblockdsp.h"
#include "qpeldsp.h"
#include "faandct.h"
#include "thread.h"
#include "aandcttab.h"
#include "flv.h"
#include "mpeg4video.h"
#include "internal.h"
#include "bytestream.h"
#include "wmv2.h"
#include "rv10.h"
#include "libxvid.h"
#include <limits.h>
#include "sp5x.h"
#define QUANT_BIAS_SHIFT 8
#define QMAT_SHIFT_MMX 16
#define QMAT_SHIFT 21
#if CONFIG_FAANDCT
#endif /* CONFIG_FAANDCT */
#define COPY(a) dst->a= src->a
#undef COPY
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_CODED_FRAME
#endif
#if FF_API_ERROR_FRAME
#endif
#if FF_API_STAT_BITS
#endif
#if FF_API_VBV_DELAY
#endif
#if FF_API_STAT_BITS
#endif
#if FF_API_RTP_CALLBACK
#endif
#if FF_API_RTP_CALLBACK
#endif
#define MERGE(field) dst->field += src->field; src->field=0
#ifdef REFINE_STATS
#endif
#ifdef REFINE_STATS
#endif
#ifdef REFINE_STATS
#endif
#ifdef REFINE_STATS
#endif
#ifdef REFINE_STATS
#endif
#ifdef REFINE_STATS
#endif
#ifdef REFINE_STATS
#endif
#ifdef REFINE_STATS
#endif
#ifdef REFINE_STATS
#endif
#ifdef REFINE_STATS
#endif
#ifdef REFINE_STATS
#endif
#ifdef REFINE_STATS
#endif
#ifdef REFINE_STATS
#endif
#ifdef REFINE_STATS
#endif
#define OFFSET(x) offsetof(MpegEncContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
