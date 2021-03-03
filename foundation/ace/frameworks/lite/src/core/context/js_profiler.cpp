#include "js_profiler.h"
#if ENABLED(JS_PROFILER)
#include "ace_log.h"
#include "ace_mem_base.h"
#include "js_async_work.h"
#include "js_fwk_common.h"
#include "key_parser.h"
#if defined(FEATURE_ACELITE_MC_JS_PROFILER)
#include "common/file.h"
#include "los_swtmr.h"
#elif defined(FEATURE_ACELITE_JS_PROFILER)
#include <sys/time.h>
#else
#include <time.h>
#endif // FEATURE_ACELITE_MC_JS_PROFILER
#if ENABLED(SECURE_C_FUNCTION)
#include "securec.h"
#else // ENABLED(SECURE_C_FUNCTION)
#include <string.h>
#endif // ENABLED(SECURE_C_FUNCTION)
#include <stdlib.h>
#if defined(FEATURE_ACELITE_MC_JS_PROFILER)
#else
#endif
#ifndef FEATURE_ACELITE_MC_JS_PROFILER
#endif
#if defined(FEATURE_ACELITE_MC_JS_PROFILER)
#else
#endif
#ifdef FEATURE_ACELITE_MC_JS_PROFILER
#else
#endif
#ifdef FEATURE_ACELITE_MC_JS_PROFILER
#endif
#ifdef FEATURE_ACELITE_MC_JS_PROFILER
#endif
#ifdef FEATURE_ACELITE_MC_JS_PROFILER
#endif
void JSProfiler::Release()
{
    ACE_FREE(data_);
#ifdef FEATURE_ACELITE_MC_JS_PROFILER
    ACE_FREE(msg_);
#endif
}
#if ENABLED(SECURE_C_FUNCTION)
#else
#endif
#ifdef FEATURE_ACELITE_MC_JS_PROFILER
#endif
#if defined(FEATURE_ACELITE_MC_JS_PROFILER)
#else
#endif
#ifdef FEATURE_ACELITE_MC_JS_PROFILER
#else
#endif
#if defined(FEATURE_ACELITE_MC_JS_PROFILER)
#elif defined(FEATURE_ACELITE_JS_PROFILER)
#else
#endif
#ifndef FEATURE_ACELITE_JS_PROFILER
#endif
#if defined(FEATURE_ACELITE_MC_JS_PROFILER)
#elif defined(FEATURE_ACELITE_JS_PROFILER)
#else
#endif
#endif // ENABLED(JS_PROFILER)
