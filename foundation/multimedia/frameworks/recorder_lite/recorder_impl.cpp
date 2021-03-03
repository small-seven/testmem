#include "recorder_impl.h"
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/io.h>
#include <sys/select.h>
#include <sys/prctl.h>
#include "media_log.h"
#include "securec.h"
#define CHECK_MEMBER_PTR_RETURN(param)                                \
int32_t Recorder::RecorderImpl::Release()
{
    std::lock_guard<std::mutex> lock(mutex_);
    int32_t ret;
    if ((ret = InitCheck()) != SUCCESS) {
        MEDIA_ERR_LOG("Release InitCheck err");
        return ret;
    }
    if (status_ == RECORDING ||
        status_ == PAUSED) {
        if ((ret = Stop(false)) != SUCCESS) {
            MEDIA_ERR_LOG("Release Stop err");
            return ret;
        }
    }
    CHECK_MEMBER_PTR_RETURN(recorderSink_);
    ret = recorderSink_->Release();
    if (ret != SUCCESS) {
        MEDIA_ERR_LOG("recorderSink_  Release failed Ret: %d", ret);
        return ret;
    }
    status_ = RELEASED;
    MEDIA_INFO_LOG("Recorder Released");
    return SUCCESS;
}
