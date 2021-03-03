#define _WIN32_WINNT    0x0400
#include "includes.h"
#ifndef COBJMACROS
#define COBJMACROS
#endif /* COBJMACROS */
#include <wbemidl.h>
#include "common.h"
#define BstrAlloc(x) (x) ? SysAllocString(x) : NULL
#define BstrFree(x) if (x) SysFreeString(x)
#define MAX_QUERY_LEN 256
