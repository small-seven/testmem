#include <asm/io.h>
#include <command.h>
#include <config.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <linux/bitops.h>
#include <linux/delay.h>
#include <log.h>
#include <malloc.h>
#include <spi.h>
#include <time.h>
#define SPBR_MIN		8
#define BITS_PER_WORD		8
#define NUM_TXRAM		32
#define NUM_RXRAM		32
#define NUM_CDRAM		16
#define HIF_MSPI_SPCR2_CONT_AFTER_CMD_MASK	0x00000080
#define HIF_MSPI_SPCR2_SPE_MASK			0x00000040
#define HIF_MSPI_SPCR2_SPIFIE_MASK		0x00000020
#define HIF_MSPI_WRITE_LOCK_WRITE_LOCK_MASK	0x00000001
#define BSPI_MAST_N_BOOT_CTRL			0x008
#define HIF_SPI_INTR2_CPU_CLEAR			0x08
#define HIF_SPI_INTR2_CPU_MASK_SET		0x10
#define HIF_SPI_INTR2_CPU_MASK_CLEAR		0x14
#define HIF_SPI_INTR2_CPU_SET_MSPI_DONE_MASK	0x00000020
#define HIF_MSPI_WAIT				10
