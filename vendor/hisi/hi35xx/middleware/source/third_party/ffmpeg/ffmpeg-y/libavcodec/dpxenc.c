#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "internal.h"
typedef struct DPXContext {
    int big_endian;
    int bits_per_component;
    int num_components;
    int descriptor;
    int planar;
} DPXContext;
#define write16(p, value) write16_internal(s->big_endian, p, value)
#define write32(p, value) write32_internal(s->big_endian, p, value)
#define HEADER_SIZE 1664  /* DPX Generic header */
