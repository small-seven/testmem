#include "js_fwk_common.h"
#include "ace_event_error_code.h"
#include "ace_log.h"
#include "ace_mem_base.h"
#include "component.h"
#include "component_utils.h"
#include "fatal_handler.h"
#include "file.h"
#include "js_app_context.h"
#include "js_app_environment.h"
#include "js_profiler.h"
#if ENABLED(CONSOLE_LOG_OUTPUT)
#include "presets/console_module.h"
#endif
#if ENABLED(SECURE_C_FUNCTION)
#include "securec.h"
#endif // ENABLED(SECURE_C_FUNCTION)
#include "presets/console_log_impl.h"
#include "task_manager.h"
#if defined(__LITEOS__)
#include <limits.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
#if ((defined __LITEOS__) || (defined __linux__) || (defined SCREENRESOLUTION_CMAKE))
#include <screen.h>
#endif
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#if ENABLED(ENGINE_DEBUGGER)
#endif
void CallJSFunctionAutoRelease(const jerry_value_t funcObj,
                               const jerry_value_t thisVal,
                               const jerry_value_t args[],
                               const jerry_size_t argc)
{
    jerry_release_value(CallJSFunction(funcObj, thisVal, args, argc));
}
#ifdef JS_TOUCH_EVENT_SUPPORT
#endif
#if defined(__LITEOS__)
#else
#endif
#if defined(__LITEOS__)
#else
#endif
#if defined(__LITEOS__)
#endif
#if (defined(_WIN32) || defined(_WIN64))
#else
#endif // (defined(_WIN32) || defined(_WIN64))
#if defined(__LITEOS__)
#else
#endif
#if defined(__LITEOS__)
#else
#endif
#if JS_PAGE_SPECIFIC
#endif // JS_PAGE_SPECIFIC
#if (defined(_WIN32) || defined(_WIN64))
#endif
#if ((defined __LITEOS__) || (defined __linux__) || (defined SCREENRESOLUTION_CMAKE))
#else
#endif // OHOS_ACELITE_PRODUCT_WATCH
#if ((defined __LITEOS__) || (defined __linux__) || (defined SCREENRESOLUTION_CMAKE))
#else
#endif // OHOS_ACELITE_PRODUCT_WATCH
#ifdef OHOS_ACELITE_PRODUCT_WATCH
#endif // OHOS_ACELITE_PRODUCT_WATCH
#ifdef OHOS_ACELITE_PRODUCT_WATCH
#endif // OHOS_ACELITE_PRODUCT_WATCH
