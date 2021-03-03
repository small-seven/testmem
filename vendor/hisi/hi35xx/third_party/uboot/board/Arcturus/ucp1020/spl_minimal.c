#include <common.h>
#include <ns16550.h>
#include <asm/io.h>
#include <nand.h>
#include <linux/compiler.h>
#include <asm/fsl_law.h>
#include <fsl_ddr_sdram.h>
#include <asm/global_data.h>
#if defined(CONFIG_SYS_NAND_BR_PRELIM) && defined(CONFIG_SYS_NAND_OR_PRELIM)
#endif
