#define LOG_CATEGORY LOGC_DM
#include <common.h>
#include <errno.h>
#include <dm/device.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/platdata.h>
#include <dm/uclass.h>
#include <dm/util.h>
#include <fdtdec.h>
#include <linux/compiler.h>
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
