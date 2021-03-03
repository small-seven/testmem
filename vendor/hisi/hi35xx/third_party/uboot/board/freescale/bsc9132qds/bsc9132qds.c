#include <common.h>
#include <init.h>
#include <asm/processor.h>
#include <asm/mmu.h>
#include <asm/cache.h>
#include <asm/immap_85xx.h>
#include <asm/io.h>
#include <env.h>
#include <miiphy.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <fsl_mdio.h>
#include <tsec.h>
#include <mmc.h>
#include <netdev.h>
#include <fsl_ifc.h>
#include <hwconfig.h>
#include <i2c.h>
#include <fsl_ddr_sdram.h>
#include <jffs2/load_kernel.h>
#include <mtd_node.h>
#include <flash.h>
#ifdef CONFIG_PCI
#include <pci.h>
#include <asm/fsl_pci.h>
#endif
#include "../common/qixis.h"
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#ifdef CONFIG_PCI
#endif /* ifdef CONFIG_PCI */
#ifdef CONFIG_TSEC_ENET
#ifdef CONFIG_TSEC1
#endif
#ifdef CONFIG_TSEC2
#endif
#endif
#define USBMUX_SEL_MASK		0xc0
#define USBMUX_SEL_UART2	0xc0
#define USBMUX_SEL_USB		0x40
#define SPIMUX_SEL_UART3	0x80
#define GPS_MUX_SEL_GPS		0x40
#define TSEC_1588_CLKIN_MASK	0x03
#define CON_XCVR_REF_CLK	0x00
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_FDT_FIXUP_PARTITIONS
#endif
#ifdef CONFIG_FDT_FIXUP_PARTITIONS
#endif
#endif
