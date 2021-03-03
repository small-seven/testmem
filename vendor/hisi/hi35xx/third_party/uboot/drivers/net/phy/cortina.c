#include <config.h>
#include <common.h>
#include <malloc.h>
#include <linux/ctype.h>
#include <linux/string.h>
#include <linux/err.h>
#include <phy.h>
#include <cortina.h>
#ifdef CONFIG_SYS_CORTINA_FW_IN_NAND
#include <nand.h>
#elif defined(CONFIG_SYS_CORTINA_FW_IN_SPIFLASH)
#include <spi_flash.h>
#elif defined(CONFIG_SYS_CORTINA_FW_IN_MMC)
#include <mmc.h>
#endif
#ifndef CONFIG_PHYLIB_10G
#error The Cortina PHY needs 10G support
#endif
#ifndef CORTINA_NO_FW_UPLOAD
#if defined(CONFIG_SYS_CORTINA_FW_IN_NOR) || \
#elif defined(CONFIG_SYS_CORTINA_FW_IN_NAND)
#elif defined(CONFIG_SYS_CORTINA_FW_IN_SPIFLASH)
#elif defined(CONFIG_SYS_CORTINA_FW_IN_MMC)
#ifdef CONFIG_BLK
#else
#endif
#endif
#endif
#ifndef CORTINA_NO_FW_UPLOAD
#endif
#ifndef CORTINA_NO_FW_UPLOAD
#endif
