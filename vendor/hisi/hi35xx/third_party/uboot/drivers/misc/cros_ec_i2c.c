#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <cros_ec.h>
#ifdef DEBUG_TRACE
#define debug_trace(fmt, b...)	debug(fmt, #b)
#else
#define debug_trace(fmt, b...)
#endif
