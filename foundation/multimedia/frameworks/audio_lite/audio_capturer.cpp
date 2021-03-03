#include "audio_capturer.h"
#include "audio_capturer_impl.h"
bool AudioCapturer::Release()
{
    return impl_->Release();
}
