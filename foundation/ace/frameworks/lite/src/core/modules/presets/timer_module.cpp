#include "timer_module.h"
#ifdef FEATURE_TIMER_MODULE
#if (!defined(_WIN32) && !defined(_WIN64))
#include "js_async_work.h"
#endif
#include "ace_log.h"
#include "ace_mem_base.h"
#include "js_fwk_common.h"
#include <cstdint>
#include <string.h>
#include "nativeapi_timer_task.h"
#if (!defined _WIN32) && (!defined _WIN64)
#if defined(__LITEOS__)
#endif
#else
#endif
#if (!defined(_WIN32) && !defined(_WIN64))
#if defined(__LITEOS__)
#endif
#endif
#endif // FEATURE_TIMER_MODULE
