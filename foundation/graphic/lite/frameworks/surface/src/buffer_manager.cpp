#include "buffer_manager.h"
#include "buffer_common.h"
#include "surface_buffer.h"
void BufferManager::FreeBuffer(SurfaceBufferImpl* buffer)
{
    RETURN_IF_FAIL((grallocFucs_ != nullptr));
    if (buffer == nullptr) {
        GRAPHIC_LOGW("Input param buffer is null.");
        return;
    }
    MemType type;
    if (!UsageToMemType(type, buffer->GetUsage())) {
        GRAPHIC_LOGW("Free graphic buffer failed --- invaild usage.");
        return;
    }
    GrallocBuffer grallocBuffer;
    SurfaceBufferToGrallocBuffer(*buffer, grallocBuffer);
    grallocBuffer.type = type;
    grallocFucs_->FreeMem(&grallocBuffer);
    GRAPHIC_LOGI("Free buffer succeed.");
    delete buffer;
}
