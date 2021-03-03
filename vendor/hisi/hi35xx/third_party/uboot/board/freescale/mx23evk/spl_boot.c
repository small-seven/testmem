#include <common.h>
#include <config.h>
#include <asm/io.h>
#include <asm/arch/iomux-mx23.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#define	MUX_CONFIG_SSP1	(MXS_PAD_8MA | MXS_PAD_PULLUP)
#define	MUX_CONFIG_EMI	(MXS_PAD_3V3 | MXS_PAD_12MA | MXS_PAD_PULLUP)
#define	MUX_CONFIG_LCD	(MXS_PAD_4MA | MXS_PAD_NOPULL)
#define HW_DRAM_CTL14	(0x38 >> 2)
#define CS_MAP		0x3
#define INTAREF		0x2
#define HW_DRAM_CTL14_CONFIG	(INTAREF << 8 | CS_MAP)
