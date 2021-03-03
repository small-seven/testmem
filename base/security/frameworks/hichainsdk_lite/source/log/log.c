#ifndef _HC_DEBUG_
#include "log.h"
#include <securec.h>
#include "base.h"
#include "../huks_adapter/hks_client.h"
#if defined(_WINDOWS)
#ifdef DLL_EXPORT
#define DLL_API_PUBLIC __declspec(dllexport)
#else
#define DLL_API_PUBLIC __declspec(dllimport)
#endif
#else
#define DLL_API_PUBLIC __attribute__ ((visibility("default")))
#endif
#endif /* _HC_DEBUG_ */
