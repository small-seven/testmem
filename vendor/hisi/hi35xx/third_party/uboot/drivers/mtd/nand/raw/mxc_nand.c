#include <common.h>
#include <nand.h>
#include <linux/err.h>
#include <asm/io.h>
#if defined(CONFIG_MX25) || defined(CONFIG_MX27) || defined(CONFIG_MX35) || \
#include <asm/arch/imx-regs.h>
#endif
#include "mxc_nand.h"
#define DRIVER_NAME "mxc_nand"
#ifdef MXC_NFC_V3_2
#endif
#define TROP_US_DELAY   2000
#define COLPOS(x)  ((x) >> 3)
#define BITPOS(x) ((x) & 0xf)
#define MAIN_SINGLEBIT_ERROR 0x4
#define SPARE_SINGLEBIT_ERROR 0x1
#if defined(MXC_NFC_V1)
#ifndef CONFIG_SYS_NAND_LARGEPAGE
#else
#endif
#elif defined(MXC_NFC_V2_1) || defined(MXC_NFC_V3_2)
#ifndef CONFIG_SYS_NAND_LARGEPAGE
#else
#endif
#endif
#if defined(CONFIG_SYS_NAND_BUSWIDTH_16BIT)
#else
#endif
#if defined(MXC_NFC_V1) || defined(MXC_NFC_V2_1)
#elif defined(MXC_NFC_V3_2)
#endif
#if defined(MXC_NFC_V1) || defined(MXC_NFC_V2_1)
#elif defined(MXC_NFC_V3_2)
#endif
#if defined(MXC_NFC_V1) || defined(MXC_NFC_V2_1)
#elif defined(MXC_NFC_V3_2)
#endif
#if defined(MXC_NFC_V1) || defined(MXC_NFC_V2_1)
#elif defined(MXC_NFC_V3_2)
#endif
#if defined(MXC_NFC_V1) || defined(MXC_NFC_V2_1)
#endif
#if defined(MXC_NFC_V1) || defined(MXC_NFC_V2_1)
#endif
#if defined(MXC_NFC_V1) || defined(MXC_NFC_V2_1)
#elif defined(MXC_NFC_V3_2)
#endif
#if defined(MXC_NFC_V1) || defined(MXC_NFC_V2_1)
#elif defined(MXC_NFC_V3_2)
#endif
#ifdef CONFIG_MXC_NAND_HWECC
#if defined(MXC_NFC_V2_1) || defined(MXC_NFC_V3_2)
#else
#define mxc_nand_read_page_syndrome NULL
#define mxc_nand_read_page_raw_syndrome NULL
#define mxc_nand_read_oob_syndrome NULL
#define mxc_nand_write_page_syndrome NULL
#define mxc_nand_write_page_raw_syndrome NULL
#define mxc_nand_write_oob_syndrome NULL
#endif
#endif
#ifdef CONFIG_SYS_NAND_USE_FLASH_BBT
#endif
#if defined(MXC_NFC_V2_1) || defined(MXC_NFC_V3_2)
#endif
#ifdef CONFIG_SYS_NAND_USE_FLASH_BBT
#endif
#ifdef MXC_NFC_V3_2
#endif
#ifdef CONFIG_MXC_NAND_HWECC
#else
#endif
#ifdef CONFIG_SYS_NAND_LARGEPAGE
#else
#endif
#if defined(MXC_NFC_V1) || defined(MXC_NFC_V2_1)
#ifdef MXC_NFC_V2_1
#endif
#elif defined(MXC_NFC_V3_2)
#endif
