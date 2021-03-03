#include <common.h>		/* core U-Boot definitions */
#include <spartan2.h>		/* Spartan-II device family */
#ifdef	FPGA_DEBUG
#define PRINTF(fmt,args...)	printf (fmt ,##args)
#else
#define PRINTF(fmt,args...)
#endif
#undef CONFIG_SYS_FPGA_CHECK_BUSY
#undef CONFIG_SYS_FPGA_PROG_FEEDBACK
#ifndef CONFIG_FPGA_DELAY
#define CONFIG_FPGA_DELAY()
#endif
#ifndef CONFIG_SYS_FPGA_WAIT
#define CONFIG_SYS_FPGA_WAIT CONFIG_SYS_HZ/100	/* 10 ms */
#endif
#ifdef CONFIG_SYS_FPGA_PROG_FEEDBACK
#endif
#ifdef CONFIG_SYS_FPGA_CHECK_BUSY
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
#ifdef CONFIG_SYS_FPGA_PROG_FEEDBACK
#endif
#ifdef CONFIG_SYS_FPGA_PROG_FEEDBACK
#endif
#ifdef CONFIG_SYS_FPGA_PROG_FEEDBACK
#endif
#ifdef CONFIG_SYS_FPGA_PROG_FEEDBACK
#endif
