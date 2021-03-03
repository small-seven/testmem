#include "opus_celt.h"
#include "opustab.h"
#include "opus_pvq.h"
void ff_celt_free(CeltFrame **f)
{
    CeltFrame *frm = *f;
    int i;

    if (!frm)
        return;

    for (i = 0; i < FF_ARRAY_ELEMS(frm->imdct); i++)
        ff_mdct15_uninit(&frm->imdct[i]);

    ff_celt_pvq_uninit(&frm->pvq);

    av_freep(&frm->dsp);
    av_freep(f);
}
