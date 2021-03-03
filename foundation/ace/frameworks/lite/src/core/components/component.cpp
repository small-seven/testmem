#include "component.h"
#include "ace_log.h"
#include "ace_mem_base.h"
#include "directive/descriptor_utils.h"
#include "fatal_handler.h"
#include "handler.h"
#include "js_ability_impl.h"
#include "js_app_context.h"
#include "js_app_environment.h"
#include "js_profiler.h"
#include "js_router.h"
#include "key_parser.h"
#include "keys.h"
#include "stylemgr/app_style.h"
#include "stylemgr/app_style_manager.h"
#include "time_util.h"
#include "wrapper/js.h"
#if ENABLED(SECURE_C_FUNCTION)
#include "securec.h"
#endif // ENABLED(SECURE_C_FUNCTION)
#ifdef JS_TOUCH_EVENT_SUPPORT
#endif
void Component::Release()
{
    // detach self from fatal handler monitoring
    FatalHandler::GetInstance().DetachComponentNode(this);
    // stop view animation
    if (curTransitionImpl_) {
        curTransitionImpl_->Stop();
    }
    // release all native views
    ReleaseNativeViews();
    // release transition param
    ReleaseTransitionParam();
    // release the common event listeners if any
    ReleaseCommonEventListeners();
    // release children = jerry_create_array() in Init()
    ClearWatchersCommon(watchersHead_);
    // free viewId string if it's set
    ACE_FREE(viewId_);
    // release js object
    jerry_release_value(nativeElement_);
    jerry_release_value(descriptors_);
    jerry_release_value(children_);
    jerry_release_value(viewModel_);
}
#ifdef JS_TOUCH_EVENT_SUPPORT
#endif
#ifdef JS_TOUCH_EVENT_SUPPORT
#endif
#ifdef JS_TOUCH_EVENT_SUPPORT
#endif
