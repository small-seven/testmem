#include <bouncebuf.h>
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <mmc.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch-tegra/tegra_mmc.h>
#if defined(CONFIG_TEGRA30)
#endif
#if defined(CONFIG_TEGRA124_MMC_DISABLE_EXT_LOOPBACK)
#endif
