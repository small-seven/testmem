#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/hash.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
#define OFFSET(x) offsetof(struct HashContext, x)
#define ENC AV_OPT_FLAG_ENCODING_PARAM
#if CONFIG_HASH_MUXER || CONFIG_FRAMEHASH_MUXER
#endif
#if CONFIG_MD5_MUXER || CONFIG_FRAMEMD5_MUXER
#endif
#if CONFIG_HASH_MUXER || CONFIG_MD5_MUXER
#endif
#if CONFIG_HASH_MUXER
#endif
#if CONFIG_MD5_MUXER
#endif
#if CONFIG_FRAMEHASH_MUXER || CONFIG_FRAMEMD5_MUXER
#endif
#if CONFIG_FRAMEHASH_MUXER
#endif
#if CONFIG_FRAMEMD5_MUXER
#endif
