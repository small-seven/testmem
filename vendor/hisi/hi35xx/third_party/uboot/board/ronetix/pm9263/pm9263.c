#include <common.h>
#include <linux/sizes.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/at91_matrix.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#if defined(CONFIG_RESET_PHY_R) && defined(CONFIG_MACB)
#include <net.h>
#endif
#include <netdev.h>
#include <asm/mach-types.h>
#ifdef CONFIG_CMD_NAND
#ifdef CONFIG_SYS_NAND_DBW_16
#else /* CONFIG_SYS_NAND_DBW_8 */
#endif
#endif
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_LCD
#ifdef CONFIG_LCD_IN_PSRAM
#define PSRAM_CRE_PIN	AT91_PIO_PORTB, 29
#define PSRAM_CTRL_REG	(PHYS_PSRAM + PHYS_PSRAM_SIZE - 2)
#endif
#ifdef CONFIG_LCD_IN_PSRAM
#else
#endif
#endif /* CONFIG_LCD */
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_USB_OHCI_NEW
#endif
#ifdef CONFIG_LCD
#endif
#ifdef CONFIG_RESET_PHY_R
#endif
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_DISPLAY_BOARDINFO
#endif
