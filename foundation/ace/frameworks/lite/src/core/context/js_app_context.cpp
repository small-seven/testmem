#include "js_app_context.h"
#include "ace_event_error_code.h"
#include "ace_log.h"
#if (defined(__LINUX__) || defined(__LITEOS__))
#include "ace_ability.h"
#endif
#include "component_factory.h"
#include "component_utils.h"
#include "js_app_environment.h"
#include "platform_adapter.h"
#if ENABLED(SECURE_C_FUNCTION)
#include "securec.h"
#endif // ENABLED(SECURE_C_FUNCTION)
#include "root_view.h"
#include "task_manager.h"
#include "ui_view_group.h"
#if (!defined(_WIN32) && !defined(_WIN64))
#ifdef SERVICE_MANAGER_API_SUPPORTED
#include "ability_service_interface.h"
#include "iunknown.h"
#include "samgr_lite.h"
#endif // SERVICE_MANAGER_API_SUPPORTED
#endif // (!defined(_WIN32) && !defined(_WIN64))
#include "fatal_handler.h"
#include "js_profiler.h"
