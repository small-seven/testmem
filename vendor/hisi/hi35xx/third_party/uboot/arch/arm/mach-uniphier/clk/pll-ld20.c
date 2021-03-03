#include <linux/delay.h>
#include "../init.h"
#include "../sc64-regs.h"
#include "pll.h"
#define SC_CPLLCTRL	0x1400	/* CPU/ARM */
#define SC_SPLLCTRL	0x1410	/* misc */
#define SC_SPLL2CTRL	0x1420	/* DSP */
#define SC_MPLLCTRL	0x1430	/* Video codec */
#define SC_VPPLLCTRL	0x1440	/* VPE etc. */
#define SC_GPPLLCTRL	0x1450	/* GPU/Mali */
#define SC_DPLL0CTRL	0x1460	/* DDR memory 0 */
#define SC_DPLL1CTRL	0x1470	/* DDR memory 1 */
#define SC_DPLL2CTRL	0x1480	/* DDR memory 2 */
#define SC_VPLL27FCTRL	0x1500
#define SC_VPLL27ACTRL	0x1520
#define SC_VPLL8KCTRL	0x1540
#define SC_A2PLLCTRL	0x15C0
