#include <common.h>
#include <asm/io.h>
#include <malloc.h>
#include <clk-uclass.h>
#include <dm/device.h>
#include <linux/clk-provider.h>
#include <clk.h>
#include "clk.h"
#define UBOOT_DM_CLK_CCF_MUX "ccf_clk_mux"
#if CONFIG_IS_ENABLED(SANDBOX_CLK_CCF)
#else
#endif
#if CONFIG_IS_ENABLED(SANDBOX_CLK_CCF)
#endif
