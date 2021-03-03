#include "platform_adapter.h"
#include <cstdlib>
#include "acelite_config.h"
#if (defined(__LINUX__) || defined(__LITEOS__))
#include "ace_ability.h"
#endif
#include "ace_log.h"
#include "ace_version.h"
#include "js_fwk_common.h"
#ifdef TARGET_SIMULATOR
#endif // TARGET_SIMULATOR
#ifndef TARGET_SIMULATOR
#else
#endif
#ifndef TARGET_SIMULATOR
#endif // TARGET_SIMULATOR
#ifdef FEATURE_TERMINATE_ABILITY
#endif
#ifndef TARGET_SIMULATOR // no AMS support on PC simulator
#ifdef FEATURE_TERMINATE_ABILITY
#else
#endif
#endif
#ifdef TARGET_SIMULATOR
#endif // TARGET_SIMULATOR
