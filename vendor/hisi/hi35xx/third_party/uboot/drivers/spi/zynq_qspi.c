#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <spi.h>
#include <asm/io.h>
#define ZYNQ_QSPI_CR_IFMODE_MASK	BIT(31)	/* Flash intrface mode*/
#define ZYNQ_QSPI_CR_MSA_MASK		BIT(15)	/* Manual start enb */
#define ZYNQ_QSPI_CR_MCS_MASK		BIT(14)	/* Manual chip select */
#define ZYNQ_QSPI_CR_PCS_MASK		BIT(10)	/* Peri chip select */
#define ZYNQ_QSPI_CR_FW_MASK		GENMASK(7, 6)	/* FIFO width */
#define ZYNQ_QSPI_CR_SS_MASK		GENMASK(13, 10)	/* Slave Select */
#define ZYNQ_QSPI_CR_BAUD_MASK		GENMASK(5, 3)	/* Baud rate div */
#define ZYNQ_QSPI_CR_CPHA_MASK		BIT(2)	/* Clock phase */
#define ZYNQ_QSPI_CR_CPOL_MASK		BIT(1)	/* Clock polarity */
#define ZYNQ_QSPI_CR_MSTREN_MASK	BIT(0)	/* Mode select */
#define ZYNQ_QSPI_IXR_RXNEMPTY_MASK	BIT(4)	/* RX_FIFO_not_empty */
#define ZYNQ_QSPI_IXR_TXOW_MASK		BIT(2)	/* TX_FIFO_not_full */
#define ZYNQ_QSPI_IXR_ALL_MASK		GENMASK(6, 0)	/* All IXR bits */
#define ZYNQ_QSPI_ENR_SPI_EN_MASK	BIT(0)	/* SPI Enable */
#define ZYNQ_QSPI_LQSPICFG_LQMODE_MASK	BIT(31) /* Linear QSPI Mode */
#define ZYNQ_QSPI_TXD_00_00_OFFSET	0x1C	/* Transmit 4-byte inst */
#define ZYNQ_QSPI_TXD_00_01_OFFSET	0x80	/* Transmit 1-byte inst */
#define ZYNQ_QSPI_TXD_00_10_OFFSET	0x84	/* Transmit 2-byte inst */
#define ZYNQ_QSPI_TXD_00_11_OFFSET	0x88	/* Transmit 3-byte inst */
#define ZYNQ_QSPI_TXFIFO_THRESHOLD	1	/* Tx FIFO threshold level*/
#define ZYNQ_QSPI_RXFIFO_THRESHOLD	32	/* Rx FIFO threshold level */
#define ZYNQ_QSPI_CR_BAUD_MAX		8	/* Baud rate divisor max val */
#define ZYNQ_QSPI_CR_BAUD_SHIFT		3	/* Baud rate divisor shift */
#define ZYNQ_QSPI_CR_SS_SHIFT		10	/* Slave select shift */
#define ZYNQ_QSPI_FIFO_DEPTH		63
#ifndef CONFIG_SYS_ZYNQ_QSPI_WAIT
#define CONFIG_SYS_ZYNQ_QSPI_WAIT	CONFIG_SYS_HZ/100	/* 10 ms */
#endif
