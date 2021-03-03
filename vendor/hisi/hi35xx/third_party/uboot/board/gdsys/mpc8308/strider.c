#include <common.h>
#include <env.h>
#include <hwconfig.h>
#include <i2c.h>
#include <init.h>
#include <spi.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <pci.h>
#include <mpc83xx.h>
#include <fsl_esdhc.h>
#include <asm/io.h>
#include <asm/fsl_serdes.h>
#include <asm/fsl_mpc83xx_serdes.h>
#include "mpc8308.h"
#include <gdsys_fpga.h>
#include "../common/adv7611.h"
#include "../common/ch7301.h"
#include "../common/dp501.h"
#include "../common/ioep-fpga.h"
#include "../common/mclink.h"
#include "../common/osd.h"
#include "../common/phy.h"
#include "../common/fanctrl.h"
#include <pca953x.h>
#include <pca9698.h>
#include <miiphy.h>
#define MAX_MUX_CHANNELS 2
#ifdef CONFIG_STRIDER_CPU
#endif
#ifdef CONFIG_STRIDER_CON_DP
#endif
#ifdef CONFIG_STRIDER_CPU
#else
#endif
#ifdef CONFIG_STRIDER_CON
#endif
#ifdef CONFIG_STRIDER_CON_DP
#endif
#ifdef CONFIG_STRIDER_CPU
#endif
#ifdef CONFIG_STRIDER_CPU
#endif
#ifdef CONFIG_STRIDER_CON
#endif
#ifdef CONFIG_STRIDER_CON_DP
#endif
#ifdef CONFIG_STRIDER_CPU
#endif
#ifdef CONFIG_STRIDER_CON_DP
#endif
#ifdef CONFIG_FSL_ESDHC
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#endif
