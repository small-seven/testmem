#include <common.h>
#include <command.h>
#include <env.h>
#include <init.h>
#include <pci.h>
#include <asm/processor.h>
#include <asm/mmu.h>
#include <asm/cache.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_pci.h>
#include <fsl_ddr_sdram.h>
#include <asm/fsl_serdes.h>
#include <asm/io.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <fsl_mdio.h>
#include <tsec.h>
#include <asm/fsl_law.h>
#include <netdev.h>
#include <i2c.h>
#include <hwconfig.h>
#include "../common/ngpixis.h"
#ifdef CONFIG_SYS_RAMBOOT
#endif
#define CONFIG_TFP410_I2C_ADDR	0x38
#define CONFIG_PIXIS_BRDCFG1_SSI_TDM_MASK	0x0c
#define CONFIG_PIXIS_BRDCFG1_AUDCLK_MASK	0x03
#define CONFIG_PIXIS_BRDCFG1_SSI_TDM_SSI	0x08
#define CONFIG_PIXIS_BRDCFG1_AUDCLK_12		0x02
#define CONFIG_PIXIS_BRDCFG1_AUDCLK_11		0x01
#define CONFIG_PIXIS_BRDCFG0_USB2		0x10
#define CONFIG_PIXIS_BRDCFG1_TDM		0x0c
#define CONFIG_PIXIS_BRDCFG0_SPI		0x80
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_TSEC1
#endif
#ifdef CONFIG_TSEC2
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#ifdef CONFIG_HAS_FSL_DR_USB
#endif
#ifdef CONFIG_FSL_SGMII_RISER
#endif
#endif
