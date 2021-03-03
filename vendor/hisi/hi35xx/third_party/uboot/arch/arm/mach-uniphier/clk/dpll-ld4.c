#include <common.h>
#include <linux/errno.h>
#include <linux/io.h>
#include "../init.h"
#include "../sc-regs.h"
#undef DPLL_SSC_RATE_1PER
#if defined(DPLL_SSC_RATE_1PER)
#else
#endif
