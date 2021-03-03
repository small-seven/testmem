#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "libavcodec/internal.h"
#include "libavcodec/bytestream.h"
#include "libavutil/opt.h"
#include "libavutil/dict.h"
#include "libavutil/pixdesc.h"
#include "libavutil/timestamp.h"
#include "metadata.h"
#include "id3v2.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/internal.h"
#include "libavutil/mathematics.h"
#include "libavutil/parseutils.h"
#include "libavutil/time.h"
#include "riff.h"
#include "audiointerleave.h"
#include "url.h"
#include <stdarg.h>
#if CONFIG_NETWORK
#include "network.h"
#endif
#if FF_API_FORMAT_FILENAME
#endif
#if FF_API_FORMAT_FILENAME
#else
#endif
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_AVCTX
#endif
#define AV_PKT_FLAG_UNCODED_FRAME 0x2000
#define UNCODED_FRAME_PACKET_SIZE (INT_MIN / 3 * 2 + (int)sizeof(AVFrame))
#if FF_API_COMPUTE_PKT_FIELDS2 && FF_API_LAVF_AVCTX
#endif
#if !FF_API_COMPUTE_PKT_FIELDS2 || !FF_API_LAVF_AVCTX
#endif
#if FF_API_COMPUTE_PKT_FIELDS2 && FF_API_LAVF_AVCTX
#endif
#define CHUNK_START 0x1000
#if FF_API_COMPUTE_PKT_FIELDS2 && FF_API_LAVF_AVCTX
#endif
