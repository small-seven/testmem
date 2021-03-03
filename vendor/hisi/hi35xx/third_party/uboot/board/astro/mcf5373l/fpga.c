#include <common.h>
#include <console.h>
#include <watchdog.h>
#include <altera.h>
#include <ACEX1K.h>
#include <spartan3.h>
#include <command.h>
#include <asm/immap_5329.h>
#include <asm/io.h>
#include "fpga.h"
#if defined(CONFIG_HW_WATCHDOG) || defined(CONFIG_WATCHDOG)
#endif
#ifdef CONFIG_SYS_FPGA_PROG_FEEDBACK
#endif
#ifdef CONFIG_SYS_FPGA_CHECK_CTRLC
#endif
#if defined(CONFIG_HW_WATCHDOG) || defined(CONFIG_WATCHDOG)
#endif
#ifdef CONFIG_SYS_FPGA_PROG_FEEDBACK
#endif
#ifdef CONFIG_SYS_FPGA_CHECK_CTRLC
#endif
