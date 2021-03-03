#include <stdint.h>
#include "ffmpeg.h"
#include "cmdutils.h"
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libavfilter/avfilter.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/avutil.h"
#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/fifo.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/pixfmt.h"
#define DEFAULT_PASS_LOGFILENAME_PREFIX "ffmpeg2pass"
#define MATCH_PER_STREAM_OPT(name, type, outvar, fmtctx, st)\
#define MATCH_PER_TYPE_OPT(name, type, outvar, fmtctx, mediatype)\
#if CONFIG_VIDEOTOOLBOX
#endif
#if CONFIG_LIBMFX
#endif
#if CONFIG_CUVID
#endif
#if CONFIG_VAAPI
#endif
#define METADATA_CHECK_INDEX(index, nb_elems, desc)\
#define SET_DICT(type, meta, context, index)\
#if FF_API_LOWRES
#endif
#if HAVE_THREADS
#endif
#if FF_API_LAVF_AVCTX
#endif
#if CONFIG_SWSCALE
#endif
#if CONFIG_SWRESAMPLE
#endif
#define OFFSET(x) offsetof(OptionsContext, x)
#if CONFIG_VIDEOTOOLBOX
#endif
#if CONFIG_VAAPI
#endif
#if CONFIG_QSV
#endif
