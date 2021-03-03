#include <common.h>
#include <dm.h>
#include <init.h>
#include <ns16550.h>
#include <netdev.h>
#include <flash.h>
#include <nand.h>
#include <i2c.h>
#include <serial.h>
#include <twl4030.h>
#include <asm/io.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/mux.h>
#include <asm/arch/mem.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/omap_mmc.h>
#include <asm/mach-types.h>
#include <linux/mtd/rawnand.h>
#include <asm/omap_musb.h>
#include <linux/errno.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <linux/usb/musb.h>
#include "omap3logic.h"
#ifdef CONFIG_USB_EHCI_HCD
#include <usb.h>
#include <asm/ehci-omap.h>
#endif
#define LOGIC_MT28_DM37_ASYNC_GPMC_CONFIG1	0x00011203
#define LOGIC_MT28_DM37_ASYNC_GPMC_CONFIG2	0x000A1302
#define LOGIC_MT28_DM37_ASYNC_GPMC_CONFIG3	0x000F1302
#define LOGIC_MT28_DM37_ASYNC_GPMC_CONFIG4	0x0A021303
#define LOGIC_MT28_DM37_ASYNC_GPMC_CONFIG5	0x00120F18
#define LOGIC_MT28_DM37_ASYNC_GPMC_CONFIG6	0x0A030000
#define LOGIC_MT28_DM37_ASYNC_GPMC_CONFIG7	0x00000C50
#define LOGIC_MT28_OMAP35_ASYNC_GPMC_CONFIG1	0x00011203
#define LOGIC_MT28_OMAP35_ASYNC_GPMC_CONFIG2	0x00091102
#define LOGIC_MT28_OMAP35_ASYNC_GPMC_CONFIG3	0x000D1102
#define LOGIC_MT28_OMAP35_ASYNC_GPMC_CONFIG4	0x09021103
#define LOGIC_MT28_OMAP35_ASYNC_GPMC_CONFIG5	0x00100D15
#define LOGIC_MT28_OMAP35_ASYNC_GPMC_CONFIG6	0x09030000
#define LOGIC_MT28_OMAP35_ASYNC_GPMC_CONFIG7	0x00000C50
#ifdef CONFIG_SPL_OS_BOOT
#endif
#if defined(CONFIG_SPL_BUILD)
#define GPMC_NAND_COMMAND_0 (OMAP34XX_GPMC_BASE + 0x7c)
#define GPMC_NAND_DATA_0 (OMAP34XX_GPMC_BASE + 0x84)
#define GPMC_NAND_ADDRESS_0 (OMAP34XX_GPMC_BASE + 0x80)
#endif
#if defined(CONFIG_FLASH_CFI_DRIVER)
#endif
#if defined(CONFIG_FLASH_CFI_DRIVER)
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#ifdef CONFIG_CMD_NAND_LOCK_UNLOCK
#endif
#endif
#if defined(CONFIG_MMC)
#endif
#ifdef CONFIG_SMC911X
#endif
