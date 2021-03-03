#include <common.h>
#include <ns16550.h>
#include <asm/io.h>
#include <nand.h>
#include <linux/compiler.h>
#include <asm/fsl_law.h>
#include <fsl_ddr_sdram.h>
#include <asm/global_data.h>
#if CONFIG_CHIP_SELECTS_PER_CTRL > 1
#endif
