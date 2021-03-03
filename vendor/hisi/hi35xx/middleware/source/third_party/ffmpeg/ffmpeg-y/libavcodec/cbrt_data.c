#include "config.h"
#include "cbrt_data.h"
#include "libavutil/libm.h"
#if CONFIG_HARDCODED_TABLES
#include "libavcodec/cbrt_tables.h"
#else
#include "cbrt_tablegen.h"
#endif
