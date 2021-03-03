#include "avcodec.h"
#include "get_bits.h"
#include "bytestream.h"
#include "adpcm.h"
#include "adpcm_data.h"
#include "internal.h"
typedef struct ADPCMDecodeContext {
    ADPCMChannelStatus status[14];
    int vqa_version;                /**< VQA version. Used for ADPCM_IMA_WS */
    int has_status;
} ADPCMDecodeContext;
#define DK3_GET_NEXT_NIBBLE() \
#define THP_GET16(g) \
#define ADPCM_DECODER(id_, sample_fmts_, name_, long_name_) \
