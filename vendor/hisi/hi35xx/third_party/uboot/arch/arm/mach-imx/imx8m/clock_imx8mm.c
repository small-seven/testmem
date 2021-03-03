#include <common.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/io.h>
#include <clk.h>
#include <clk-uclass.h>
#include <dt-bindings/clock/imx8mm-clock.h>
#include <div64.h>
#include <errno.h>
#ifdef CONFIG_SPL_BUILD
#endif
