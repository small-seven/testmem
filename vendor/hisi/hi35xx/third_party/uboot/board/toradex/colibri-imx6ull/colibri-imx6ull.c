#include <common.h>
#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch-mx6/clock.h>
#include <asm/arch-mx6/imx-regs.h>
#include <asm/arch-mx6/mx6ull_pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/io.h>
#include <dm.h>
#include <dm/platform_data/serial_mxc.h>
#include <env.h>
#include <fdt_support.h>
#include <imx_thermal.h>
#include <jffs2/load_kernel.h>
#include <linux/sizes.h>
#include <miiphy.h>
#include <mtd_node.h>
#include <netdev.h>
#include "../common/tdx-common.h"
#include "../common/tdx-cfg-block.h"
#define LCD_PAD_CTRL    (PAD_CTL_HYS | PAD_CTL_PUS_100K_UP | \
#define MX6_PAD_SNVS_PMIC_STBY_REQ_ADDR 0x2290040
#define NAND_PAD_CTRL (PAD_CTL_DSE_48ohm | PAD_CTL_SRE_SLOW | PAD_CTL_HYS)
#define NAND_PAD_READY0_CTRL (PAD_CTL_DSE_48ohm | PAD_CTL_PUS_22K_UP)
#ifdef CONFIG_NAND_MXS
#endif /* CONFIG_NAND_MXS */
#ifdef CONFIG_VIDEO_MXS
#define GPIO_BL_ON IMX_GPIO_NR(1, 11)
#define GPIO_PWM_A IMX_GPIO_NR(4, 11)
#endif
#ifdef CONFIG_FEC_MXC
#endif /* CONFIG_FEC_MXC */
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_NAND_MXS
#endif
#ifdef CONFIG_VIDEO_MXS
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_TDX_CFG_BLOCK
#endif
#ifdef CONFIG_CMD_BMODE
#endif
#ifdef CONFIG_CMD_USB_SDP
#endif /* CONFIG_CMD_USB_SDP */
#if defined(CONFIG_OF_LIBFDT) && defined(CONFIG_OF_BOARD_SETUP)
#if defined(CONFIG_FDT_FIXUP_PARTITIONS)
#endif
#endif
