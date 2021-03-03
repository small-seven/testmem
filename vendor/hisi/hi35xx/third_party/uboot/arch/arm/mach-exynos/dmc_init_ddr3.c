#include <common.h>
#include <config.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/cpu.h>
#include <asm/arch/dmc.h>
#include <asm/arch/power.h>
#include "common_setup.h"
#include "exynos5_setup.h"
#include "clock_init.h"
#define TIMEOUT_US		10000
#define NUM_BYTE_LANES		4
#define DEFAULT_DQS		8
#define DEFAULT_DQS_X4		((DEFAULT_DQS << 24) || (DEFAULT_DQS << 16) \
#ifdef CONFIG_EXYNOS5250
#endif
#ifdef CONFIG_EXYNOS5420
#endif
