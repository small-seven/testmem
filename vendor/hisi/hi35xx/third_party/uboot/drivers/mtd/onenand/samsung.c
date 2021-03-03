#include <common.h>
#include <malloc.h>
#include <linux/compat.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/onenand.h>
#include <linux/mtd/flashchip.h>
#include <linux/mtd/samsung_onenand.h>
#include <asm/io.h>
#include <linux/errno.h>
#define ONENAND_ERASE_STATUS		0x00
#define ONENAND_MULTI_ERASE_SET		0x01
#define ONENAND_ERASE_START		0x03
#define ONENAND_UNLOCK_START		0x08
#define ONENAND_UNLOCK_END		0x09
#define ONENAND_LOCK_START		0x0A
#define ONENAND_LOCK_END		0x0B
#define ONENAND_LOCK_TIGHT_START	0x0C
#define ONENAND_LOCK_TIGHT_END		0x0D
#define ONENAND_UNLOCK_ALL		0x0E
#define ONENAND_OTP_ACCESS		0x12
#define ONENAND_SPARE_ACCESS_ONLY	0x13
#define ONENAND_MAIN_ACCESS_ONLY	0x14
#define ONENAND_ERASE_VERIFY		0x15
#define ONENAND_MAIN_SPARE_ACCESS	0x16
#define ONENAND_PIPELINE_READ		0x4000
#if defined(CONFIG_S5P)
#define MAP_00				(0x0 << 26)
#define MAP_01				(0x1 << 26)
#define MAP_10				(0x2 << 26)
#define MAP_11				(0x3 << 26)
#endif
#define CMD_MAP_00(mem_addr)		(MAP_00 | ((mem_addr) << 1))
#define CMD_MAP_01(mem_addr)		(MAP_01 | (mem_addr))
#define CMD_MAP_10(mem_addr)		(MAP_10 | (mem_addr))
#define CMD_MAP_11(mem_addr)		(MAP_11 | ((mem_addr) << 2))
#if defined(CONFIG_S5P)
#endif
#if defined(CONFIG_S5P)
#endif
