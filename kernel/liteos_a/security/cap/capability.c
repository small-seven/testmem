#include "capability_type.h"
#include "los_memory.h"
#include "los_process_pri.h"
#include "user_copy.h"
#include "los_printf.h"
#define CAPABILITY_INIT_STAT            0xffffffff
#define CAPABILITY_GET_CAP_MASK(x)      (1 << ((x) & 31))
#define CAPABILITY_MAX                  31
