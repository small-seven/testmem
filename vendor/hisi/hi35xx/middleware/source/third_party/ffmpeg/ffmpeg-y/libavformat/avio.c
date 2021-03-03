#include "libavutil/avstring.h"
#include "libavutil/dict.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavutil/avassert.h"
#include "os_support.h"
#include "avformat.h"
#if CONFIG_NETWORK
#include "network.h"
#endif
#include "url.h"
#define OFFSET(x) offsetof(URLContext,x)
#define E AV_OPT_FLAG_ENCODING_PARAM
#define D AV_OPT_FLAG_DECODING_PARAM
#if CONFIG_NETWORK
#endif
#if CONFIG_NETWORK
#endif
#define URL_SCHEME_CHARS                        \
#if CONFIG_NETWORK
#endif
