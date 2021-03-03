#include <common.h>
#include <vsprintf.h>
#include <linux/sizes.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/at91_matrix.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#if defined(CONFIG_RESET_PHY_R) && defined(CONFIG_DRIVER_DM9000)
#include <net.h>
#endif
#include <netdev.h>
#include <asm/mach-types.h>
#ifdef CONFIG_CMD_NAND
#ifdef CONFIG_SYS_NAND_DBW_16
#else /* CONFIG_SYS_NAND_DBW_8 */
#endif
#endif
#ifdef CONFIG_DRIVER_DM9000
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_DRIVER_DM9000
#endif
#ifdef CONFIG_DRIVER_DM9000
#endif
#ifdef CONFIG_RESET_PHY_R
#ifdef CONFIG_DRIVER_DM9000
#endif
#endif
#ifdef CONFIG_DISPLAY_BOARDINFO
#endif
