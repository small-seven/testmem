#include "libavutil/avassert.h"
#include "avcodec.h"
#include "internal.h"
#include "libavutil/common.h"
typedef struct EightSvxContext {
    uint8_t fib_acc[2];
    const int8_t *table;

    /* buffer used to store the whole first packet.
       data is only sent as one large packet */
    uint8_t *data[2];
    int data_size;
    int data_idx;
} EightSvxContext;
#define MAX_FRAME_SIZE 2048
#if CONFIG_EIGHTSVX_FIB_DECODER
#endif
#if CONFIG_EIGHTSVX_EXP_DECODER
#endif
