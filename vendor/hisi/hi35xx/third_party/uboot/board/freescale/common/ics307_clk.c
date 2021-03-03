#include <common.h>
#include <asm/io.h>
#include "ics307_clk.h"
#if defined(CONFIG_FSL_NGPIXIS)
#include "ngpixis.h"
#define fpga_reg pixis
#elif defined(CONFIG_FSL_QIXIS)
#include "qixis.h"
#define fpga_reg ((struct qixis *)QIXIS_BASE)
#else
#include "pixis.h"
#define fpga_reg pixis
#endif
#define TTL		1
#define CLK2		0
#define CRYSTAL		0
#define MAX_VDW		(511 + 8)
#define MAX_RDW		(127 + 2)
#define MIN_VDW		(4 + 8)
#define MIN_RDW		(1 + 2)
#define NUM_OD_SETTING	8
#define MAX_VCO		360000
#define MIN_VCO		60000
