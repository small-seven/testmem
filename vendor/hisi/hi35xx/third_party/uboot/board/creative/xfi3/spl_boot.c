#include <common.h>
#include <config.h>
#include <asm/io.h>
#include <asm/arch/iomux-mx23.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#define	MUX_CONFIG_EMI	(MXS_PAD_1V8 | MXS_PAD_12MA | MXS_PAD_PULLUP)
#define	MUX_CONFIG_SSP	(MXS_PAD_3V3 | MXS_PAD_8MA | MXS_PAD_PULLUP)
#define	MUX_CONFIG_LCD	(MXS_PAD_3V3 | MXS_PAD_4MA | MXS_PAD_NOPULL)
