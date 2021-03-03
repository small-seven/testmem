#include <common.h>
#include <mpc83xx.h>
#include <spi.h>
#include <linux/libfdt.h>
#ifndef CONFIG_SYS_RAMBOOT
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#endif
#define IDSCPLD_SPI_CS_MASK		0x00000001
#define IDSCPLD_SPI_CS_BASE		(CONFIG_SYS_CPLD_BASE + 0xf)
#if defined(CONFIG_MISC_INIT_R)
#define IDSUMCR_RTS_MASK 0x04
#endif
#ifdef CONFIG_MPC8XXX_SPI
#endif
