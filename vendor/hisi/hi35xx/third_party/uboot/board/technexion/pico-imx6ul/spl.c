#include <asm/arch/clock.h>
#include <asm/arch/iomux.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/mx6ul_pins.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/boot_mode.h>
#include <fsl_esdhc_imx.h>
#include <linux/libfdt.h>
#include <spl.h>
#if defined(CONFIG_SPL_BUILD)
#ifdef CONFIG_SPL_OS_BOOT
#endif
#include <asm/arch/mx6-ddr.h>
#define USDHC_PAD_CTRL (PAD_CTL_PKE | PAD_CTL_PUE |		\
#endif
