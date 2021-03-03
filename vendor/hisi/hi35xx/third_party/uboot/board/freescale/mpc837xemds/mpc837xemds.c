#include <common.h>
#include <hwconfig.h>
#include <i2c.h>
#include <init.h>
#include <asm/io.h>
#include <asm/fsl_mpc83xx_serdes.h>
#include <spd_sdram.h>
#include <tsec.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <fsl_esdhc.h>
#include <fsl_mdio.h>
#include <phy.h>
#include "pci.h"
#include "../common/pq-mds-pib.h"
#ifdef CONFIG_FSL_SERDES
#endif /* CONFIG_FSL_SERDES */
#ifdef CONFIG_FSL_ESDHC
#endif
#if defined(CONFIG_TSEC1) || defined(CONFIG_TSEC2)
#ifdef CONFIG_TSEC1
#endif
#ifdef CONFIG_TSEC2
#endif
#ifdef CONFIG_TSEC1
#endif
#ifdef CONFIG_TSEC2
#endif
#else
#endif /* defined(CONFIG_TSEC1) || defined(CONFIG_TSEC2) */
#ifdef CONFIG_PQ_MDS_PIB
#endif
#if defined(CONFIG_DDR_ECC) && !defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif
#if defined(CONFIG_SPD_EEPROM)
#else
#endif
#if defined(CONFIG_DDR_ECC) && !defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif
#if !defined(CONFIG_SPD_EEPROM)
#if (CONFIG_SYS_DDR_SIZE != 512)
#warning Currenly any ddr size other than 512 is not supported
#endif
#endif /*!CONFIG_SYS_SPD_EEPROM */
#ifdef CONFIG_PCI
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_PCI
#endif
#endif /* CONFIG_OF_BOARD_SETUP */
