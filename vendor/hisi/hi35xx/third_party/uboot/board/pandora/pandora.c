#include <common.h>
#include <dm.h>
#include <ns16550.h>
#include <twl4030.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/mux.h>
#include <asm/arch/gpio.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-types.h>
#include "pandora.h"
#define TWL4030_BB_CFG_BBCHEN		(1 << 4)
#define TWL4030_BB_CFG_BBSEL_3200MV	(3 << 2)
#define TWL4030_BB_CFG_BBISEL_500UA	2
#define CONTROL_WKUP_CTRL		0x48002a5c
#define GPIO_IO_PWRDNZ			(1 << 6)
#define PBIASLITEVMODE1			(1 << 8)
#ifdef CONFIG_MMC
#endif
