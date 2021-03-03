#include "config.h"
#if HAVE_UNISTD_H
#include <unistd.h>             /* getopt */
#endif
#include "libavformat/avformat.h"
#include "libavutil/timestamp.h"
#if !HAVE_GETOPT
#include "compat/getopt.c"
#endif
