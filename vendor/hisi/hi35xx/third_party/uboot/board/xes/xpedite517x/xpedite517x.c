#include <common.h>
#include <init.h>
#include <asm/processor.h>
#include <fsl_ddr_sdram.h>
#include <asm/mmu.h>
#include <asm/io.h>
#include <fdt_support.h>
#include <pca953x.h>
#include "../common/fsl_8xxx_misc.h"
#if defined(CONFIG_OF_BOARD_SETUP) && defined(CONFIG_PCI)
#endif
#if defined(CONFIG_DDR_ECC) && !defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_PCI
#endif
#endif
