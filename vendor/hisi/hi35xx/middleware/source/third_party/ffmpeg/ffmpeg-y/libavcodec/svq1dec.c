#include "avcodec.h"
#include "get_bits.h"
#include "h263.h"
#include "hpeldsp.h"
#include "internal.h"
#include "mathops.h"
#include "svq1.h"
typedef struct svq1_pmv_s {
    int x;
    int y;
} svq1_pmv;
typedef struct SVQ1Context {
    HpelDSPContext hdsp;
    GetBitContext gb;
    AVFrame *prev;

    uint8_t *pkt_swapped;
    int pkt_swapped_allocated;

    int width;
    int height;
    int frame_code;
    int nonref;         // 1 if the current frame won't be referenced
} SVQ1Context;
#define SVQ1_PROCESS_VECTOR()                                           \
#define SVQ1_ADD_CODEBOOK()                                             \
#define SVQ1_CALC_CODEBOOK_ENTRIES(cbook)                               \
