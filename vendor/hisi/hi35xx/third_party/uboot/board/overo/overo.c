#include <common.h>
#include <dm.h>
#include <env.h>
#include <ns16550.h>
#include <netdev.h>
#include <twl4030.h>
#include <linux/mtd/rawnand.h>
#include <asm/io.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/mux.h>
#include <asm/arch/mem.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-types.h>
#include "overo.h"
#ifdef CONFIG_USB_EHCI_HCD
#include <usb.h>
#include <asm/ehci-omap.h>
#endif
#define TWL4030_I2C_BUS			0
#define EXPANSION_EEPROM_I2C_BUS	2
#define EXPANSION_EEPROM_I2C_ADDRESS	0x51
#define GUMSTIX_EMPTY_EEPROM		0x0
#define GUMSTIX_SUMMIT			0x01000200
#define GUMSTIX_TOBI			0x02000200
#define GUMSTIX_TOBI_DUO		0x03000200
#define GUMSTIX_PALO35			0x04000200
#define GUMSTIX_PALO43			0x05000200
#define GUMSTIX_CHESTNUT43		0x06000200
#define GUMSTIX_PINTO			0x07000200
#define GUMSTIX_GALLOP43		0x08000200
#define GUMSTIX_ALTO35			0x09000200
#define GUMSTIX_STAGECOACH		0x0A000200
#define GUMSTIX_THUMBO			0x0B000200
#define GUMSTIX_TURTLECORE		0x0C000200
#define GUMSTIX_ARBOR43C		0x0D000200
#define ETTUS_USRP_E			0x01000300
#define GUMSTIX_NO_EEPROM		0xffffffff
#if defined(CONFIG_CMD_NET)
#ifdef CONFIG_SMC911X
#endif
#endif
#if defined(CONFIG_USB_EHCI_HCD)
#define GUMSTIX_GPIO_USBH_CPEN		168
#endif /* CONFIG_USB_EHCI_HCD */
