#include <common.h>
#include <command.h>
#include <dm.h>
#include <init.h>
#include <dm/platform_data/net_ethoc.h>
#include <env.h>
#include <linux/ctype.h>
#include <linux/string.h>
#include <linux/stringify.h>
#include <asm/global_data.h>
#if defined(CONFIG_XTFPGA_LX60)
#elif defined(CONFIG_XTFPGA_LX110)
#elif defined(CONFIG_XTFPGA_LX200)
#elif defined(CONFIG_XTFPGA_ML605)
#elif defined(CONFIG_XTFPGA_KC705)
#else
#endif
#ifdef CONFIG_SYS_FPGAREG_FREQ
#else
#endif
#ifdef CONFIG_CMD_NET
#endif /* CONFIG_CMD_NET */
