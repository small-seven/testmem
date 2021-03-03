#include <clk.h>
#include <common.h>
#include <spl.h>
#include "init.h"
#if defined(CONFIG_SPL_SPI_SUPPORT)
#elif defined(CONFIG_SPL_MMC_SUPPORT)
#elif defined(CONFIG_SPL_NAND_SUPPORT)
#elif defined(CONFIG_SPL_NOR_SUPPORT)
#else
#endif
