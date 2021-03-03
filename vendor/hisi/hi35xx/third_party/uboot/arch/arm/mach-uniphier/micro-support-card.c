#include <common.h>
#include <linux/ctype.h>
#include <linux/io.h>
#include "micro-support-card.h"
#define MICRO_SUPPORT_CARD_BASE		0x43f00000
#define SMC911X_BASE			((MICRO_SUPPORT_CARD_BASE) + 0x00000)
#define LED_BASE			((MICRO_SUPPORT_CARD_BASE) + 0x90000)
#define NS16550A_BASE			((MICRO_SUPPORT_CARD_BASE) + 0xb0000)
#define MICRO_SUPPORT_CARD_RESET	((MICRO_SUPPORT_CARD_BASE) + 0xd0034)
#define MICRO_SUPPORT_CARD_REVISION	((MICRO_SUPPORT_CARD_BASE) + 0xd00E0)
#if defined(CONFIG_SMC911X)
#include <netdev.h>
#endif
#if defined(CONFIG_MTD_NOR_FLASH)
#include <mtd/cfi_flash.h>
#else /* CONFIG_MTD_NOR_FLASH */
#endif /* CONFIG_MTD_NOR_FLASH */
