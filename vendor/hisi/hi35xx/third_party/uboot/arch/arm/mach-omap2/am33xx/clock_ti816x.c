#include <common.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/cpu.h>
#include <asm/arch/clock.h>
#include <asm/arch/hardware.h>
#include <asm/io.h>
#include <asm/emif.h>
#define CM_PLL_BASE		(CTRL_BASE + 0x0400)
#define MAIN_N			64
#define MAIN_P			0x1
#define MAIN_INTFREQ1		0x8
#define MAIN_FRACFREQ1		0x800000
#define MAIN_MDIV1		0x2
#define MAIN_INTFREQ2		0xE
#define MAIN_FRACFREQ2		0x0
#define MAIN_MDIV2		0x1
#define MAIN_INTFREQ3		0x8
#define MAIN_FRACFREQ3		0xAAAAB0
#define MAIN_MDIV3		0x3
#define MAIN_INTFREQ4		0x9
#define MAIN_FRACFREQ4		0x55554F
#define MAIN_MDIV4		0x3
#define MAIN_INTFREQ5		0x9
#define MAIN_FRACFREQ5		0x374BC6
#define MAIN_MDIV5		0xC
#define MAIN_MDIV6		0x48
#define MAIN_MDIV7		0x4
#define DDR_N			59
#define DDR_P			0x1
#define DDR_MDIV1		0x2
#define DDR_INTFREQ2		0x8
#define DDR_FRACFREQ2		0xD99999
#define DDR_MDIV2		0x1E
#define DDR_INTFREQ3		0x8
#define DDR_FRACFREQ3		0x0
#define DDR_MDIV3		0x4
#define DDR_INTFREQ4		0xE /* Expansion DDR clk */
#define DDR_FRACFREQ4		0x0
#define DDR_MDIV4		0x4
#define DDR_INTFREQ5		0xE /* Expansion DDR clk */
#define DDR_FRACFREQ5		0x0
#define DDR_MDIV5		0x4
#define CONTROL_STATUS			(CTRL_BASE + 0x40)
#define DDR_RCD				(CTRL_BASE + 0x070C)
#define CM_TIMER1_CLKSEL		(PRCM_BASE + 0x390)
#define CM_ALWON_CUST_EFUSE_CLKCTRL	(PRCM_BASE + 0x1628)
#define INTCPS_SYSCONFIG	0x48200010
#define CM_SYSCLK10_CLKSEL	0x48180324
