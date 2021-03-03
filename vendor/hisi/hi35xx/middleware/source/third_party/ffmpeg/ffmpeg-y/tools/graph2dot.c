#include "config.h"
#if HAVE_UNISTD_H
#include <unistd.h>             /* getopt */
#endif
#include <stdio.h>
#include <string.h>
#include "libavutil/channel_layout.h"
#include "libavutil/mem.h"
#include "libavutil/pixdesc.h"
#include "libavfilter/avfilter.h"
#if !HAVE_GETOPT
#include "compat/getopt.c"
#endif
