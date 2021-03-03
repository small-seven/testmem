#include <common.h>
#include <dm.h>
#include <time.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch-tegra/clk_rst.h>
#include <spi.h>
#include <fdtdec.h>
#include "tegra_spi.h"
#define SLINK_CMD_ENB			BIT(31)
#define SLINK_CMD_GO			BIT(30)
#define SLINK_CMD_M_S			BIT(28)
#define SLINK_CMD_IDLE_SCLK_DRIVE_LOW	(0 << 24)
#define SLINK_CMD_IDLE_SCLK_DRIVE_HIGH	BIT(24)
#define SLINK_CMD_IDLE_SCLK_PULL_LOW	(2 << 24)
#define SLINK_CMD_IDLE_SCLK_PULL_HIGH	(3 << 24)
#define SLINK_CMD_IDLE_SCLK_MASK	(3 << 24)
#define SLINK_CMD_CK_SDA		BIT(21)
#define SLINK_CMD_CS_POL		BIT(13)
#define SLINK_CMD_CS_VAL		BIT(12)
#define SLINK_CMD_CS_SOFT		BIT(11)
#define SLINK_CMD_BIT_LENGTH		BIT(4)
#define SLINK_CMD_BIT_LENGTH_MASK	GENMASK(4, 0)
#define SLINK_CMD2_TXEN			BIT(30)
#define SLINK_CMD2_RXEN			BIT(31)
#define SLINK_CMD2_SS_EN		BIT(18)
#define SLINK_CMD2_SS_EN_SHIFT		18
#define SLINK_CMD2_SS_EN_MASK		GENMASK(19, 18)
#define SLINK_CMD2_CS_ACTIVE_BETWEEN	BIT(17)
#define SLINK_STAT_BSY			BIT(31)
#define SLINK_STAT_RDY			BIT(30)
#define SLINK_STAT_ERR			BIT(29)
#define SLINK_STAT_RXF_FLUSH		BIT(27)
#define SLINK_STAT_TXF_FLUSH		BIT(26)
#define SLINK_STAT_RXF_OVF		BIT(25)
#define SLINK_STAT_TXF_UNR		BIT(24)
#define SLINK_STAT_RXF_EMPTY		BIT(23)
#define SLINK_STAT_RXF_FULL		BIT(22)
#define SLINK_STAT_TXF_EMPTY		BIT(21)
#define SLINK_STAT_TXF_FULL		BIT(20)
#define SLINK_STAT_TXF_OVF		BIT(19)
#define SLINK_STAT_RXF_UNR		BIT(18)
#define SLINK_STAT_CUR_BLKCNT		BIT(15)
#define SLINK_STAT2_RXF_FULL_CNT	BIT(16)
#define SLINK_STAT2_TXF_FULL_CNT	BIT(0)
#define SPI_TIMEOUT		1000
#define TEGRA_SPI_MAX_FREQ	52000000
