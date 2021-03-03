#include <stdint.h>
#include <string.h>
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/mem.h"
#include "rl.h"
void ff_rl_free(RLTable *rl)
{
    int i;

    for (i = 0; i < 2; i++) {
        av_freep(&rl->max_run[i]);
        av_freep(&rl->max_level[i]);
        av_freep(&rl->index_run[i]);
    }
}
