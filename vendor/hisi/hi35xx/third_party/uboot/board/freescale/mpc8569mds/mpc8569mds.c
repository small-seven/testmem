#include <common.h>
#include <console.h>
#include <hwconfig.h>
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
#include <spd_sdram.h>
#include <i2c.h>
#include <ioports.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <fsl_esdhc.h>
#include <phy.h>
#include "bcsr.h"
#if defined(CONFIG_PQ_MDS_PIB)
#include "../common/pq-mds-pib.h"
#endif
#if defined(CONFIG_SYS_UCC_RGMII_MODE)
#elif defined(CONFIG_SYS_UCC_RMII_MODE)
#endif
#ifdef CONFIG_QE
#endif
#if CONFIG_SYS_I2C2_OFFSET
#endif
#if !defined(CONFIG_SPD_EEPROM)
#if defined (CONFIG_DDR_ECC)
#endif
#if defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif
#endif
#ifdef CONFIG_FSL_ESDHC
#else
#endif
#ifdef CONFIG_PCI
#if defined(CONFIG_PQ_MDS_PIB)
#endif
#endif /* CONFIG_PCI */
#if defined(CONFIG_OF_BOARD_SETUP)
#if defined(CONFIG_SYS_UCC_RMII_MODE)
#endif
#endif
