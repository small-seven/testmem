#include <common.h>
#include <env.h>
#include <errno.h>
#include <spl.h>
#include <asm/arch/cpu.h>
#include <asm/arch/hardware.h>
#include <asm/arch/omap.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/sys_proto.h>
#include <asm/io.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <i2c.h>
#include <miiphy.h>
#include <cpsw.h>
#include "board.h"
#define RMII_RGMII2_MODE_ENABLE	0x49
#ifdef CONFIG_SPL_BUILD
#define DDR_CLK_MHZ		303 /* DDR_DPLL_MULT value */
#define OSC	(V_OSCK/1000000)
#ifdef CONFIG_REV1
#else
#endif
#endif
#ifdef CONFIG_DRIVER_TI_CPSW
#endif
#if defined(CONFIG_DRIVER_TI_CPSW) || \
#ifdef CONFIG_DRIVER_TI_CPSW
#endif
#if defined(CONFIG_USB_ETHER) && !defined(CONFIG_SPL_BUILD)
#endif
#endif
