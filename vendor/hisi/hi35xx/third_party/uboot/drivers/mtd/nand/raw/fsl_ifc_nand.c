#include <common.h>
#include <command.h>
#include <malloc.h>
#include <nand.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/rawnand.h>
#include <linux/mtd/nand_ecc.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <fsl_ifc.h>
#ifndef CONFIG_SYS_FSL_IFC_BANK_COUNT
#define CONFIG_SYS_FSL_IFC_BANK_COUNT	4
#endif
#define MAX_BANKS	CONFIG_SYS_FSL_IFC_BANK_COUNT
#define ERR_BYTE	0xFF /* Value returned for read bytes
#ifndef CONFIG_SYS_NAND_BASE_LIST
#define CONFIG_SYS_NAND_BASE_LIST { CONFIG_SYS_NAND_BASE }
#endif
