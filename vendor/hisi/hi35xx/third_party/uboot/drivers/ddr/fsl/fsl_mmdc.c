#include <common.h>
#include <fsl_mmdc.h>
#include <asm/io.h>
#if (CONFIG_CHIP_SELECTS_PER_CTRL == 1)
#elif (CONFIG_CHIP_SELECTS_PER_CTRL == 2)
#endif
