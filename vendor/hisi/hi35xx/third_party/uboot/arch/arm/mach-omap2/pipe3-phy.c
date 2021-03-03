#include <common.h>
#include <sata.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/io.h>
#include <linux/errno.h>
#include "pipe3-phy.h"
#define PLL_STATUS              0x00000004
#define PLL_GO                  0x00000008
#define PLL_CONFIGURATION1      0x0000000C
#define PLL_CONFIGURATION2      0x00000010
#define PLL_CONFIGURATION3      0x00000014
#define PLL_CONFIGURATION4      0x00000020
#define PLL_REGM_MASK           0x001FFE00
#define PLL_REGM_SHIFT          9
#define PLL_REGM_F_MASK         0x0003FFFF
#define PLL_REGM_F_SHIFT        0
#define PLL_REGN_MASK           0x000001FE
#define PLL_REGN_SHIFT          1
#define PLL_SELFREQDCO_MASK     0x0000000E
#define PLL_SELFREQDCO_SHIFT    1
#define PLL_SD_MASK             0x0003FC00
#define PLL_SD_SHIFT            10
#define SET_PLL_GO              0x1
#define PLL_TICOPWDN            BIT(16)
#define PLL_LDOPWDN             BIT(15)
#define PLL_LOCK                0x2
#define PLL_IDLE                0x1
#define OMAP_CTRL_PIPE3_PHY_PWRCTL_CLK_CMD_MASK         0x003FC000
#define OMAP_CTRL_PIPE3_PHY_PWRCTL_CLK_CMD_SHIFT        0xE
#define OMAP_CTRL_PIPE3_PHY_PWRCTL_CLK_FREQ_MASK        0xFFC00000
#define OMAP_CTRL_PIPE3_PHY_PWRCTL_CLK_FREQ_SHIFT       0x16
#define OMAP_CTRL_PIPE3_PHY_TX_RX_POWERON       0x3
#define OMAP_CTRL_PIPE3_PHY_TX_RX_POWEROFF      0x0
#define PLL_IDLE_TIME   100     /* in milliseconds */
#define PLL_LOCK_TIME   100     /* in milliseconds */
