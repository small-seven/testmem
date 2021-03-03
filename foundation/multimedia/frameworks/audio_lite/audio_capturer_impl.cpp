#include "audio_capturer_impl.h"
#include <sys/select.h>
#include "audio_source.h"
#include "audio_encoder.h"
#include "media_log.h"
bool AudioCapturer::AudioCapturerImpl::Release()
{
    if (status == RELEASED) {
        MEDIA_ERR_LOG("ILLEGAL_STATE status:%u", status);
        return false;
    }
    if (status == RECORDING && Stop()) {
        MEDIA_ERR_LOG("Stop  failed: %u", status);
        return false;
    }
    status = RELEASED;
    MEDIA_INFO_LOG("Release Audio Capturer SUCCESS");
    return true;
}
