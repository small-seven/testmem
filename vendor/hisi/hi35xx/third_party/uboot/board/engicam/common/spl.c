#include <common.h>
#include <serial.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <linux/sizes.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/video.h>
#define UART_PAD_CTRL  (PAD_CTL_PKE | PAD_CTL_PUE |             \
#ifdef CONFIG_MX6QDL
#elif CONFIG_MX6UL
#endif
#ifdef CONFIG_SPL_LOAD_FIT
#endif
#ifdef CONFIG_ENV_IS_IN_MMC
#endif
#ifdef CONFIG_SPL_OS_BOOT
#endif
#ifdef CONFIG_MX6QDL
#define IMX6DQ_DRIVE_STRENGTH		0x30
#define IMX6SDL_DRIVE_STRENGTH		0x28
#endif /* CONFIG_MX6QDL */
#ifdef CONFIG_MX6UL
#ifdef TARGET_MX6UL_ISIOT
#else
#endif
#endif /* CONFIG_MX6UL */
#ifdef CONFIG_MX6QDL
#elif CONFIG_MX6UL
#endif
#ifdef CONFIG_MX6QDL
#elif CONFIG_MX6UL
#endif
