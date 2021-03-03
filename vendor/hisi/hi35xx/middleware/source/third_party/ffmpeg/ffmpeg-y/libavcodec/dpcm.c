#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "mathops.h"
typedef struct DPCMContext {
    int16_t array[256];
    int sample[2];                  ///< previous sample (for SOL_DPCM)
    const int8_t *sol_table;        ///< delta table for SOL_DPCM
} DPCMContext;
#define DPCM_DECODER(id_, name_, long_name_)                \
