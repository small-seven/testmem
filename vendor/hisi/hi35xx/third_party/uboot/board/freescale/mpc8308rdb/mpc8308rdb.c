#include <common.h>
#include <hwconfig.h>
#include <i2c.h>
#include <init.h>
#include <spi.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <pci.h>
#include <mpc83xx.h>
#include <vsc7385.h>
#include <netdev.h>
#include <fsl_esdhc.h>
#include <asm/io.h>
#include <asm/fsl_serdes.h>
#include <asm/fsl_mpc83xx_serdes.h>
#ifdef CONFIG_MPC8XXX_SPI
#define SPI_CS_MASK	0x00400000
#endif /* CONFIG_MPC8XXX_SPI */
#ifdef CONFIG_FSL_ESDHC
#endif
#ifdef CONFIG_MPC8XXX_SPI
#endif
#ifdef CONFIG_VSC7385_IMAGE
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#endif
