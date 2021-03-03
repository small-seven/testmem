#include <common.h>
#include <command.h>
#include <init.h>
#include <asm/processor.h>
#include <asm/io.h>
#include <asm/global_data.h>
#include "mpc8308.h"
#include <gdsys_fpga.h>
#define REFLECTION_TESTPATTERN 0xdede
#define REFLECTION_TESTPATTERN_INV (~REFLECTION_TESTPATTERN & 0xffff)
#ifdef CONFIG_SYS_FPGA_NO_RFL_HI
#define REFLECTION_TESTREG reflection_low
#else
#define REFLECTION_TESTREG reflection_high
#endif
#ifdef CONFIG_GDSYS_LEGACY_DRIVERS
#endif
