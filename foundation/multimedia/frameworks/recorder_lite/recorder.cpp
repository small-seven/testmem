#include "recorder.h"
#include "media_log.h"
#include "pms_interface.h"
#include "recorder_impl.h"
#include "securec.h"
int32_t Recorder::Release()
{
    return impl_->Release();
}
