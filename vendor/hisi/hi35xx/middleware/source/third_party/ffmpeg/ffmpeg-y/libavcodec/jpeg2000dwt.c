#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/mem.h"
#include "jpeg2000dwt.h"
#include "internal.h"
#define F_LFTG_ALPHA  1.586134342059924f
#define F_LFTG_BETA   0.052980118572961f
#define F_LFTG_GAMMA  0.882911075530934f
#define F_LFTG_DELTA  0.443506852043971f
#define I_LFTG_ALPHA  103949ll
#define I_LFTG_BETA     3472ll
#define I_LFTG_GAMMA   57862ll
#define I_LFTG_DELTA   29066ll
#define I_LFTG_K       80621ll
#define I_LFTG_X       53274ll
#define I_PRESHIFT 8
void ff_dwt_destroy(DWTContext *s)
{
    av_freep(&s->f_linebuf);
    av_freep(&s->i_linebuf);
}
