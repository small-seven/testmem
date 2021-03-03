#include "recorder_audio_source.h"
#include "media_log.h"
int32_t RecorderAudioSource::Release()
{
    if (!audioCap_->Release()) {
        MEDIA_ERR_LOG("AudioCapturer Can't Release");
        return ERR_UNKNOWN;
    }
    return SUCCESS;
}
