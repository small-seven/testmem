#include <common.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/crm_regs.h>
#include <asm/mach-imx/iomux-v3.h>
#include <fsl_esdhc_imx.h>
#include "common.h"
#define CM_FX6_DDR_IOMUX_CFG \
#define CM_FX6_GPR_IOMUX_CFG \
#ifdef CONFIG_SPL_SPI_SUPPORT
#else
#endif
#ifdef CONFIG_SPL_MMC_SUPPORT
#endif
