#include <common.h>
#include <dm.h>
#include <command.h>
#include <cros_ec.h>
#include <asm/io.h>
#ifdef DEBUG_TRACE
#define debug_trace(fmt, b...)	debug(fmt, ##b)
#else
#define debug_trace(fmt, b...)
#endif
