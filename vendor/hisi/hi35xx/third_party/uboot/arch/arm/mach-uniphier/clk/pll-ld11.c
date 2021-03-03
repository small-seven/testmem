#include <linux/delay.h>
#include <linux/io.h>
#include "../init.h"
#include "../sc64-regs.h"
#include "pll.h"
#define SC_CPLLCTRL	0x1400	/* CPU/ARM */
#define SC_SPLLCTRL	0x1410	/* misc */
#define SC_MPLLCTRL	0x1430	/* DSP */
#define SC_VSPLLCTRL	0x1440	/* Video codec, VPE etc. */
#define SC_DPLLCTRL	0x1460	/* DDR memory */
#define SC_VPLL27FCTRL	0x1500
#define SC_VPLL27ACTRL	0x1520
