#include <common.h>
#include <miiphy.h>
#include <netdev.h>
#include <led.h>
#include <linux/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <asm/arch/mpp.h>
#include <asm/arch/gpio.h>
#define SBX81LIFXCAT_OE_LOW		(~0)
#define SBX81LIFXCAT_OE_HIGH		(~BIT(11))
#define SBX81LIFXCAT_OE_VAL_LOW		(0)
#define SBX81LIFXCAT_OE_VAL_HIGH	(BIT(11))
#ifdef CONFIG_RESET_PHY_R
#endif
#ifdef CONFIG_MV88E61XX_SWITCH
#endif
#ifdef CONFIG_MISC_INIT_R
#endif
