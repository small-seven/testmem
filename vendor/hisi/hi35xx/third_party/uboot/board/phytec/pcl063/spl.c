#include <common.h>
#include <spl.h>
#include <asm/arch/clock.h>
#include <asm/io.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/sys_proto.h>
#include <fsl_esdhc_imx.h>
#ifdef CONFIG_FSL_ESDHC_IMX
#define USDHC_PAD_CTRL (PAD_CTL_PKE         | PAD_CTL_PUE       | \
#ifndef CONFIG_NAND_MXS
#endif
#ifndef CONFIG_NAND_MXS
#endif
#ifndef CONFIG_NAND_MXS
#endif
#endif /* CONFIG_FSL_ESDHC_IMX */
