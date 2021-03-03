#include "avcodec.h"
#include "bsf.h"
#include "get_bits.h"
#include "mlp_parse.h"
#include "mlp.h"
typedef struct AccessUnit {
    uint8_t bits[4];
    uint16_t offset;
    uint16_t optional;
} AccessUnit;
typedef struct TrueHDCoreContext {
    const AVClass *class;

    MLPHeaderInfo hdr;
} TrueHDCoreContext;
