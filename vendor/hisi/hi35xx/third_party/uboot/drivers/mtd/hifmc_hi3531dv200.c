#include <common.h>
#include <asm/io.h>
#include <asm/arch/platform.h>
#include <hifmc_common.h>
#include "hifmc_spi_ids.h"
#define REG_IO_BASE_FMC 0x10ff0000
#define REG_SPI_CLK		(REG_IO_BASE_FMC + 0x24)
#define REG_SPI_MOSI_IO0	(REG_IO_BASE_FMC + 0x1C)
#define REG_SPI_MISO_IO1	(REG_IO_BASE_FMC + 0x28)
#define REG_SPI_WP_IO2		(REG_IO_BASE_FMC + 0x20)
#define REG_SPI_HOLD_IO3	(REG_IO_BASE_FMC + 0x2c)
#define REG_SFC_CS0N		(REG_IO_BASE_FMC + 0x30)
#define REG_SFC_CS1N		(REG_IO_BASE_FMC + 0x34)
#define SPI_CLK_VAL		0x000002d1
#define SPI_MOSI_IO0_VAL	0x000000d1
#define SPI_MISO_IO1_VAL	0x000000d1
#define SPI_WP_IO2_VAL		0x000000d1
#define SPI_HOLD_IO3_VAL	0x000000d1
#define SPI_SFC_CS0N_VAL	0x00000031
#define SPI_SFC_CS1N_VAL	0x00000031
#define CLK_2X(_clk)	(((_clk) + 1) >> 1)
#undef CLK_2X
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif
#ifdef CONFIG_DTR_MODE_SUPPORT
#define CLK_4X(_clk)	(((_clk) + 1) >> 2)
#undef CLK_4X
#endif/* CONFIG_DTR_MODE_SUPPORT */
