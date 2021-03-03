#include <common.h>
#include <dm.h>
#include <eeprom.h>
#include <init.h>
#include <dm/device-internal.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/sata.h>
#include <ahci.h>
#include <dwc_ahsata.h>
#include <env.h>
#include <errno.h>
#include <fsl_esdhc_imx.h>
#include <fuse.h>
#include <i2c_eeprom.h>
#include <miiphy.h>
#include <mmc.h>
#include <net.h>
#include <netdev.h>
#include <usb.h>
#include <usb/ehci-ci.h>
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_USB_EHCI_MX6
#endif
#ifdef CONFIG_USB_EHCI_MX6
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#define HW_CODE_BIT_0	IMX_GPIO_NR(2, 19)
#define HW_CODE_BIT_1	IMX_GPIO_NR(6, 6)
#define HW_CODE_BIT_2	IMX_GPIO_NR(2, 16)
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_MULTI_DTB_FIT
#endif
