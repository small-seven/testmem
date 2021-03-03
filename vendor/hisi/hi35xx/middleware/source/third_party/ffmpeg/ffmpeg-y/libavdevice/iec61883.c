#include <poll.h>
#include <libraw1394/raw1394.h>
#include <libavc1394/avc1394.h>
#include <libavc1394/rom1394.h>
#include <libiec61883/iec61883.h>
#include "libavformat/dv.h"
#include "libavformat/mpegts.h"
#include "libavutil/opt.h"
#include "avdevice.h"
#define THREADS HAVE_PTHREADS
#if THREADS
#include <pthread.h>
#endif
#define MOTDCT_SPEC_ID      0x00005068
#define IEC61883_AUTO       0
#define IEC61883_DV         1
#define IEC61883_HDV        2
typedef struct DVPacket {
    uint8_t *buf;                       ///< actual buffer data
    int len;                            ///< size of buffer allocated
    struct DVPacket *next;              ///< next DVPacket
} DVPacket;
#if THREADS
#endif
#if THREADS
#endif
#if THREADS
#endif
#if THREADS
#endif
#if THREADS
#else
#endif
#if THREADS
#endif
#if THREADS
#else
#endif
#if THREADS
#endif
