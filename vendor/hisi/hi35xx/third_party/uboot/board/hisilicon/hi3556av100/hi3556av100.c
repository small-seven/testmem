#include "../../../lib/hw_dec/hw_decompress_v2.h"
#include <config.h>
#include <common.h>
#include <command.h>
#include <asm/io.h>
#include <asm/arch/platform.h>
#include <spi_flash.h>
#include <linux/mtd/mtd.h>
#include <nand.h>
#include <netdev.h>
#include <mmc.h>
#include <sdhci.h>
#include <blk.h>
#include <hicpu_common.h>
#include <asm/mach-types.h>
#include <cpu_func.h>
#ifndef CONFIG_SYS_DCACHE_OFF
#endif
#if defined(CONFIG_SHOW_BOOT_PROGRESS)
#endif
#define COMP_MODE_ENABLE ((unsigned int)0x0000EAEF)
#define UBOOT_DATA_ADDR     0x21000000ul
#define UBOOT_DATA_SIZE     0x80000UL
#if defined(CONFIG_HIFMC)
#endif
#if defined(CONFIG_MMC)
#endif
#define REG_BASE_GPIO4          0x045f4000
#define GPIO4_3_DATA_OFST       0x20
#define GPIO_DIR_OFST       0x400
#ifdef CONFIG_TARGET_HI3556AV100
#define UPGRADE_STATUS_REG_ADDR (0x04590048)
typedef enum tagUPGRADE_STATUS_E {
	UPGRADE_STATUS_IDLE = 0,
	UPGRADE_STATUS_PROCESSING,
	UPGRADE_STATUS_FINISH,
	UPGRADE_STATUS_BUTT
} upgrade_status_e;
#endif
#if (CONFIG_AUTO_UPDATE == 1)
#if (defined CONFIG_AUTO_SD_UPDATE) || (defined CONFIG_AUTO_USB_UPDATE)
#ifdef CONFIG_TARGET_HI3556AV100
#endif
#else
#endif
#endif /* CONFIG_AUTO_UPDATE */
#ifdef CONFIG_TARGET_HI3556AV100
#if defined(CONFIG_HIFMC_SPI_NAND)|| defined(CONFIG_HIFMC_NAND)
#define NAND_MAX_SIZE  0xFFFFFFFF
#endif
#ifdef CONFIG_HIFMC_SPI_NOR              /* spi nor configure */
#include "spi_flash.h"
#endif
#ifdef CONFIG_MMC
#endif
#ifdef CONFIG_HIFMC_SPI_NOR
#endif
#if defined(CONFIG_HIFMC_SPI_NAND)|| defined(CONFIG_HIFMC_NAND)
#endif
#ifdef CONFIG_MMC
#endif
#endif
#ifdef CONFIG_EMMC
#endif
#ifdef CONFIG_TARGET_HI3556AV100
#endif
#ifdef CONFIG_RANDOM_ETHADDR
#endif
#if (CONFIG_AUTO_UPDATE == 1)
#ifdef CFG_MMU_HANDLEOK
#endif
#ifdef CFG_MMU_HANDLEOK
#endif
#endif
#if (CONFIG_AUTO_UPDATE == 1)
#ifdef CONFIG_TARGET_HI3556AV100
#else
#endif
#endif
#ifdef CONFIG_HIGMACV300_ETH
#endif
#ifdef CONFIG_GENERIC_MMC
#ifdef CONFIG_HISI_SDHCI
#if !defined(CONFIG_HIFMC) || defined(CONFIG_AUTO_SD_UPDATE)
#endif
#ifndef CONFIG_HIFMC
#endif
#ifdef CONFIG_AUTO_SD_UPDATE
#endif
#endif
#endif
#ifdef CONFIG_SECURE_SCHEME_ENABLE
#define sec_rgn_map_ofst(region_idx) (0x1100 + 0x10 * (region_idx))
#define sec_rgn_map_ext_ofst(region_idx) (0x1200 + 0x10 * (region_idx))
#define sec_rgn_attrib_ofst(region_idx) (0x1104 + 0x10 * (region_idx))
#define sec_mid_wr_ofst(region_idx) (0x1108 + 0x10 * (region_idx))
#define sec_mid_wr_ext_ofst(region_idx) (0x1204 + 0x10 * (region_idx))
#define sec_mid_rd_ofst(region_idx) (0x110c + 0x10 * (region_idx))
#define sec_mid_rd_ext_ofst(region_idx) (0x1208 + 0x10 * (region_idx))
#define SEC_BYPASS_OFST         0x1004
#define SEC_INT_EN_OFST         0x1020
#define SECURITY_ENABLE 0xff
#define SEC_INV_EN      (0x1 << 4)
#define SHARE_REGN_EN   (0xf)
#define SECUR_REGN_EN   (0xc)
#define NON_SEC_REGN_EN (0x3)
#define A53CPU0_MID     0xf
#define A53CPU1_MID     0x11
#define DSP_M0_MID      0x13
#define AVSP_M2_MID     0x18
#define DSP_M1_MID      0x1c
#define MID_HIGH_START_BIT  0x20
#define FMC_MID     0x21
#define EMMC_MID    0x28
#define IPCM_REGN_WR_MID_MASK   ((0x1 << A53CPU0_MID) | (0x1 << A53CPU1_MID))
#define IPCM_REGN_RD_MID_MASK   IPCM_REGN_WR_MID_MASK
#define DSP_REGN_WR_MID_MASK    ((0x1 << A53CPU0_MID) | (0x1 << DSP_M0_MID) | \
#define DSP_REGN_RD_MID_MASK    DSP_REGN_WR_MID_MASK
#define LITEOS_REGN_WR_MID_MASK (0x1 << A53CPU1_MID)
#define LITEOS_REGN_RD_MID_MASK LITEOS_REGN_WR_MID_MASK
#define LINUX_REGN_WR_MID_MASK  ((0x1 << A53CPU0_MID))
#define LINUX_REGN_RD_MID_MASK  LINUX_REGN_WR_MID_MASK
#define LINUX_REGN_WR_MID_HIGH_MASK ((0x1 << (FMC_MID - MID_HIGH_START_BIT)) | \
#define LINUX_REGN_RD_MID_HIGH_MASK LINUX_REGN_WR_MID_HIGH_MASK
#define REGN_CTRL_ENABLE        (0x1 << 31)
#define IPCM_REGN_HIGH_ADDR     0x2000  /* high 16 bit of address */
#define IPCM_REGN_SIZE          0x20    /* 0x20 * 64K Byte */
#define DSP_REGN_HIGH_ADDR      0x2020  /* high 16 bit of address */
#define DSP_REGN_SIZE           0x1e0   /* 0x1e0 * 64K Byte */
#define LITEOS_REGN_HIGH_ADDR   0x2200  /* high 16 bit of address */
#define LITEOS_REGN_SIZE        0x1000  /* 0x1000 * 64K Byte */
#define LINUX_REGN_HIGH_ADDR    0x3200  /* high 16 bit of address */
#define LINUX_REGN_SIZE         0x1000  /* 0x1000 * 64K Byte */
#define IPCM_DDR_REGN_IDX       1
#define DSP_DDR_REGN_IDX        2
#define LITEOS_DDR_REGN_IDX     3
#define LINUX_DDR_REGN_IDX      4
#endif
#ifdef CONFIG_TARGET_HI3556AV100
#define PAGE_SIZE       4096
#define page_size_align(x) (((x)+(PAGE_SIZE)-1) / (PAGE_SIZE)*(PAGE_SIZE))
#ifdef CONFIG_SECURE_SCHEME_ENABLE
#endif
#else
#ifdef CONFIG_SECURE_SCHEME_ENABLE
#endif
#endif
