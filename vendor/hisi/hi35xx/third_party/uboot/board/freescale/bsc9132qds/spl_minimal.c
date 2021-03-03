#include <common.h>
#include <ns16550.h>
#include <asm/io.h>
#include <nand.h>
#include <linux/compiler.h>
#include <asm/fsl_law.h>
#include <fsl_ddr_sdram.h>
#include <asm/global_data.h>
#if CONFIG_DDR_CLK_FREQ == 100000000
#elif CONFIG_DDR_CLK_FREQ == 133000000
#else
#endif
