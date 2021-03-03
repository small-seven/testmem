#include "config.h"
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_IO_H
#include <io.h>
#endif
#include "libavutil/avstring.h"
#include "libavutil/time.h"
#include "libavformat/avformat.h"
#define FILENAME_BUF_SIZE 4096
#define PKTFILESUFF "_%08" PRId64 "_%02d_%010" PRId64 "_%06d_%c.bin"
