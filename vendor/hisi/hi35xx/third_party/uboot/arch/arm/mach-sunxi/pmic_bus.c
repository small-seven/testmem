#include <common.h>
#include <asm/arch/p2wi.h>
#include <asm/arch/rsb.h>
#include <i2c.h>
#include <asm/arch/pmic_bus.h>
#define AXP152_I2C_ADDR			0x30
#define AXP209_I2C_ADDR			0x34
#define AXP221_CHIP_ADDR		0x68
#define AXP221_CTRL_ADDR		0x3e
#define AXP221_INIT_DATA		0x3e
#define AXP223_DEVICE_ADDR		0x3a3
#define AXP223_RUNTIME_ADDR		0x2d
#if defined CONFIG_AXP221_POWER || defined CONFIG_AXP809_POWER || defined CONFIG_AXP818_POWER
# ifdef CONFIG_MACH_SUN6I
# elif defined CONFIG_MACH_SUN8I_R40
# else
# endif
#endif
#ifdef CONFIG_AXP152_POWER
#elif defined CONFIG_AXP209_POWER
#elif defined CONFIG_AXP221_POWER || defined CONFIG_AXP809_POWER || defined CONFIG_AXP818_POWER
# ifdef CONFIG_MACH_SUN6I
# elif defined CONFIG_MACH_SUN8I_R40
# else
# endif
#endif
#ifdef CONFIG_AXP152_POWER
#elif defined CONFIG_AXP209_POWER
#elif defined CONFIG_AXP221_POWER || defined CONFIG_AXP809_POWER || defined CONFIG_AXP818_POWER
# ifdef CONFIG_MACH_SUN6I
# elif defined CONFIG_MACH_SUN8I_R40
# else
# endif
#endif
