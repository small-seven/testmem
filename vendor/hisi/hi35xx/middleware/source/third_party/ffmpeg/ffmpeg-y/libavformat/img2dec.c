#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#include <sys/stat.h>
#include "libavutil/avstring.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/parseutils.h"
#include "libavutil/intreadwrite.h"
#include "libavcodec/gif.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "img2.h"
#include "libavcodec/mjpeg.h"
#include "libavcodec/xwd.h"
#include "subtitles.h"
#if HAVE_GLOB
#ifndef GLOB_NOMAGIC
#define GLOB_NOMAGIC 0
#endif
#ifndef GLOB_BRACE
#define GLOB_BRACE 0
#endif
#endif /* HAVE_GLOB */
#if HAVE_GLOB
#else
#endif
#if !HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC
#endif
#if HAVE_GLOB
#endif
#if HAVE_GLOB
#endif
#if HAVE_GLOB
#else
#endif
#if HAVE_GLOB
#endif
#if HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC
#endif
#if HAVE_GLOB
#endif
#define OFFSET(x) offsetof(VideoDemuxData, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
#define COMMON_OPTIONS \
#if CONFIG_IMAGE2_DEMUXER
#endif
#if CONFIG_IMAGE2PIPE_DEMUXER
#endif
#define IMAGEAUTO_DEMUXER(imgname, codecid)\
