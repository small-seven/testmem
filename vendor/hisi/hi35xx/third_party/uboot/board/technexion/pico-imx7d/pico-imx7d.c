#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/mx7-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/io.h>
#include <common.h>
#include <i2c.h>
#include <miiphy.h>
#include <netdev.h>
#include <power/pmic.h>
#include <power/pfuze3000_pmic.h>
#include "../../freescale/common/pfuze.h"
#define UART_PAD_CTRL  (PAD_CTL_DSE_3P3V_49OHM | \
#define ENET_PAD_CTRL  (PAD_CTL_PUS_PU100KOHM | PAD_CTL_DSE_3P3V_49OHM)
#define ENET_PAD_CTRL_MII  (PAD_CTL_DSE_3P3V_32OHM)
#define ENET_RX_PAD_CTRL  (PAD_CTL_PUS_PU100KOHM | PAD_CTL_DSE_3P3V_49OHM)
#define I2C_PAD_CTRL    (PAD_CTL_DSE_3P3V_32OHM | PAD_CTL_SRE_SLOW | \
#ifdef CONFIG_SYS_I2C_MXC
#define PC MUX_PAD_CTRL(I2C_PAD_CTRL)
#endif
#ifdef CONFIG_OPTEE_TZDRAM_SIZE
#endif
#ifdef CONFIG_POWER
#define I2C_PMIC	3
#endif
#ifdef CONFIG_FEC_MXC
#define FEC1_RST_GPIO	IMX_GPIO_NR(6, 11)
#endif
#ifdef CONFIG_SYS_I2C_MXC
#endif
#ifdef CONFIG_DM_VIDEO
#endif
#ifdef CONFIG_DM_VIDEO
#endif
#ifdef CONFIG_FEC_MXC
#endif
