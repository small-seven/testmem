#include <common.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/setup.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux-mx28.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <env.h>
#include <linux/mii.h>
#include <miiphy.h>
#include <netdev.h>
#include <errno.h>
#ifdef CONFIG_CMD_MMC
#endif
#ifdef CONFIG_CMD_NET
#define MII_PHY_CTRL2 0x1f
#endif
#ifdef CONFIG_SERIAL_TAG
#define MXS_OCOTP_MAX_TIMEOUT 1000000
#endif
#ifdef CONFIG_REVISION_TAG
#endif
