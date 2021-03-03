#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <spi.h>
#include <time.h>
#include <asm/io.h>
#define ZYNQ_SPI_CR_MSA_MASK		BIT(15)	/* Manual start enb */
#define ZYNQ_SPI_CR_MCS_MASK		BIT(14)	/* Manual chip select */
#define ZYNQ_SPI_CR_CS_MASK		GENMASK(13, 10)	/* Chip select */
#define ZYNQ_SPI_CR_BAUD_MASK		GENMASK(5, 3)	/* Baud rate div */
#define ZYNQ_SPI_CR_CPHA_MASK		BIT(2)	/* Clock phase */
#define ZYNQ_SPI_CR_CPOL_MASK		BIT(1)	/* Clock polarity */
#define ZYNQ_SPI_CR_MSTREN_MASK		BIT(0)	/* Mode select */
#define ZYNQ_SPI_IXR_RXNEMPTY_MASK	BIT(4)	/* RX_FIFO_not_empty */
#define ZYNQ_SPI_IXR_TXOW_MASK		BIT(2)	/* TX_FIFO_not_full */
#define ZYNQ_SPI_IXR_ALL_MASK		GENMASK(6, 0)	/* All IXR bits */
#define ZYNQ_SPI_ENR_SPI_EN_MASK	BIT(0)	/* SPI Enable */
#define ZYNQ_SPI_CR_BAUD_MAX		8	/* Baud rate divisor max val */
#define ZYNQ_SPI_CR_BAUD_SHIFT		3	/* Baud rate divisor shift */
#define ZYNQ_SPI_CR_SS_SHIFT		10	/* Slave select shift */
#define ZYNQ_SPI_FIFO_DEPTH		128
#ifndef CONFIG_SYS_ZYNQ_SPI_WAIT
#define CONFIG_SYS_ZYNQ_SPI_WAIT	(CONFIG_SYS_HZ/100)	/* 10 ms */
#endif
