#include <common.h>
#include <command.h>
#include <init.h>
#include <pci.h>
#include <asm/processor.h>
#include <asm/immap_86xx.h>
#include <asm/fsl_pci.h>
#include <fsl_ddr_sdram.h>
#include <asm/fsl_serdes.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#if defined(CONFIG_SPD_EEPROM)
#else
#endif
#if defined(CONFIG_SYS_DRAM_TEST)
#endif
#if !defined(CONFIG_SPD_EEPROM)
#if !defined(CONFIG_SYS_RAMBOOT)
#endif
#endif				/* !defined(CONFIG_SPD_EEPROM) */
#if defined(CONFIG_PCI)
#endif /* CONFIG_PCI */
#if defined(CONFIG_OF_BOARD_SETUP)
#endif
#ifdef CONFIG_SYS_RESET_ADDRESS
#endif
