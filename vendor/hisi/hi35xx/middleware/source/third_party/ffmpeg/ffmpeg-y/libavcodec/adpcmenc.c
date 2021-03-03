#include "avcodec.h"
#include "put_bits.h"
#include "bytestream.h"
#include "adpcm.h"
#include "adpcm_data.h"
#include "internal.h"
typedef struct TrellisPath {
    int nibble;
    int prev;
} TrellisPath;
typedef struct TrellisNode {
    uint32_t ssd;
    int path;
    int sample1;
    int sample2;
    int step;
} TrellisNode;
typedef struct ADPCMEncodeContext {
    ADPCMChannelStatus status[6];
    TrellisPath *paths;
    TrellisNode *node_buf;
    TrellisNode **nodep_buf;
    uint8_t *trellis_hash;
} ADPCMEncodeContext;
#define FREEZE_INTERVAL 128
#define STORE_NODE(NAME, STEP_INDEX)\
#define LOOP_NODES(NAME, STEP_TABLE, STEP_INDEX)\
#undef LOOP_NODES
#undef STORE_NODE
#define ADPCM_ENCODER(id_, name_, sample_fmts_, long_name_) \
