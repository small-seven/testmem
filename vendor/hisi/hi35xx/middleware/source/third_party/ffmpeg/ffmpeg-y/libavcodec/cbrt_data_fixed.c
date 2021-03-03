#include "config.h"
#include "cbrt_data.h"
#if CONFIG_HARDCODED_TABLES
#include "libavcodec/cbrt_fixed_tables.h"
#else
#define USE_FIXED 1
#include "cbrt_tablegen.h"
#endif
