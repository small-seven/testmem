#include <string.h>
#include "libavutil/avstring.h"
#include "libavutil/base64.h"
#include "libavutil/dict.h"
#include "libavutil/parseutils.h"
#include "libavutil/opt.h"
#include "libavcodec/xiph.h"
#include "libavcodec/mpeg4audio.h"
#include "avformat.h"
#include "internal.h"
#include "avc.h"
#include "hevc.h"
#include "rtp.h"
#if CONFIG_NETWORK
#include "network.h"
#endif
#if CONFIG_RTP_MUXER
#define MAX_EXTRADATA_SIZE ((INT_MAX - 10) / 2)
#if CONFIG_NETWORK
#ifdef AF_INET6
#endif
#else
#endif
#define MAX_PSET_SIZE 1024
#else
#endif
