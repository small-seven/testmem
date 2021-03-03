#include <common.h>
#include <init.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <dm.h>
#include <clk.h>
#include <env.h>
#include <spi.h>
#include <mvebu/comphy.h>
#include <miiphy.h>
#include <linux/string.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include "mox_sp.h"
#define MAX_MOX_MODULES		10
#define MOX_MODULE_SFP		0x1
#define MOX_MODULE_PCI		0x2
#define MOX_MODULE_TOPAZ	0x3
#define MOX_MODULE_PERIDOT	0x4
#define MOX_MODULE_USB3		0x5
#define MOX_MODULE_PASSPCI	0x6
#define ARMADA_37XX_NB_GPIO_SEL	0xd0013830
#define ARMADA_37XX_SPI_CTRL	0xd0010600
#define ARMADA_37XX_SPI_CFG	0xd0010604
#define ARMADA_37XX_SPI_DOUT	0xd0010608
#define ARMADA_37XX_SPI_DIN	0xd001060c
#define PCIE_PATH	"/soc/pcie@d0070000"
#if defined(CONFIG_OF_BOARD_FIXUP)
#endif
#define SW_SMI_CMD_R(d, r)	(0x9800 | (((d) & 0x1f) << 5) | ((r) & 0x1f))
#define SW_SMI_CMD_W(d, r)	(0x9400 | (((d) & 0x1f) << 5) | ((r) & 0x1f))
