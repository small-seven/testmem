#include "feature_ability_module.h"
#ifdef FEATURE_FEATURE_ABILITY_MODULE
#include "ace_event_error_code.h"
#include "ace_log.h"
#include "fatal_handler.h"
#include "js_app_context.h"
#include "js_async_work.h"
#include "js_fwk_common.h"
#if ENABLED(SECURE_C_FUNCTION)
#include "securec.h"
#endif // ENABLED(SECURE_C_FUNCTION)
void FeatureAbilityModule::Release()
{
    ReleaseJsValues();
    if (registed) {
        char *bundleName = const_cast<char *>(JsAppContext::GetInstance()->GetCurrentBundleName());
        AbilityKit::UnregisterReceiver(bundleName);
        registed = false;
    }
}
#if ENABLED(SECURE_C_FUNCTION)
#else
#endif
#endif
