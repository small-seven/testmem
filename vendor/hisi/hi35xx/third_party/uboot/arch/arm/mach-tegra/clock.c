#include <common.h>
#include <div64.h>
#include <dm.h>
#include <errno.h>
#include <time.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/tegra.h>
#include <asm/arch-tegra/ap.h>
#include <asm/arch-tegra/clk_rst.h>
#include <asm/arch-tegra/pmc.h>
#include <asm/arch-tegra/timer.h>
#define clock_type_id_isvalid(id) ((id) >= 0 && \
#define periphc_internal_id_isvalid(id) ((id) >= 0 && \
#ifdef CONFIG_TEGRA20
#else
#endif
#ifdef CONFIG_TEGRA210
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif /* CONFIG_IS_ENABLED(OF_CONTROL) */
