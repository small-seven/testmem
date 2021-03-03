#define LOG_CATEGORY UCLASS_CROS_EC
#include <common.h>
#include <command.h>
#include <dm.h>
#include <i2c.h>
#include <cros_ec.h>
#include <fdtdec.h>
#include <malloc.h>
#include <spi.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm-generic/gpio.h>
#include <dm/device-internal.h>
#include <dm/of_extra.h>
#include <dm/uclass-internal.h>
#ifdef DEBUG_TRACE
#define debug_trace(fmt, b...)	debug(fmt, #b)
#else
#define debug_trace(fmt, b...)
#endif
#define INVALID_HCMD 0xFF
#ifdef DEBUG
#endif
#define UHEPI_SUPPORTED 1
#define UHEPI_NOT_SUPPORTED 2
