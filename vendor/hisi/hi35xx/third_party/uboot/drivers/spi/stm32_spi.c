#include <common.h>
#include <clk.h>
#include <dm.h>
#include <errno.h>
#include <reset.h>
#include <spi.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <linux/bitfield.h>
#include <linux/iopoll.h>
#define STM32_SPI_CR1		0x00
#define STM32_SPI_CR2		0x04
#define STM32_SPI_CFG1		0x08
#define STM32_SPI_CFG2		0x0C
#define STM32_SPI_SR		0x14
#define STM32_SPI_IFCR		0x18
#define STM32_SPI_TXDR		0x20
#define STM32_SPI_RXDR		0x30
#define STM32_SPI_I2SCFGR	0x50
#define SPI_CR1_SPE		BIT(0)
#define SPI_CR1_MASRX		BIT(8)
#define SPI_CR1_CSTART		BIT(9)
#define SPI_CR1_CSUSP		BIT(10)
#define SPI_CR1_HDDIR		BIT(11)
#define SPI_CR1_SSI		BIT(12)
#define SPI_CR2_TSIZE		GENMASK(15, 0)
#define SPI_CFG1_DSIZE		GENMASK(4, 0)
#define SPI_CFG1_DSIZE_MIN	3
#define SPI_CFG1_FTHLV_SHIFT	5
#define SPI_CFG1_FTHLV		GENMASK(8, 5)
#define SPI_CFG1_MBR_SHIFT	28
#define SPI_CFG1_MBR		GENMASK(30, 28)
#define SPI_CFG1_MBR_MIN	0
#define SPI_CFG1_MBR_MAX	FIELD_GET(SPI_CFG1_MBR, SPI_CFG1_MBR)
#define SPI_CFG2_COMM_SHIFT	17
#define SPI_CFG2_COMM		GENMASK(18, 17)
#define SPI_CFG2_MASTER		BIT(22)
#define SPI_CFG2_LSBFRST	BIT(23)
#define SPI_CFG2_CPHA		BIT(24)
#define SPI_CFG2_CPOL		BIT(25)
#define SPI_CFG2_SSM		BIT(26)
#define SPI_CFG2_AFCNTR		BIT(31)
#define SPI_SR_RXP		BIT(0)
#define SPI_SR_TXP		BIT(1)
#define SPI_SR_EOT		BIT(3)
#define SPI_SR_TXTF		BIT(4)
#define SPI_SR_OVR		BIT(6)
#define SPI_SR_SUSP		BIT(11)
#define SPI_SR_RXPLVL_SHIFT	13
#define SPI_SR_RXPLVL		GENMASK(14, 13)
#define SPI_SR_RXWNE		BIT(15)
#define SPI_IFCR_ALL		GENMASK(11, 3)
#define SPI_I2SCFGR_I2SMOD	BIT(0)
#define MAX_CS_COUNT	4
#define STM32_MBR_DIV_MIN	(2 << SPI_CFG1_MBR_MIN)
#define STM32_MBR_DIV_MAX	(2 << SPI_CFG1_MBR_MAX)
#define STM32_SPI_TIMEOUT_US	100000
#define SPI_FULL_DUPLEX		0
#define SPI_SIMPLEX_TX		1
#define SPI_SIMPLEX_RX		2
#define SPI_HALF_DUPLEX		3
static int stm32_spi_remove(struct udevice *dev)
{
	struct stm32_spi_priv *priv = dev_get_priv(dev);
	int ret;

	stm32_spi_stopxfer(dev);
	stm32_spi_disable(priv);

	ret = reset_assert(&priv->rst_ctl);
	if (ret < 0)
		return ret;

	reset_free(&priv->rst_ctl);

	ret = clk_disable(&priv->clk);
	if (ret < 0)
		return ret;

	clk_free(&priv->clk);

	return ret;
};
