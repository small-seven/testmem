#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/io.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <env.h>
#include <linux/sizes.h>
#include <common.h>
#include <fsl_esdhc_imx.h>
#include <mmc.h>
#include <i2c.h>
#include <miiphy.h>
#include <netdev.h>
#include <power/pmic.h>
#include <power/pfuze100_pmic.h>
#include <usb.h>
#include <usb/ehci-ci.h>
#include <pwm.h>
#include <wait_bit.h>
#define UART_PAD_CTRL  (PAD_CTL_HYS | PAD_CTL_PUS_100K_UP |	\
#define ENET_PAD_CTRL  (PAD_CTL_PUS_100K_UP | PAD_CTL_PKE |	\
#define ENET_CLK_PAD_CTRL  PAD_CTL_DSE_34ohm
#define ENET_RX_PAD_CTRL  (PAD_CTL_PKE |			\
#define I2C_PAD_CTRL  (PAD_CTL_HYS | PAD_CTL_PUS_100K_UP |	\
#define USDHC_CLK_PAD_CTRL  (PAD_CTL_HYS | PAD_CTL_SPEED_MED |	\
#define USDHC_PAD_CTRL  (PAD_CTL_HYS | PAD_CTL_PUS_47K_UP |	\
#define USDHC_RESET_CTRL (PAD_CTL_HYS | PAD_CTL_PUS_47K_UP |	\
#define GPIO_PAD_CTRL  (PAD_CTL_HYS | PAD_CTL_PUS_100K_UP |	\
#define PC MUX_PAD_CTRL(I2C_PAD_CTRL)
#ifdef CONFIG_USB_EHCI_MX6
#endif
#ifdef CONFIG_PWM_IMX
#else
#endif
#define ADCx_HC0        0x00
#define ADCx_HS         0x08
#define ADCx_HS_C0      BIT(0)
#define ADCx_R0         0x0c
#define ADCx_CFG        0x14
#define ADCx_CFG_SWMODE 0x308
#define ADCx_GC         0x18
#define ADCx_GC_CAL     BIT(7)
#define VAL_UPPER	2498
#define VAL_LOWER	1550
#ifdef CONFIG_SYS_I2C_MXC
#endif
#define PCIE_PHY_PUP_REQ		BIT(7)
#ifdef CONFIG_SPL_BUILD
#include <linux/libfdt.h>
#include <spl.h>
#include <asm/arch/mx6-ddr.h>
#endif
