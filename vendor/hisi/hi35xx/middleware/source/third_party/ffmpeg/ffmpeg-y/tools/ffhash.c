#include "config.h"
#include "libavutil/avstring.h"
#include "libavutil/error.h"
#include "libavutil/hash.h"
#include "libavutil/mem.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#if HAVE_IO_H
#include <io.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#define SIZE 65536
#ifdef O_BINARY
#endif
