#include <common.h>
#include <dm.h>
#include <ram.h>
#include <timer.h>
#include <asm/io.h>
#include <asm/arch/timer.h>
#include <asm/arch/wdt.h>
#include <linux/err.h>
#include <dm/uclass.h>
#define AST_2ND_BOOT_WDT		1
#define AST_FLASH_ADDR_DETECT_WDT	2
#ifndef CONFIG_FIRMWARE_2ND_BOOT
#endif
