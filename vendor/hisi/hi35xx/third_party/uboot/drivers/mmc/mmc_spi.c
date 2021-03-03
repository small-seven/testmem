#include <common.h>
#include <errno.h>
#include <malloc.h>
#include <part.h>
#include <mmc.h>
#include <stdlib.h>
#include <u-boot/crc.h>
#include <linux/crc7.h>
#include <asm/byteorder.h>
#include <dm.h>
#include <spi.h>
#define R1_SPI_IDLE			BIT(0)
#define R1_SPI_ERASE_RESET		BIT(1)
#define R1_SPI_ILLEGAL_COMMAND		BIT(2)
#define R1_SPI_COM_CRC			BIT(3)
#define R1_SPI_ERASE_SEQ		BIT(4)
#define R1_SPI_ADDRESS			BIT(5)
#define R1_SPI_PARAMETER		BIT(6)
#define R1_SPI_ERROR			BIT(7)
#define SPI_MMC_RESPONSE_CODE(x)	((x) & 0x1f)
#define SPI_RESPONSE_ACCEPTED		((2 << 1)|1)
#define SPI_RESPONSE_CRC_ERR		((5 << 1)|1)
#define SPI_RESPONSE_WRITE_ERR		((6 << 1)|1)
#define SPI_TOKEN_SINGLE		0xfe
#define SPI_TOKEN_MULTI_WRITE		0xfc
#define SPI_TOKEN_STOP_TRAN		0xfd
#define MMC_SPI_CMD(x) (0x40 | (x))
#define MMC_SPI_VOLTAGE			(MMC_VDD_32_33 | MMC_VDD_33_34)
#define MMC_SPI_MIN_CLOCK		400000	/* 400KHz to meet MMC spec */
#define MMC_SPI_MAX_CLOCK		25000000 /* SD/MMC legacy speed */
#define CMD_TIMEOUT			8
#define READ_TIMEOUT			3000000 /* 1 sec */
#define WRITE_TIMEOUT			3000000 /* 1 sec */
#ifdef CONFIG_MMC_SPI_CRC_ON
#endif
#ifdef CONFIG_MMC_SPI_CRC_ON
#endif
