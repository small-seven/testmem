#include "config.h"
#include <zmq.h>
#include "libavutil/mem.h"
#include "libavutil/bprint.h"
#if HAVE_UNISTD_H
#include <unistd.h>             /* getopt */
#endif
#if !HAVE_GETOPT
#include "compat/getopt.c"
#endif
