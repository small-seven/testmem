#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <errno.h>
#include <asm/io.h>
#include <linux/bitops.h>
#include "clock-snapdragon.h"
#define GPLL0_STATUS_ACTIVE		BIT(30)
#define APCS_GPLL_ENA_VOTE_GPLL0	BIT(0)
