#include "config.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/md5.h"
#include "libavformat/avformat.h"
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if !HAVE_GETOPT
#include "compat/getopt.c"
#endif
#define HASH_SIZE 16
#define check(value, ...) check_func(value, __LINE__, __VA_ARGS__)
