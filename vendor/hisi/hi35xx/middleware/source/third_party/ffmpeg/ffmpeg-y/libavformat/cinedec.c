#include "libavutil/intreadwrite.h"
#include "libavcodec/bmp.h"
#include "libavutil/intfloat.h"
#include "avformat.h"
#include "internal.h"
typedef struct {
    uint64_t pts;
} CineDemuxContext;
#define CFA_TLGRAY  0x80000000U
#define CFA_TRGRAY  0x40000000U
#define CFA_BLGRAY  0x20000000U
#define CFA_BRGRAY  0x10000000U
#define DESCRIPTION_SIZE 4096
