#include <string.h>
#include "libavutil/attributes.h"
#include "libavutil/opt.h"
#include "roqvideo.h"
#include "bytestream.h"
#include "elbg.h"
#include "internal.h"
#include "mathops.h"
#define CHROMA_BIAS 1
#define MAX_CBS_4x4 256
#define MAX_CBS_2x2 256 ///< Maximum number of 2x2 codebooks.
#define ROQ_LAMBDA_SCALE ((uint64_t) FF_LAMBDA_SCALE)
typedef struct SubcelEvaluation {
    int eval_dist[4];
    int best_bit_use;
    int best_coding;

    int subCels[4];
    motion_vect motion;
    int cbEntry;
} SubcelEvaluation;
typedef struct CelEvaluation {
    int eval_dist[4];
    int best_coding;

    SubcelEvaluation subCels[4];

    motion_vect motion;
    int cbEntry;

    int sourceX, sourceY;
} CelEvaluation;
typedef struct RoqCodebooks {
    int numCB4;
    int numCB2;
    int usedCB2[MAX_CBS_2x2];
    int usedCB4[MAX_CBS_4x4];
    uint8_t unpacked_cb2[MAX_CBS_2x2*2*2*3];
    uint8_t unpacked_cb4[MAX_CBS_4x4*4*4*3];
    uint8_t unpacked_cb4_enlarged[MAX_CBS_4x4*8*8*3];
} RoqCodebooks;
typedef struct RoqTempData
{
    CelEvaluation *cel_evals;

    int f2i4[MAX_CBS_4x4];
    int i2f4[MAX_CBS_4x4];
    int f2i2[MAX_CBS_2x2];
    int i2f2[MAX_CBS_2x2];

    int mainChunkSize;

    int numCB4;
    int numCB2;

    RoqCodebooks codebooks;

    int *closest_cb2;
    int used_option[4];
} RoqTempdata;
#define EVAL_MOTION(MOTION) \
typedef struct CodingSpool {
    int typeSpool;
    int typeSpoolLength;
    uint8_t argumentSpool[64];
    uint8_t *args;
    uint8_t **pout;
} CodingSpool;
#define OFFSET(x) offsetof(RoqContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
