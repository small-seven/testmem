#include "config.h"
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <stdatomic.h>
#include <stdint.h>
#if HAVE_IO_H
#include <io.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include "libavformat/avformat.h"
#include "libavdevice/avdevice.h"
#include "libswresample/swresample.h"
#include "libavutil/opt.h"
#include "libavutil/channel_layout.h"
#include "libavutil/parseutils.h"
#include "libavutil/samplefmt.h"
#include "libavutil/fifo.h"
#include "libavutil/hwcontext.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/dict.h"
#include "libavutil/display.h"
#include "libavutil/mathematics.h"
#include "libavutil/pixdesc.h"
#include "libavutil/avstring.h"
#include "libavutil/libm.h"
#include "libavutil/imgutils.h"
#include "libavutil/timestamp.h"
#include "libavutil/bprint.h"
#include "libavutil/time.h"
#include "libavutil/thread.h"
#include "libavutil/threadmessage.h"
#include "libavcodec/mathops.h"
#include "libavformat/os_support.h"
# include "libavfilter/avfilter.h"
# include "libavfilter/buffersrc.h"
# include "libavfilter/buffersink.h"
#if HAVE_SYS_RESOURCE_H
#include <sys/time.h>
#include <sys/types.h>
#include <sys/resource.h>
#elif HAVE_GETPROCESSTIMES
#include <windows.h>
#endif
#if HAVE_GETPROCESSMEMORYINFO
#include <windows.h>
#include <psapi.h>
#endif
#if HAVE_SETCONSOLECTRLHANDLER
#include <windows.h>
#endif
#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif
#if HAVE_TERMIOS_H
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <termios.h>
#elif HAVE_KBHIT
#include <conio.h>
#endif
#include <time.h>
#include "ffmpeg.h"
#include "cmdutils.h"
#include "libavutil/avassert.h"
typedef struct BenchmarkTimeStamps {
    int64_t real_usec;
    int64_t user_usec;
    int64_t sys_usec;
} BenchmarkTimeStamps;
#if HAVE_TERMIOS_H
#endif
#if HAVE_THREADS
#endif
#if HAVE_TERMIOS_H
#endif
#if HAVE_SETCONSOLECTRLHANDLER
#endif
#if HAVE_TERMIOS_H
#endif
#ifdef SIGXCPU
#endif
#ifdef SIGPIPE
#endif
#if HAVE_SETCONSOLECTRLHANDLER
#endif
#if HAVE_TERMIOS_H
#elif HAVE_KBHIT
#    if HAVE_PEEKNAMEDPIPE
#    endif
#endif
#if HAVE_THREADS
#endif
#if HAVE_TERMIOS_H
#endif
#if FF_API_DEBUG_MV
#endif
#if HAVE_THREADS
#endif
#if HAVE_THREADS
#endif
#if HAVE_THREADS
#endif
#if HAVE_THREADS
#endif
#if HAVE_THREADS
#endif
#if HAVE_THREADS
#endif
#if HAVE_THREADS
#endif
#if HAVE_GETRUSAGE
#elif HAVE_GETPROCESSTIMES
#else
#endif
#if HAVE_GETRUSAGE && HAVE_STRUCT_RUSAGE_RU_MAXRSS
#elif HAVE_GETPROCESSMEMORYINFO
#else
#endif
#if CONFIG_AVDEVICE
#endif
