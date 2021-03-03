#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <input.h>
#include <keyboard.h>
#include <key_matrix.h>
#include <stdio_dev.h>
#include <tegra-kbc.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/funcmux.h>
#include <asm/arch-tegra/timer.h>
#include <linux/input.h>
#define KBC_FIFO_TH_CNT_SHIFT		14
#define KBC_DEBOUNCE_CNT_SHIFT		4
#define KBC_CONTROL_FIFO_CNT_INT_EN	(1 << 3)
#define KBC_CONTROL_KBC_EN		(1 << 0)
#define KBC_INT_FIFO_CNT_INT_STATUS	(1 << 2)
#define KBC_KPENT_VALID			(1 << 7)
#define KBC_ST_STATUS			(1 << 3)
