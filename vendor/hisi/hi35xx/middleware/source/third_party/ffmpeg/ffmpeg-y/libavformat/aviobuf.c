#include "libavutil/bprint.h"
#include "libavutil/crc.h"
#include "libavutil/dict.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/avassert.h"
#include "avformat.h"
#include "avio.h"
#include "avio_internal.h"
#include "internal.h"
#include "url.h"
#include <stdarg.h>
#define IO_BUFFER_SIZE 32768
#define SHORT_SEEK_THRESHOLD 4096
typedef struct AVIOInternal {
    URLContext *h;
} AVIOInternal;
#define OFFSET(x) offsetof(AVIOContext,x)
#define E AV_OPT_FLAG_ENCODING_PARAM
#define D AV_OPT_FLAG_DECODING_PARAM
void avio_context_free(AVIOContext **ps)
{
    av_freep(ps);
}
#define PUT_STR16(type, big_endian)                          \
#undef PUT_STR16
#if FF_API_OLD_AVIO_EOF_0
#else
#endif
#define GET_STR16(type, read) \
#undef GET_STR16
typedef struct DynBuffer {
    int pos, size, allocated_size;
    uint8_t *buffer;
    int io_buffer_size;
    uint8_t io_buffer[1];
} DynBuffer;
