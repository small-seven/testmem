#include "config.h"
#if HAVE_UNISTD_H
#include <unistd.h>             /* getopt */
#endif
#include "libavutil/pixdesc.h"
#include "libavcodec/avcodec.h"
#include "libavutil/common.h"
#include "libavcodec/raw.h"
#undef printf
#undef fprintf
#if !HAVE_GETOPT
#include "compat/getopt.c"
#endif
