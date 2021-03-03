#include <common.h>
#include <asm/io.h>
#include <asm/arch/sdram.h>
#include <errno.h>
#include "sequencer.h"
#define DELTA_D		1
#define DLEVEL 0
#define STATIC_IN_RTL_SIM 0
#define STATIC_SKIP_DELAY_LOOPS 0
#define STATIC_CALIB_STEPS (STATIC_IN_RTL_SIM | CALIB_SKIP_FULL_TEST | \
#define SKIP_DELAY_LOOP_VALUE_OR_ZERO(non_skip_value) \
#if DISABLE_GUARANTEED_READ
#endif
