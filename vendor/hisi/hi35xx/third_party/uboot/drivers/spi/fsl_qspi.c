#include <common.h>
#include <malloc.h>
#include <spi.h>
#include <asm/io.h>
#include <linux/sizes.h>
#include <linux/iopoll.h>
#include <dm.h>
#include <errno.h>
#include <watchdog.h>
#include <wait_bit.h>
#include "fsl_qspi.h"
#define OFFSET_BITS_MASK	GENMASK(23, 0)
#define FLASH_STATUS_WEL	0x02
#define SEQID_WREN		1
#define SEQID_FAST_READ		2
#define SEQID_RDSR		3
#define SEQID_SE		4
#define SEQID_CHIP_ERASE	5
#define SEQID_PP		6
#define SEQID_RDID		7
#define SEQID_BE_4K		8
#ifdef CONFIG_SPI_FLASH_BAR
#define SEQID_BRRD		9
#define SEQID_BRWR		10
#define SEQID_RDEAR		11
#define SEQID_WREAR		12
#endif
#define SEQID_WRAR		13
#define SEQID_RDAR		14
#define QSPI_CMD_PP		0x02	/* Page program (up to 256 bytes) */
#define QSPI_CMD_RDSR		0x05	/* Read status register */
#define QSPI_CMD_WREN		0x06	/* Write enable */
#define QSPI_CMD_FAST_READ	0x0b	/* Read data bytes (high frequency) */
#define QSPI_CMD_BE_4K		0x20    /* 4K erase */
#define QSPI_CMD_CHIP_ERASE	0xc7	/* Erase whole flash chip */
#define QSPI_CMD_SE		0xd8	/* Sector erase (usually 64KiB) */
#define QSPI_CMD_RDID		0x9f	/* Read JEDEC ID */
#define	QSPI_CMD_WREAR		0xc5	/* EAR register write */
#define	QSPI_CMD_RDEAR		0xc8	/* EAR reigster read */
#define	QSPI_CMD_BRRD		0x16	/* Bank register read */
#define	QSPI_CMD_BRWR		0x17	/* Bank register write */
#define QSPI_CMD_RDAR		0x65	/* Read any device register */
#define QSPI_CMD_WRAR		0x71	/* Write any device register */
#define QSPI_CMD_FAST_READ_4B	0x0c    /* Read data bytes (high frequency) */
#define QSPI_CMD_PP_4B		0x12    /* Page program (up to 256 bytes) */
#define QSPI_CMD_SE_4B		0xdc    /* Sector erase (usually 64KiB) */
#define QSPI_FLAG_REGMAP_ENDIAN_BIG	BIT(0)
#define FSL_QSPI_DEFAULT_SCK_FREQ	50000000
#define FSL_QSPI_MAX_CHIPSELECT_NUM     4
#define QUADSPI_QUIRK_SWAP_ENDIAN	BIT(0)
#ifdef CONFIG_SPI_FLASH_BAR
#else
#endif
#ifdef CONFIG_SPI_FLASH_BAR
#else
#endif
#ifdef CONFIG_SPI_FLASH_BAR
#else
#endif
#ifdef CONFIG_SPI_FLASH_BAR
#endif
#if defined(CONFIG_SYS_FSL_QSPI_AHB)
#endif
#ifdef CONFIG_SPI_FLASH_BAR
#endif
#ifdef CONFIG_SPI_FLASH_BAR
#endif
#ifdef CONFIG_SPI_FLASH_BAR
#endif
#ifdef CONFIG_SYS_FSL_QSPI_AHB
#else
#endif
#ifdef CONFIG_SPI_FLASH_BAR
#endif
#ifdef CONFIG_SYS_FSL_QSPI_AHB
#endif
#ifdef CONFIG_SYS_FSL_QSPI_AHB
#endif
