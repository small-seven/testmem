#include "libavutil/opt.h"
#include "libavutil/avstring.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/crc.h"
#include "libavutil/dict.h"
#include "libavutil/mathematics.h"
#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
#include "id3v2.h"
#include "id3v1.h"
#include "replaygain.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/mpegaudiodecheader.h"
#define XING_FLAG_FRAMES 0x01
#define XING_FLAG_SIZE   0x02
#define XING_FLAG_TOC    0x04
#define XING_FLAC_QSCALE 0x08
#define XING_TOC_COUNT 100
#define SAME_HEADER_MASK \
typedef struct {
    AVClass *class;
    int64_t filesize;
    int xing_toc;
    int start_pad;
    int end_pad;
    int usetoc;
    unsigned frames; /* Total number of frames in file */
    unsigned header_filesize;   /* Total number of bytes in the stream */
    int is_cbr;
} MP3DecContext;
#define LAST_BITS(k, n) ((k) & ((1 << (n)) - 1))
#define MIDDLE_BITS(k, m, n) LAST_BITS((k) >> (m), ((n) - (m) + 1))
#define MP3_PACKET_SIZE 1024
#define SEEK_WINDOW 4096
#define MIN_VALID 3
