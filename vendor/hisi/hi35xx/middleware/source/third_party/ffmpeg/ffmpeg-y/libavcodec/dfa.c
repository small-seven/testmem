#include <inttypes.h>
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/mem.h"
typedef struct DfaContext {
    uint32_t pal[256];
    uint8_t *frame_buf;
} DfaContext;
typedef int (*chunk_decoder)(GetByteContext *gb, uint8_t *frame, int width, int height);

static const chunk_decoder decoder[8] = {
    decode_copy, decode_tsw1, decode_bdlt, decode_wdlt,
    decode_tdlt, decode_dsw1, decode_blck, decode_dds1,
};
