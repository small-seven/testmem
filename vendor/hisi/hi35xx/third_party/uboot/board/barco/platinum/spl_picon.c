#include <common.h>
#include <i2c.h>
#include <asm/io.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <spl.h>
#include "platinum.h"
#undef RTT_NOM_120OHM	/* use 120ohm Rtt_nom vs 60ohm (lower power) */
#ifdef RTT_NOM_120OHM
#else
#endif
