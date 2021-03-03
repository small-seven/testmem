#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include "config.h"
#include "compat/va_copy.h"
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"
#include "libavdevice/avdevice.h"
#include "libavresample/avresample.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"
#include "libpostproc/postprocess.h"
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/display.h"
#include "libavutil/mathematics.h"
#include "libavutil/imgutils.h"
#include "libavutil/libm.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/eval.h"
#include "libavutil/dict.h"
#include "libavutil/opt.h"
#include "libavutil/cpu.h"
#include "libavutil/ffversion.h"
#include "libavutil/version.h"
#include "cmdutils.h"
#if CONFIG_NETWORK
#include "libavformat/network.h"
#endif
#if HAVE_SYS_RESOURCE_H
#include <sys/time.h>
#include <sys/resource.h>
#endif
#ifdef _WIN32
#include <windows.h>
#endif
#ifdef _WIN32
#endif
#if HAVE_COMMANDLINETOARGVW && defined(_WIN32)
#include <shellapi.h>
#else
#endif /* HAVE_COMMANDLINETOARGVW */
#define FLAGS (o->type == AV_OPT_TYPE_FLAGS && (arg[0]=='-' || arg[0]=='+')) ? AV_DICT_APPEND : 0
#if CONFIG_AVRESAMPLE
#endif
#if CONFIG_SWSCALE
#endif
#if CONFIG_SWRESAMPLE
#endif
#if CONFIG_SWSCALE
#else
#endif
#if CONFIG_SWRESAMPLE
#endif
#if CONFIG_AVRESAMPLE
#endif
#define GET_ARG(arg)                                                           \
#if HAVE_SETRLIMIT
#else
#endif
#define INDENT        1
#define SHOW_VERSION  2
#define SHOW_CONFIG   4
#define SHOW_COPYRIGHT 8
#define PRINT_LIB_INFO(libname, LIBNAME, flags, level)                  \
#if CONFIG_NONFREE
#elif CONFIG_GPLV3
#elif CONFIG_GPL
#elif CONFIG_LGPLV3
#else
#endif
#define PRINT_CODEC_SUPPORTED(codec, field, type, list_name, term, get_name) \
#if CONFIG_AVFILTER
#else
#endif
#if !CONFIG_SWSCALE
#   define sws_isSupportedInput(x)  0
#   define sws_isSupportedOutput(x) 0
#endif
#if CONFIG_AVFILTER
#if CONFIG_AVFILTER
#else
#endif
#endif
#if CONFIG_AVFILTER
#endif
#ifdef _WIN32
#endif
#if CONFIG_AVDEVICE
#endif
