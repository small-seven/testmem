#include <common.h>
#include <env.h>
#include <hwconfig.h>
#include <i2c.h>
#include <asm/io.h>
#include <asm/fsl_mpc83xx_serdes.h>
#include <fdt_support.h>
#include <spd_sdram.h>
#include <vsc7385.h>
#include <fsl_esdhc.h>
#if defined(CONFIG_SYS_DRAM_TEST)
#endif
#if defined(CONFIG_DDR_ECC) && !defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif
#if defined(CONFIG_SPD_EEPROM)
#else
#endif
#if defined(CONFIG_DDR_ECC) && !defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif
#if !defined(CONFIG_SPD_EEPROM)
#endif	/*!CONFIG_SYS_SPD_EEPROM */
#ifdef CONFIG_FSL_SERDES
#endif /* CONFIG_FSL_SERDES */
#ifdef CONFIG_FSL_ESDHC
#endif
#ifdef CONFIG_VSC7385_IMAGE
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_PCI
#endif
#endif /* CONFIG_OF_BOARD_SETUP */
