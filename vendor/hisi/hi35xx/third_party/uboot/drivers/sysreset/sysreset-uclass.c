#define LOG_CATEGORY UCLASS_SYSRESET
#include <common.h>
#include <sysreset.h>
#include <dm.h>
#include <errno.h>
#include <regmap.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/root.h>
#include <linux/err.h>
#if IS_ENABLED(CONFIG_SYSRESET_CMD_POWEROFF)
#endif
#if defined(CONFIG_NEEDS_MANUAL_RELOC)
#endif
