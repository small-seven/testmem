#include <common.h>
#include <mpc85xx.h>
#include <asm/io.h>
#include <ns16550.h>
#include <nand.h>
#include <asm/mmu.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_law.h>
#include <asm/global_data.h>
#if defined(CONFIG_SYS_NAND_BR_PRELIM) && defined(CONFIG_SYS_NAND_OR_PRELIM)
#endif
