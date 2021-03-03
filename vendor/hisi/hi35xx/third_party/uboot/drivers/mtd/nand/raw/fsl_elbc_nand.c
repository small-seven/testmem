#include <common.h>
#include <command.h>
#include <malloc.h>
#include <nand.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/rawnand.h>
#include <linux/mtd/nand_ecc.h>
#include <asm/io.h>
#include <linux/errno.h>
#ifdef VERBOSE_DEBUG
#define DEBUG_ELBC
#define vdbg(format, arg...) printf("DEBUG: " format, ##arg)
#else
#define vdbg(format, arg...) do {} while (0)
#endif
#ifdef DEBUG_ELBC
#define dbg(format, arg...) printf("DEBUG: " format, ##arg)
#else
#define dbg(format, arg...) do {} while (0)
#endif
#define MAX_BANKS 8
#define ERR_BYTE 0xFF /* Value returned for read bytes when read failed */
#define LTESR_NAND_MASK (LTESR_FCT | LTESR_PAR | LTESR_CC)
#if defined(CONFIG_NAND_ECC_BCH)
#else
#endif
#ifndef CONFIG_SYS_NAND_BASE_LIST
#define CONFIG_SYS_NAND_BASE_LIST { CONFIG_SYS_NAND_BASE }
#endif
