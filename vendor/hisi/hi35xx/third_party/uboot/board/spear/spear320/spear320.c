#include <common.h>
#include <miiphy.h>
#include <netdev.h>
#include <nand.h>
#include <asm/io.h>
#include <linux/mtd/fsmc_nand.h>
#include <asm/mach-types.h>
#include <asm/arch/hardware.h>
#include <asm/arch/spr_defs.h>
#include <asm/arch/spr_misc.h>
#define PLGPIO_SEL_36	0xb3000028
#define PLGPIO_IO_36	0xb3000038
#if defined(CONFIG_NAND_FSMC)
#endif
#if defined(CONFIG_ETH_DESIGNWARE)
#endif
#if defined(CONFIG_MACB)
#endif
