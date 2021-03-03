#include <common.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/iomux-mx23.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#ifdef CONFIG_LED_STATUS
#include <status_led.h>
#endif
#ifdef CONFIG_CMD_USB
#endif
#ifdef	CONFIG_CMD_MMC
#endif
#if defined(CONFIG_LED_STATUS) && defined(CONFIG_LED_STATUS_BOOT_ENABLE)
#endif
