#include "libavutil/avassert.h"
#include "libavutil/samplefmt.h"
#include "libavutil/pixfmt.h"
#include "libavcodec/avcodec.h"
#include "avdevice.h"
#include "internal.h"
#include "config.h"
#include "libavutil/ffversion.h"
#define E AV_OPT_FLAG_ENCODING_PARAM
#define D AV_OPT_FLAG_DECODING_PARAM
#define A AV_OPT_FLAG_AUDIO_PARAM
#define V AV_OPT_FLAG_VIDEO_PARAM
#define OFFSET(x) offsetof(AVDeviceCapabilitiesQuery, x)
#undef E
#undef D
#undef A
#undef V
#undef OFFSET
#define LICENSE_PREFIX "libavdevice license: "
void avdevice_capabilities_free(AVDeviceCapabilitiesQuery **caps, AVFormatContext *s)
{
    if (!s || !caps || !(*caps))
        return;
    av_assert0(s->iformat || s->oformat);
    if (s->iformat) {
        if (s->iformat->free_device_capabilities)
            s->iformat->free_device_capabilities(s, *caps);
    } else {
        if (s->oformat->free_device_capabilities)
            s->oformat->free_device_capabilities(s, *caps);
    }
    av_freep(caps);
}
