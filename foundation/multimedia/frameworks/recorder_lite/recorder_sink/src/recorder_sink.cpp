#include "recorder_sink.h"
#include "format_interface.h"
#include "media_log.h"
#include "securec.h"
int32_t RecorderSink::Release()
{
    int32_t ret;
    if (started_) {
        ret = Stop(false);
        if (ret != SUCCESS) {
            MEDIA_ERR_LOG("Stop failed 0x%x", ret);
            return ret;
        }
        started_ = false;
    }
    ret = FormatMuxerDestory(formatMuxerHandle_);
    if (ret != SUCCESS) {
        MEDIA_ERR_LOG("FormatMuxerDestory failed Ret: 0x%x", ret);
        return ret;
    }
    formatMuxerHandle_ = nullptr;
    prepared_ = false;
    return SUCCESS;
}
