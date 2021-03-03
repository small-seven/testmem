#include "dcaadpcm.h"
#include "dcaenc.h"
#include "dca_core.h"
#include "mathops.h"
typedef int32_t premultiplied_coeffs[10];

//assume we have DCA_ADPCM_COEFFS values before x
static inline int64_t calc_corr(const int32_t *x, int len, int j, int k)
{
    int n;
    int64_t s = 0;
    for (n = 0; n < len; n++)
        s += MUL64(x[n-j], x[n-k]);
    return s;
}
av_cold void ff_dcaadpcm_free(DCAADPCMEncContext *s)
{
    if (!s)
        return;

    av_freep(&s->private_data);
}
