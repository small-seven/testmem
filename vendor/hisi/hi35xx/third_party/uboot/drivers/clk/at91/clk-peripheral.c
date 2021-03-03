#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <linux/io.h>
#include <mach/at91_pmc.h>
#include "pmc.h"
#define PERIPHERAL_ID_MIN	2
#define PERIPHERAL_ID_MAX	31
#define PERIPHERAL_MASK(id)	(1 << ((id) & PERIPHERAL_ID_MAX))
