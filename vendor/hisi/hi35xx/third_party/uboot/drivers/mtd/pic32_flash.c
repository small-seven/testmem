#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <fdt_support.h>
#include <flash.h>
#include <irq_func.h>
#include <mach/pic32.h>
#include <wait_bit.h>
#define NVMOP_NOP		0
#define NVMOP_WORD_WRITE	1
#define NVMOP_PAGE_ERASE	4
#define NVM_WR			BIT(15)
#define NVM_WREN		BIT(14)
#define NVM_WRERR		BIT(13)
#define NVM_LVDERR		BIT(12)
#define LOCK_KEY		0x0
#define UNLOCK_KEY1		0xaa996655
#define UNLOCK_KEY2		0x556699aa
#if (CONFIG_SYS_MONITOR_BASE >= CONFIG_SYS_FLASH_BASE)
#endif
#ifdef CONFIG_ENV_IS_IN_FLASH
#endif
