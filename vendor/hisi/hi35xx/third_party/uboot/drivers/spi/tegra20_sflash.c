#include <common.h>
#include <dm.h>
#include <errno.h>
#include <time.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/clock.h>
#include <asm/arch/pinmux.h>
#include <asm/arch-tegra/clk_rst.h>
#include <spi.h>
#include <fdtdec.h>
#include "tegra_spi.h"
#define SPI_CMD_GO			BIT(30)
#define SPI_CMD_ACTIVE_SCLK_SHIFT	26
#define SPI_CMD_ACTIVE_SCLK_MASK	(3 << SPI_CMD_ACTIVE_SCLK_SHIFT)
#define SPI_CMD_CK_SDA			BIT(21)
#define SPI_CMD_ACTIVE_SDA_SHIFT	18
#define SPI_CMD_ACTIVE_SDA_MASK		(3 << SPI_CMD_ACTIVE_SDA_SHIFT)
#define SPI_CMD_CS_POL			BIT(16)
#define SPI_CMD_TXEN			BIT(15)
#define SPI_CMD_RXEN			BIT(14)
#define SPI_CMD_CS_VAL			BIT(13)
#define SPI_CMD_CS_SOFT			BIT(12)
#define SPI_CMD_CS_DELAY		BIT(9)
#define SPI_CMD_CS3_EN			BIT(8)
#define SPI_CMD_CS2_EN			BIT(7)
#define SPI_CMD_CS1_EN			BIT(6)
#define SPI_CMD_CS0_EN			BIT(5)
#define SPI_CMD_BIT_LENGTH		BIT(4)
#define SPI_CMD_BIT_LENGTH_MASK		GENMASK(4, 0)
#define SPI_STAT_BSY			BIT(31)
#define SPI_STAT_RDY			BIT(30)
#define SPI_STAT_RXF_FLUSH		BIT(29)
#define SPI_STAT_TXF_FLUSH		BIT(28)
#define SPI_STAT_RXF_UNR		BIT(27)
#define SPI_STAT_TXF_OVF		BIT(26)
#define SPI_STAT_RXF_EMPTY		BIT(25)
#define SPI_STAT_RXF_FULL		BIT(24)
#define SPI_STAT_TXF_EMPTY		BIT(23)
#define SPI_STAT_TXF_FULL		BIT(22)
#define SPI_STAT_SEL_TXRX_N		BIT(16)
#define SPI_STAT_CUR_BLKCNT		BIT(15)
#define SPI_TIMEOUT		1000
#define TEGRA_SPI_MAX_FREQ	52000000
