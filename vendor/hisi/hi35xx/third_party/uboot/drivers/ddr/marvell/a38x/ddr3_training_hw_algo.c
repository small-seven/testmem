#include "ddr3_init.h"
#include "mv_ddr_regs.h"
#define VREF_INITIAL_STEP		3
#define VREF_SECOND_STEP		1
#define VREF_MAX_INDEX			7
#define MAX_VALUE			(1024 - 1)
#define MIN_VALUE			(-MAX_VALUE)
#define GET_RD_SAMPLE_DELAY(data, cs)	((data >> rd_sample_mask[cs]) & 0xf)
#define	VREF_STEP_1		0
#define	VREF_STEP_2		1
#define	VREF_CONVERGE		2
