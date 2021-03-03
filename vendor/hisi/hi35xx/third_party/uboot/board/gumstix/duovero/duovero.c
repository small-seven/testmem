#include <common.h>
#include <netdev.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mmc_host_def.h>
#include <twl6030.h>
#include <asm/emif.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <asm/gpio.h>
#include <asm/mach-types.h>
#include "duovero_mux_data.h"
#define WIFI_EN	43
#if defined(CONFIG_CMD_NET)
#define SMSC_NRESET	45
#endif
#ifdef CONFIG_USB_EHCI_HCD
#include <usb.h>
#include <asm/arch/ehci.h>
#include <asm/ehci-omap.h>
#endif
#if defined(CONFIG_CMD_NET)
#endif
#if defined(CONFIG_MMC)
#if !defined(CONFIG_SPL_BUILD)
#endif
#endif
#if defined(CONFIG_CMD_NET)
#define GPMC_SIZE_16M	0xF
#define GPMC_BASEADDR_MASK	0x3F
#define GPMC_CS_ENABLE		0x1
#define NET_LAN9221_GPMC_CONFIG1    0x2a001203
#define NET_LAN9221_GPMC_CONFIG2    0x000a0a02
#define NET_LAN9221_GPMC_CONFIG3    0x00020200
#define NET_LAN9221_GPMC_CONFIG4    0x0a030a03
#define NET_LAN9221_GPMC_CONFIG5    0x000a0a0a
#define NET_LAN9221_GPMC_CONFIG6    0x8a070707
#define NET_LAN9221_GPMC_CONFIG7    0x00000f6c
#endif
#ifdef CONFIG_SMC911X
#endif
#ifdef CONFIG_USB_EHCI_HCD
#endif
