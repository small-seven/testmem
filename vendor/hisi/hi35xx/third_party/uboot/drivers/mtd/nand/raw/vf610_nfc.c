#include <common.h>
#include <malloc.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/rawnand.h>
#include <linux/mtd/partitions.h>
#include <nand.h>
#include <errno.h>
#include <asm/io.h>
#if CONFIG_NAND_VF610_NFC_DT
#include <dm.h>
#include <linux/io.h>
#include <linux/ioport.h>
#endif
#define NFC_FLASH_CMD1			0x3F00
#define NFC_FLASH_CMD2			0x3F04
#define NFC_COL_ADDR			0x3F08
#define NFC_ROW_ADDR			0x3F0c
#define NFC_ROW_ADDR_INC		0x3F14
#define NFC_FLASH_STATUS1		0x3F18
#define NFC_FLASH_STATUS2		0x3F1c
#define NFC_CACHE_SWAP			0x3F28
#define NFC_SECTOR_SIZE			0x3F2c
#define NFC_FLASH_CONFIG		0x3F30
#define NFC_IRQ_STATUS			0x3F38
#define NFC_MAIN_AREA(n)		((n) *  0x1000)
#define PAGE_2K				0x0800
#define OOB_64				0x0040
#define OOB_MAX				0x0100
#define READ_PAGE_CMD_CODE		0x7EE0
#define READ_ONFI_PARAM_CMD_CODE	0x4860
#define PROGRAM_PAGE_CMD_CODE		0x7FC0
#define ERASE_CMD_CODE			0x4EC0
#define READ_ID_CMD_CODE		0x4804
#define RESET_CMD_CODE			0x4040
#define STATUS_READ_CMD_CODE		0x4068
#define ECC_BYPASS			0
#define ECC_45_BYTE			6
#define ECC_60_BYTE			7
#define CMD_BYTE2_MASK				0xFF000000
#define CMD_BYTE2_SHIFT				24
#define CMD_BYTE1_MASK				0xFF000000
#define CMD_BYTE1_SHIFT				24
#define CMD_CODE_MASK				0x00FFFF00
#define CMD_CODE_SHIFT				8
#define BUFNO_MASK				0x00000006
#define BUFNO_SHIFT				1
#define START_BIT				(1<<0)
#define COL_ADDR_MASK				0x0000FFFF
#define COL_ADDR_SHIFT				0
#define ROW_ADDR_MASK				0x00FFFFFF
#define ROW_ADDR_SHIFT				0
#define ROW_ADDR_CHIP_SEL_RB_MASK		0xF0000000
#define ROW_ADDR_CHIP_SEL_RB_SHIFT		28
#define ROW_ADDR_CHIP_SEL_MASK			0x0F000000
#define ROW_ADDR_CHIP_SEL_SHIFT			24
#define STATUS_BYTE1_MASK			0x000000FF
#define CONFIG_ECC_SRAM_ADDR_MASK		0x7FC00000
#define CONFIG_ECC_SRAM_ADDR_SHIFT		22
#define CONFIG_ECC_SRAM_REQ_BIT			(1<<21)
#define CONFIG_DMA_REQ_BIT			(1<<20)
#define CONFIG_ECC_MODE_MASK			0x000E0000
#define CONFIG_ECC_MODE_SHIFT			17
#define CONFIG_FAST_FLASH_BIT			(1<<16)
#define CONFIG_16BIT				(1<<7)
#define CONFIG_BOOT_MODE_BIT			(1<<6)
#define CONFIG_ADDR_AUTO_INCR_BIT		(1<<5)
#define CONFIG_BUFNO_AUTO_INCR_BIT		(1<<4)
#define CONFIG_PAGE_CNT_MASK			0xF
#define CONFIG_PAGE_CNT_SHIFT			0
#define IDLE_IRQ_BIT				(1<<29)
#define IDLE_EN_BIT				(1<<20)
#define CMD_DONE_CLEAR_BIT			(1<<18)
#define IDLE_CLEAR_BIT				(1<<17)
#define NFC_TIMEOUT	(1000)
#define ECC_SRAM_ADDR		(PAGE_2K + OOB_MAX - 8)
#define ECC_STATUS		0x4
#define ECC_STATUS_MASK		0x80
#define ECC_STATUS_ERR_COUNT	0x3F
#define mtd_to_nfc(_mtd) nand_get_controller_data(mtd_to_nand(_mtd))
#if defined(CONFIG_SYS_NAND_VF610_NFC_45_ECC_BYTES)
#define ECC_HW_MODE ECC_45_BYTE
#elif defined(CONFIG_SYS_NAND_VF610_NFC_60_ECC_BYTES)
#define ECC_HW_MODE ECC_60_BYTE
#endif
static inline void vf610_nfc_memcpy(void *dst, const void *src, size_t n)
{
	/*
	 * Use this accessor for the internal SRAM buffers. On the ARM
	 * Freescale Vybrid SoC it's known that the driver can treat
	 * the SRAM buffer as if it's memory. Other platform might need
	 * to treat the buffers differently.
	 *
	 * For the time being, use memcpy
	 */
	memcpy(dst, src, n);
}
#ifdef __LITTLE_ENDIAN
#endif
#ifdef CONFIG_VF610
#endif
#ifdef CONFIG_SYS_NAND_BUSWIDTH_16BIT
#else
#endif
#if defined(CONFIG_SYS_NAND_VF610_NFC_45_ECC_BYTES)
#elif defined(CONFIG_SYS_NAND_VF610_NFC_60_ECC_BYTES)
#endif
#if CONFIG_NAND_VF610_NFC_DT
#else
#endif /* CONFIG_NAND_VF610_NFC_DT */
