#include <stdint.h>
#include "opus.h"
#include "opustab.h"
typedef struct SilkFrame {
    int coded;
    int log_gain;
    int16_t nlsf[16];
    float    lpc[16];

    float output     [2 * SILK_HISTORY];
    float lpc_history[2 * SILK_HISTORY];
    int primarylag;

    int prev_voiced;
} SilkFrame;
#define SILK_MAX_LAG  (288 + LTP_ORDER / 2)
#define LTP_ORDER 5
void ff_silk_free(SilkContext **ps)
{
    av_freep(ps);
}
