#include "config.h"
#if HAVE_UNISTD_H
#include <unistd.h>             /* getopt */
#endif
#include "libavutil/log.h"
#include "libavutil/bprint.h"
#if !HAVE_GETOPT
#include "compat/getopt.c"
#endif
