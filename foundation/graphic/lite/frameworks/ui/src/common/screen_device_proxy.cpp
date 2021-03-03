#include "common/screen_device_proxy.h"
#include "graphic_log.h"
#include "securec.h"
#if ENABLE_FRAME_BUFFER
#else
#if ENABLE_WINDOW
#else
#endif
#endif
#if !ENABLE_WINDOW
#endif
