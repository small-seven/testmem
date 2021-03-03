#include <common.h>
#include <linux/io.h>
#include <miiphy.h>
#include <netdev.h>
#include <status_led.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <asm/arch/mpp.h>
#include <asm/arch/gpio.h>
#define SBX81LIFKW_OE_LOW	~(BIT(31) | BIT(30) | BIT(28) | BIT(27) | \
#define SBX81LIFKW_OE_HIGH	~(BIT(0) | BIT(1) | BIT(7))
#define SBX81LIFKW_OE_VAL_LOW	 (BIT(31) | BIT(30) | BIT(28) | BIT(27))
#define SBX81LIFKW_OE_VAL_HIGH	 (BIT(0) | BIT(1))
#define MV88E6097_RESET		27
#ifdef CONFIG_RESET_PHY_R
#endif
#ifdef CONFIG_MV88E61XX_SWITCH
#endif
#ifdef CONFIG_MISC_INIT_R
#endif
