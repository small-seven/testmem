#include <common.h>
#include <asm/io.h>
#include <asm/arch/platform.h>
#include <hifmc_common.h>
#include "hifmc_spi_ids.h"
#define REG_BASE_MISC       0x04528000
#define PHY_INIT_EN         0x1
#define PHY_ZCAL_EN         (0x1 << 3)
#define EMMC_PHY_IOCTL_RONSEL_1_0   (EMMC_PHY_BASE + 0x264)
#define EMMC_PHY_IOCTL_OD_RONSEL_2  (EMMC_PHY_BASE + 0x268)
#define REG_IO_CFG_0_BASE   0x04058000
#define IO_CFG_REG46            0xb8
#define IO_CFG_REG47            0xbc
#define IO_CFG_REG48            0xc0
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif/* CONFIG_DTR_MODE_SUPPORT */
