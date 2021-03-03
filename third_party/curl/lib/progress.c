#include "curl_setup.h"
#include "urldata.h"
#include "sendf.h"
#include "multiif.h"
#include "progress.h"
#include "timeval.h"
#include "curl_printf.h"
#define MIN_RATE_LIMIT_PERIOD 3000
#ifndef CURL_DISABLE_PROGRESS_METER
#define ONE_KILOBYTE  CURL_OFF_T_C(1024)
#define ONE_MEGABYTE (CURL_OFF_T_C(1024) * ONE_KILOBYTE)
#define ONE_GIGABYTE (CURL_OFF_T_C(1024) * ONE_MEGABYTE)
#define ONE_TERABYTE (CURL_OFF_T_C(1024) * ONE_GIGABYTE)
#define ONE_PETABYTE (CURL_OFF_T_C(1024) * ONE_TERABYTE)
#if (CURL_SIZEOF_CURL_OFF_T > 4)
#else
#endif
#endif
#ifndef CURL_DISABLE_PROGRESS_METER
#else
#define progress_meter(x) Curl_nop_stmt
#endif
