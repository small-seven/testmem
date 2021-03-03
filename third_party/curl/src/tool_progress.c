#include "tool_setup.h"
#include "tool_operate.h"
#include "tool_progress.h"
#include "tool_util.h"
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#define ONE_KILOBYTE  CURL_OFF_T_C(1024)
#define ONE_MEGABYTE (CURL_OFF_T_C(1024) * ONE_KILOBYTE)
#define ONE_GIGABYTE (CURL_OFF_T_C(1024) * ONE_MEGABYTE)
#define ONE_TERABYTE (CURL_OFF_T_C(1024) * ONE_GIGABYTE)
#define ONE_PETABYTE (CURL_OFF_T_C(1024) * ONE_TERABYTE)
#if (CURL_SIZEOF_CURL_OFF_T > 4)
#else
#endif
#define SPEEDCNT 10
