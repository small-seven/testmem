#include <common.h>
#include <env.h>
#include <init.h>
#include <miiphy.h>
#include <input.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <serial.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <linux/sizes.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/iomux-v3.h>
#define UART_PAD_CTRL  (PAD_CTL_PKE | PAD_CTL_PUE |            \
#define NAND_PAD_CTRL  (PAD_CTL_PKE | PAD_CTL_PUE |            \
#ifdef CONFIG_SPL_BUILD
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/mx6q-ddr.h>
#include <spl.h>
#include <linux/libfdt.h>
#ifdef CONFIG_SPL_OS_BOOT
#endif
#endif
