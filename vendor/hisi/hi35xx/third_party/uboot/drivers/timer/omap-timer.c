#include <common.h>
#include <dm.h>
#include <errno.h>
#include <timer.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#define TCLR_START			BIT(0)	/* Start=1 */
#define TCLR_AUTO_RELOAD		BIT(1)	/* Auto reload */
#define TCLR_PRE_EN			BIT(5)	/* Pre-scaler enable */
#define TCLR_PTV_SHIFT			(2)	/* Pre-scaler shift value */
#define TIMER_CLOCK             (V_SCLK / (2 << CONFIG_SYS_PTV))
