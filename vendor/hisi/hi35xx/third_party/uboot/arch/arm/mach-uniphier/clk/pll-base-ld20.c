#include <linux/bitfield.h>
#include <linux/bitops.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/io.h>
#include <linux/sizes.h>
#include "../sc64-regs.h"
#include "pll.h"
#define SC_PLLCTRL_SSC_DK_MASK		GENMASK(14, 0)
#define SC_PLLCTRL_SSC_EN		BIT(31)
#define SC_PLLCTRL2_NRSTDS		BIT(28)
#define SC_PLLCTRL2_SSC_JK_MASK		GENMASK(26, 0)
#define SC_PLLCTRL3_REGI_MASK		GENMASK(19, 16)
#define SC_VPLL27CTRL_WP		BIT(0)
#define SC_VPLL27CTRL3_K_LD		BIT(28)
#define SC_DSPLLCTRL2_K_LD		BIT(28)
