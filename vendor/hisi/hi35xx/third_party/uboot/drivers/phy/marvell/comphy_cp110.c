#include <common.h>
#include <fdtdec.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "comphy_core.h"
#include "comphy_hpipe.h"
#include "sata.h"
#include "utmi_phy.h"
#define SD_ADDR(base, lane)			(base + 0x1000 * lane)
#define HPIPE_ADDR(base, lane)			(SD_ADDR(base, lane) + 0x800)
#define COMPHY_ADDR(base, lane)			(base + 0x28 * lane)
