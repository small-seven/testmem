#include <common.h>
#include <config.h>
#include <asm/io.h>
#include <asm/arch/iomux-mx28.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#define	MUX_CONFIG_LED	(MXS_PAD_3V3 | MXS_PAD_4MA | MXS_PAD_NOPULL)
#define	MUX_CONFIG_SSP0	(MXS_PAD_3V3 | MXS_PAD_12MA | MXS_PAD_PULLUP)
#define	MUX_CONFIG_SSP2	(MXS_PAD_3V3 | MXS_PAD_4MA | MXS_PAD_PULLUP)
#define	MUX_CONFIG_ENET	(MXS_PAD_3V3 | MXS_PAD_12MA | MXS_PAD_NOPULL)
#define	MUX_CONFIG_EMI	(MXS_PAD_3V3 | MXS_PAD_12MA | MXS_PAD_NOPULL)
