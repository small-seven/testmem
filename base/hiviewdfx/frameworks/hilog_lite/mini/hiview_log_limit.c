#include "hos_types.h"
#include "hos_init.h"
#include "hiview_def.h"
#include "hiview_util.h"
#include "hiview_config.h"
#include "hiview_log.h"
#include "hiview_log_limit.h"
#define LOG_LIMIT_CHECK_DURATION   60   /* seconds */
#define LOG_LIMIT_LEVEL1           6    /* Maximum number of log records in a check period. */
#define LOG_LIMIT_LEVEL2           30
#define LOG_LIMIT_LEVEL3           60
#define LOG_LIMIT_LEVEL4           120
#define LOG_LIMIT_DEFAULT          LOG_LIMIT_LEVEL2
