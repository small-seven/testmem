#include <common.h>		/* core U-Boot definitions */
#include <altera.h>
#include <ACEX1K.h>		/* ACEX device family */
#ifdef	FPGA_DEBUG
#define PRINTF(fmt, args...)	printf(fmt, ##args)
#else
#define PRINTF(fmt, args...)
#endif
#ifndef CONFIG_FPGA_DELAY
#define CONFIG_FPGA_DELAY()
#endif
#ifndef CONFIG_SYS_FPGA_WAIT
#define CONFIG_SYS_FPGA_WAIT CONFIG_SYS_HZ / 10		/* 100 ms */
#endif
#ifdef CONFIG_SYS_FPGA_PROG_FEEDBACK
#endif
#ifdef CONFIG_SYS_FPGA_PROG_FEEDBACK
#endif
#ifdef CONFIG_SYS_FPGA_PROG_FEEDBACK
#endif
#ifdef CONFIG_SYS_FPGA_PROG_FEEDBACK
#endif
#ifdef CONFIG_SYS_FPGA_PROG_FEEDBACK
#endif
