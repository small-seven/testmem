#include <common.h>
#include <init.h>
#include <pci.h>
#include <asm/processor.h>
#include <asm/immap_86xx.h>
#include <asm/fsl_pci.h>
#include <fsl_ddr_sdram.h>
#include <asm/fsl_serdes.h>
#include <asm/io.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <netdev.h>
#if defined(CONFIG_SPD_EEPROM)
#else
#endif
#if !defined(CONFIG_SPD_EEPROM)
#if !defined(CONFIG_SYS_RAMBOOT)
#if defined (CONFIG_DDR_ECC)
#endif
#if defined (CONFIG_DDR_ECC)
#else
#endif
#endif
#endif	/* !defined(CONFIG_SPD_EEPROM) */
#ifdef CONFIG_PCIE1
#endif /* CONFIG_PCIE1 */
#if defined(CONFIG_OF_BOARD_SETUP)
#endif
