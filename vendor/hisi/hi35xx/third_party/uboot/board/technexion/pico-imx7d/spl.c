#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/mx7-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch-mx7/mx7-ddr.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/gpio.h>
#include <fsl_esdhc_imx.h>
#include <spl.h>
#if defined(CONFIG_SPL_BUILD)
#ifdef CONFIG_SPL_OS_BOOT
#endif
#define USDHC_PAD_CTRL (PAD_CTL_DSE_3P3V_32OHM | PAD_CTL_SRE_SLOW | \
#endif
