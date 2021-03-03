#include "console_log_impl.h"
#if ENABLED(CONSOLE_LOG_OUTPUT)
#include "js_app_environment.h"
#ifdef FEATURE_USER_MC_LOG_PRINTF
#include "log_js.h" // mc js console log header
#endif // FEATURE_USER_MC_LOG_PRINTF
#ifdef FEATURE_ACELITE_HI_LOG_PRINTF
#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0xD003B00
#define LOG_TAG "JS-3RD-APP"
#include "hilog/log.h"
#endif // FEATURE_ACELITE_HI_LOG_PRINTF
#include <stdio.h>
#include <string.h>
#ifdef CONSOLE_LOG_LINE_MAX_LENGTH
#else
#endif // CONSOLE_LOG_LINE_MAX_LENGTH
#if defined(FEATURE_ACELITE_HI_LOG_PRINTF) || defined(FEATURE_USER_MC_LOG_PRINTF)
#else
#endif
#if !defined(FEATURE_ACELITE_HI_LOG_PRINTF) && !defined(FEATURE_USER_MC_LOG_PRINTF)
#endif
#ifdef FEATURE_ACELITE_HI_LOG_PRINTF
#elif defined(FEATURE_USER_MC_LOG_PRINTF)
#endif
#if defined(FEATURE_ACELITE_HI_LOG_PRINTF) || defined(FEATURE_USER_MC_LOG_PRINTF)
#endif
#endif // ENABLED(CONSOLE_LOG_OUTPUT)
