#include <common.h>
#include <console.h>
#include <clk.h>
#include <ram.h>
#include <reset.h>
#include <asm/io.h>
#include "stm32mp1_ddr_regs.h"
#include "stm32mp1_ddr.h"
#include "stm32mp1_tests.h"
#define MAX_DQS_PHASE_IDX _144deg
#define MAX_DQS_UNIT_IDX 7
#define MAX_GSL_IDX 5
#define MAX_GPS_IDX 3
#define NUM_BYTES 4
