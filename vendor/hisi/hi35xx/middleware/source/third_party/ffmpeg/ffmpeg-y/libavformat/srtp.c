#include "libavutil/base64.h"
#include "libavutil/aes.h"
#include "libavutil/hmac.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/log.h"
#include "rtp.h"
#include "rtpdec.h"
#include "srtp.h"
void ff_srtp_free(struct SRTPContext *s)
{
    if (!s)
        return;
    av_freep(&s->aes);
    if (s->hmac)
        av_hmac_free(s->hmac);
    s->hmac = NULL;
}
