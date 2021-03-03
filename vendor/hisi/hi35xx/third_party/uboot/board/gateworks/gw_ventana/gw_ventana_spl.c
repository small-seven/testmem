#include <common.h>
#include <env.h>
#include <asm/io.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <env.h>
#include <i2c.h>
#include <spl.h>
#include "gsc.h"
#include "common.h"
#define RTT_NOM_120OHM /* use 120ohm Rtt_nom vs 60ohm (lower power) */
#define GSC_EEPROM_DDR_SIZE	0x2B	/* enum (512,1024,2048) MB */
#define GSC_EEPROM_DDR_WIDTH	0x2D	/* enum (32,64) bit */
#ifdef RTT_NOM_120OHM
#else
#endif
#ifdef CONFIG_SPL_OS_BOOT
#ifdef CONFIG_SPL_ENV_SUPPORT
#else
#endif
#endif
