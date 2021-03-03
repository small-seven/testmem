#include "dfx/ui_screenshot.h"
#if ENABLE_DEBUG
#include "client/iwindows_manager.h"
#include "color.h"
#include "common/screen.h"
#include "draw/draw_utils.h"
#include "file.h"
#include "graphic_log.h"
#include "image_info.h"
#include "securec.h"
#if COLOR_DEPTH == 16
#elif COLOR_DEPTH == 32
#endif
#endif // ENABLE_DEBUG