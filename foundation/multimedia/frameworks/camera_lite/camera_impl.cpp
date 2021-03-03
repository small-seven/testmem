#include "camera_impl.h"
#include "camera_service.h"
#include "media_log.h"
void CameraImpl::Release()
{
    if (config_ != nullptr) {
        delete config_;
        config_ = nullptr;
    }
    handler_->Post([this] { this->stateCb_->OnReleased(*this); });
}
