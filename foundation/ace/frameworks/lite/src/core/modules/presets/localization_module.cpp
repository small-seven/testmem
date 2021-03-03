#include "localization_module.h"
#include "ace_event_error_code.h"
#ifdef FEATURE_LOCALIZATION_MODULE
#include "ace_log.h"
#if (defined(_WIN32) || defined(_WIN64))
#include <windows.h>
#else
#include "securec.h"
#endif
#include "file.h"
#include "js_fwk_common.h"
#include <stdlib.h>
#ifdef LOCALIZATION_PLURAL
#endif // LOCALIZATION_PLURAL
#ifdef LOCALIZATION_PLURAL
#else
#endif
#ifdef LOCALIZATION_PLURAL
#else
#endif // LOCALIZATION_PLURAL
#ifdef LOCALIZATION_PLURAL
#else
#endif // LOCALIZATION_PLURAL
#endif // LOCALIZATION_MODULE
