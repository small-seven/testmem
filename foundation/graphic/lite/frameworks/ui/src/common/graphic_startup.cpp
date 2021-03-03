#include "common/graphic_startup.h"
#include "animator/animator.h"
#include "common/input_device_manager.h"
#include "core/render_manager.h"
#include "common/task_manager.h"
#include "file.h"
#include "font/ui_font.h"
#include "graphic_log.h"
#include "imgdecode/cache_manager.h"
#ifdef VERSION_STANDARD
#include "dock/ohos/ohos_input_device.h"
#endif
#if ENABLE_WINDOW
#include "client/iwindows_manager.h"
#if ENABLE_HARDWARE_ACCELERATION
#include "gfx_engines.h"
#endif
#endif
#ifdef VERSION_STANDARD
#endif
#if ENABLE_WINDOW
#if ENABLE_HARDWARE_ACCELERATION
#endif
#endif
