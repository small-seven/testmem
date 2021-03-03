#include <common.h>
#include <lcd.h>
#include <linux/err.h>
#include <asm/arch/dsim.h>
#include <asm/arch/mipi_dsim.h>
#include "exynos_mipi_dsi_lowlevel.h"
#define MHZ			(1000 * 1000)
#define FIN_HZ			(24 * MHZ)
#define DFIN_PLL_MIN_HZ		(6 * MHZ)
#define DFIN_PLL_MAX_HZ		(12 * MHZ)
#define DFVCO_MIN_HZ		(500 * MHZ)
#define DFVCO_MAX_HZ		(1000 * MHZ)
#define TRY_GET_FIFO_TIMEOUT	(5000 * 2)
