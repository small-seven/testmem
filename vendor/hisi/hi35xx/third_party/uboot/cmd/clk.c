#include <common.h>
#include <command.h>
#include <clk.h>
#if defined(CONFIG_DM) && defined(CONFIG_CLK)
#include <dm.h>
#include <dm/device.h>
#include <dm/root.h>
#include <dm/device-internal.h>
#include <linux/clk-provider.h>
#endif
#if defined(CONFIG_DM) && defined(CONFIG_CLK)
#else
#endif
#ifdef CONFIG_SYS_LONGHELP
#endif
