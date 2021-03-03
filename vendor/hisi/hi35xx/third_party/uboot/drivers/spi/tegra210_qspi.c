#include <common.h>
#include <dm.h>
#include <time.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch-tegra/clk_rst.h>
#include <spi.h>
#include <fdtdec.h>
#include "tegra_spi.h"
#define QSPI_CMD1_GO			BIT(31)
#define QSPI_CMD1_M_S			BIT(30)
#define QSPI_CMD1_MODE_MASK		GENMASK(1,0)
#define QSPI_CMD1_MODE_SHIFT		28
#define QSPI_CMD1_CS_SEL_MASK		GENMASK(1,0)
#define QSPI_CMD1_CS_SEL_SHIFT		26
#define QSPI_CMD1_CS_POL_INACTIVE0	BIT(22)
#define QSPI_CMD1_CS_SW_HW		BIT(21)
#define QSPI_CMD1_CS_SW_VAL		BIT(20)
#define QSPI_CMD1_IDLE_SDA_MASK		GENMASK(1,0)
#define QSPI_CMD1_IDLE_SDA_SHIFT	18
#define QSPI_CMD1_BIDIR			BIT(17)
#define QSPI_CMD1_LSBI_FE		BIT(16)
#define QSPI_CMD1_LSBY_FE		BIT(15)
#define QSPI_CMD1_BOTH_EN_BIT		BIT(14)
#define QSPI_CMD1_BOTH_EN_BYTE		BIT(13)
#define QSPI_CMD1_RX_EN			BIT(12)
#define QSPI_CMD1_TX_EN			BIT(11)
#define QSPI_CMD1_PACKED		BIT(5)
#define QSPI_CMD1_BITLEN_MASK		GENMASK(4,0)
#define QSPI_CMD1_BITLEN_SHIFT		0
#define QSPI_CMD2_TX_CLK_TAP_DELAY	BIT(6)
#define QSPI_CMD2_TX_CLK_TAP_DELAY_MASK	GENMASK(11,6)
#define QSPI_CMD2_RX_CLK_TAP_DELAY	BIT(0)
#define QSPI_CMD2_RX_CLK_TAP_DELAY_MASK	GENMASK(5,0)
#define QSPI_XFER_STS_RDY		BIT(30)
#define QSPI_FIFO_STS_CS_INACTIVE	BIT(31)
#define QSPI_FIFO_STS_FRAME_END		BIT(30)
#define QSPI_FIFO_STS_RX_FIFO_FLUSH	BIT(15)
#define QSPI_FIFO_STS_TX_FIFO_FLUSH	BIT(14)
#define QSPI_FIFO_STS_ERR		BIT(8)
#define QSPI_FIFO_STS_TX_FIFO_OVF	BIT(7)
#define QSPI_FIFO_STS_TX_FIFO_UNR	BIT(6)
#define QSPI_FIFO_STS_RX_FIFO_OVF	BIT(5)
#define QSPI_FIFO_STS_RX_FIFO_UNR	BIT(4)
#define QSPI_FIFO_STS_TX_FIFO_FULL	BIT(3)
#define QSPI_FIFO_STS_TX_FIFO_EMPTY	BIT(2)
#define QSPI_FIFO_STS_RX_FIFO_FULL	BIT(1)
#define QSPI_FIFO_STS_RX_FIFO_EMPTY	BIT(0)
#define QSPI_TIMEOUT		1000