#include <config.h>
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <spi.h>
#include <asm/io.h>
#include <wait_bit.h>
#define SPICR_LSB_FIRST		BIT(9)
#define SPICR_MASTER_INHIBIT	BIT(8)
#define SPICR_MANUAL_SS		BIT(7)
#define SPICR_RXFIFO_RESEST	BIT(6)
#define SPICR_TXFIFO_RESEST	BIT(5)
#define SPICR_CPHA		BIT(4)
#define SPICR_CPOL		BIT(3)
#define SPICR_MASTER_MODE	BIT(2)
#define SPICR_SPE		BIT(1)
#define SPICR_LOOP		BIT(0)
#define SPISR_SLAVE_MODE_SELECT	BIT(5)
#define SPISR_MODF		BIT(4)
#define SPISR_TX_FULL		BIT(3)
#define SPISR_TX_EMPTY		BIT(2)
#define SPISR_RX_FULL		BIT(1)
#define SPISR_RX_EMPTY		BIT(0)
#define SPIDTR_8BIT_MASK	GENMASK(7, 0)
#define SPIDTR_16BIT_MASK	GENMASK(15, 0)
#define SPIDTR_32BIT_MASK	GENMASK(31, 0)
#define SPIDRR_8BIT_MASK	GENMASK(7, 0)
#define SPIDRR_16BIT_MASK	GENMASK(15, 0)
#define SPIDRR_32BIT_MASK	GENMASK(31, 0)
#define SPISSR_MASK(cs)		(1 << (cs))
#define SPISSR_ACT(cs)		~SPISSR_MASK(cs)
#define SPISSR_OFF		~0UL
#define SPISSR_RESET_VALUE	0x0a
#define XILSPI_MAX_XFER_BITS	8
#define XILSPI_SPICR_DFLT_ON	(SPICR_MANUAL_SS | SPICR_MASTER_MODE | \
#define XILSPI_SPICR_DFLT_OFF	(SPICR_MASTER_INHIBIT | SPICR_MANUAL_SS)
#ifndef CONFIG_XILINX_SPI_IDLE_VAL
#define CONFIG_XILINX_SPI_IDLE_VAL	GENMASK(7, 0)
#endif
#define XILINX_SPISR_TIMEOUT	10000 /* in milliseconds */
