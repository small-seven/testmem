#include <common.h>
#include <malloc.h>
#include <dwmmc.h>
#include <linux/libfdt.h>
#include <fdtdec.h>
#include <asm/arcregs.h>
#define SYSCON_BASE	0xf000a000
#define AHBCKDIV	(void *)(SYSCON_BASE + 0x04)
#define APBCKDIV	(void *)(SYSCON_BASE + 0x08)
#define APBCKEN		(void *)(SYSCON_BASE + 0x0C)
#define RESET_REG	(void *)(SYSCON_BASE + 0x18)
#define CLKSEL		(void *)(SYSCON_BASE + 0x24)
#define CLKSTAT		(void *)(SYSCON_BASE + 0x28)
#define PLLCON		(void *)(SYSCON_BASE + 0x2C)
#define APBCKSEL	(void *)(SYSCON_BASE + 0x30)
#define AHBCKEN		(void *)(SYSCON_BASE + 0x34)
#define USBPHY_PLL	(void *)(SYSCON_BASE + 0x78)
#define USBCFG		(void *)(SYSCON_BASE + 0x7c)
#define PLL_MASK_0	0xffcfffff
#define PLL_MASK_1	0xffcfff00
#define PLL_MASK_2	0xfbcfff00
#define CLKSEL_DEFAULT	0x5a690000
#define DEBUG_UART_BASE		0x80014000
#define DEBUG_UART_DLF_OFFSET	0xc0
#define IOTDK_RESET_SEQ		0x55AA6699
