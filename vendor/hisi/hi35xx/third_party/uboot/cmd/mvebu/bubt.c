#include <config.h>
#include <common.h>
#include <command.h>
#include <env.h>
#include <vsprintf.h>
#include <errno.h>
#include <dm.h>
#include <spi_flash.h>
#include <spi.h>
#include <nand.h>
#include <usb.h>
#include <fs.h>
#include <mmc.h>
#ifdef CONFIG_BLK
#include <blk.h>
#endif
#include <u-boot/sha1.h>
#include <u-boot/sha256.h>
#ifndef CONFIG_SYS_MMC_ENV_DEV
#define CONFIG_SYS_MMC_ENV_DEV	0
#endif
#if defined(CONFIG_ARMADA_8K)
#define MAIN_HDR_MAGIC		0xB105B002
#elif defined(CONFIG_ARMADA_3700)	/* A3700 */
#define HASH_SUM_LEN		16
#define IMAGE_VERSION_3_6_0	0x030600
#define IMAGE_VERSION_3_5_0	0x030500
#endif /* CONFIG_ARMADA_XXX */
#if CONFIG_IS_ENABLED(DM_MMC) && CONFIG_IS_ENABLED(MMC_WRITE)
#ifdef CONFIG_BLK
#endif
#ifdef CONFIG_SYS_MMC_ENV_PART
#endif
#ifdef CONFIG_BLK
#else
#endif /* CONFIG_BLK */
#ifdef CONFIG_SYS_MMC_ENV_PART
#endif
#else /* CONFIG_DM_MMC */
#endif /* CONFIG_DM_MMC */
#ifdef CONFIG_SPI_FLASH
#ifdef CONFIG_SPI_FLASH_PROTECTION
#endif
#ifdef CONFIG_SPI_FLASH_PROTECTION
#endif
#else /* CONFIG_SPI_FLASH */
#endif /* CONFIG_SPI_FLASH */
#ifdef CONFIG_CMD_NAND
#else /* CONFIG_CMD_NAND */
#endif /* CONFIG_CMD_NAND */
#if defined(CONFIG_USB_STORAGE) && defined(CONFIG_BLK)
#else /* defined(CONFIG_USB_STORAGE) && defined (CONFIG_BLK) */
#endif /* defined(CONFIG_USB_STORAGE) && defined (CONFIG_BLK) */
#ifdef CONFIG_CMD_NET
#else
#endif /* CONFIG_CMD_NET */
#if defined(CONFIG_ARMADA_8K)
#elif defined(CONFIG_ARMADA_3700) /* Armada 3700 */
#else /* Not ARMADA? */
#endif
#define DEFAULT_BUBT_SRC "tftp"
#ifndef DEFAULT_BUBT_DST
#ifdef CONFIG_MVEBU_SPI_BOOT
#define DEFAULT_BUBT_DST "spi"
#elif defined(CONFIG_MVEBU_NAND_BOOT)
#define DEFAULT_BUBT_DST "nand"
#elif defined(CONFIG_MVEBU_MMC_BOOT)
#define DEFAULT_BUBT_DST "mmc"
#define DEFAULT_BUBT_DST "error"
#endif
#endif /* DEFAULT_BUBT_DST */
