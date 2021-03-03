#include "event_listener.h"
#include "ace_log.h"
#include "jerryscript.h"
#include "js_fwk_common.h"
#include "root_view.h"
#ifdef JS_TOUCH_EVENT_SUPPORT
bool ViewOnTouchEndListener::OnRelease(UIView &view, const ReleaseEvent &event)
{
    return CallBaseEvent(fn_, event, id_);
}
#endif // JS_TOUCH_EVENT_SUPPORT
