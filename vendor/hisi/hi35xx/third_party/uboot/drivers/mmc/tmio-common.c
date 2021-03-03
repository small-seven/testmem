#include <common.h>
#include <clk.h>
#include <cpu_func.h>
#include <fdtdec.h>
#include <mmc.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <linux/compat.h>
#include <linux/dma-direction.h>
#include <linux/io.h>
#include <linux/sizes.h>
#include <power/regulator.h>
#include <asm/unaligned.h>
#include "tmio-common.h"
#define tmio_pio_read_fifo(__width, __suffix)				\
#define tmio_pio_write_fifo(__width, __suffix)				\
#if defined(CONFIG_RCAR_GEN3)
#endif
#if defined(CONFIG_ARCH_UNIPHIER) && !defined(CONFIG_ARM64) && \
#endif
#ifdef CONFIG_DM_REGULATOR
#endif
#ifdef CONFIG_PINCTRL
#endif
#ifdef CONFIG_DM_REGULATOR
#endif
