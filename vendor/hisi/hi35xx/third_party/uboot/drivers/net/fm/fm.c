#include <common.h>
#include <env.h>
#include <malloc.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <u-boot/crc.h>
#include "fm.h"
#include <fsl_qe.h>		/* For struct qe_firmware */
#include <nand.h>
#include <spi_flash.h>
#include <mmc.h>
#ifdef CONFIG_ARM64
#include <asm/armv8/mmu.h>
#include <asm/arch/cpu.h>
#endif
#ifdef CONFIG_TFABOOT
#ifdef CONFIG_DM_SPI_FLASH
#else
#endif
#else
#if defined(CONFIG_SYS_QE_FMAN_FW_IN_NOR)
#elif defined(CONFIG_SYS_QE_FMAN_FW_IN_NAND)
#elif defined(CONFIG_SYS_QE_FMAN_FW_IN_SPIFLASH)
#ifdef CONFIG_DM_SPI_FLASH
#else
#endif
#elif defined(CONFIG_SYS_QE_FMAN_FW_IN_MMC)
#elif defined(CONFIG_SYS_QE_FMAN_FW_IN_REMOTE)
#else
#endif
#endif
