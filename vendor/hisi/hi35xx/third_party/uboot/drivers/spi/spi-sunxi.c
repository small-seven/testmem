#include <common.h>
#include <clk.h>
#include <dm.h>
#include <spi.h>
#include <errno.h>
#include <fdt_support.h>
#include <reset.h>
#include <wait_bit.h>
#include <asm/bitops.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <linux/iopoll.h>
#define SUN4I_RXDATA_REG		0x00
#define SUN4I_TXDATA_REG		0x04
#define SUN4I_CTL_REG			0x08
#define SUN4I_CLK_CTL_REG		0x1c
#define SUN4I_BURST_CNT_REG		0x20
#define SUN4I_XMIT_CNT_REG		0x24
#define SUN4I_FIFO_STA_REG		0x28
#define SUN6I_GBL_CTL_REG		0x04
#define SUN6I_TFR_CTL_REG		0x08
#define SUN6I_FIFO_CTL_REG		0x18
#define SUN6I_FIFO_STA_REG		0x1c
#define SUN6I_CLK_CTL_REG		0x24
#define SUN6I_BURST_CNT_REG		0x30
#define SUN6I_XMIT_CNT_REG		0x34
#define SUN6I_BURST_CTL_REG		0x38
#define SUN6I_TXDATA_REG		0x200
#define SUN6I_RXDATA_REG		0x300
#define SUN4I_CTL_ENABLE		BIT(0)
#define SUN4I_CTL_MASTER		BIT(1)
#define SUN4I_CLK_CTL_CDR2_MASK		0xff
#define SUN4I_CLK_CTL_CDR2(div)		((div) & SUN4I_CLK_CTL_CDR2_MASK)
#define SUN4I_CLK_CTL_CDR1_MASK		0xf
#define SUN4I_CLK_CTL_CDR1(div)		(((div) & SUN4I_CLK_CTL_CDR1_MASK) << 8)
#define SUN4I_CLK_CTL_DRS		BIT(12)
#define SUN4I_MAX_XFER_SIZE		0xffffff
#define SUN4I_BURST_CNT(cnt)		((cnt) & SUN4I_MAX_XFER_SIZE)
#define SUN4I_XMIT_CNT(cnt)		((cnt) & SUN4I_MAX_XFER_SIZE)
#define SUN4I_FIFO_STA_RF_CNT_BITS	0
#define SUN4I_SPI_MAX_RATE		24000000
#define SUN4I_SPI_MIN_RATE		3000
#define SUN4I_SPI_DEFAULT_RATE		1000000
#define SUN4I_SPI_TIMEOUT_US		1000000
#define SPI_REG(priv, reg)		((priv)->base + \
#define SPI_BIT(priv, bit)		((priv)->variant->bits[bit])
#define SPI_CS(priv, cs)		(((cs) << SPI_BIT(priv, SPI_TCR_CS_SEL)) & \
