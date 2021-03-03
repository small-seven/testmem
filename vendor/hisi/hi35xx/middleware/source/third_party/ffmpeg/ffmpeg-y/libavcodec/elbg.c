#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/lfg.h"
#include "elbg.h"
#include "avcodec.h"
#define DELTA_ERR_MAX 0.1  ///< Precision of the ELBG algorithm (as percentage error)
typedef struct cell_s {
    int index;
    struct cell_s *next;
} cell;
typedef struct elbg_data {
    int error;
    int dim;
    int numCB;
    int *codebook;
    cell **cells;
    int *utility;
    int64_t *utility_inc;
    int *nearest_cb;
    int *points;
    AVLFG *rand_state;
    int *scratchbuf;
} elbg_data;
#define BIG_PRIME 433494437LL
