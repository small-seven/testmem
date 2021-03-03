#include <common.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/iomux.h>
#include <asm/arch/imx-regs.h>
#if	defined(CONFIG_MX23)
#define	PINCTRL_BANKS		3
#define	PINCTRL_DOUT(n)		(0x0500 + ((n) * 0x10))
#define	PINCTRL_DIN(n)		(0x0600 + ((n) * 0x10))
#define	PINCTRL_DOE(n)		(0x0700 + ((n) * 0x10))
#define	PINCTRL_PIN2IRQ(n)	(0x0800 + ((n) * 0x10))
#define	PINCTRL_IRQEN(n)	(0x0900 + ((n) * 0x10))
#define	PINCTRL_IRQSTAT(n)	(0x0c00 + ((n) * 0x10))
#elif	defined(CONFIG_MX28)
#define	PINCTRL_BANKS		5
#define	PINCTRL_DOUT(n)		(0x0700 + ((n) * 0x10))
#define	PINCTRL_DIN(n)		(0x0900 + ((n) * 0x10))
#define	PINCTRL_DOE(n)		(0x0b00 + ((n) * 0x10))
#define	PINCTRL_PIN2IRQ(n)	(0x1000 + ((n) * 0x10))
#define	PINCTRL_IRQEN(n)	(0x1100 + ((n) * 0x10))
#define	PINCTRL_IRQSTAT(n)	(0x1400 + ((n) * 0x10))
#else
#error "Please select CONFIG_MX23 or CONFIG_MX28"
#endif
#define GPIO_INT_FALL_EDGE	0x0
#define GPIO_INT_LOW_LEV	0x1
#define GPIO_INT_RISE_EDGE	0x2
#define GPIO_INT_HIGH_LEV	0x3
#define GPIO_INT_LEV_MASK	(1 << 0)
#define GPIO_INT_POL_MASK	(1 << 1)
#if !CONFIG_IS_ENABLED(DM_GPIO)
int gpio_free(unsigned gpio)
{
	return 0;
}
#else /* CONFIG_DM_GPIO */
#include <dm.h>
#include <asm/gpio.h>
#include <dt-structs.h>
#include <asm/arch/gpio.h>
#define MXS_MAX_GPIO_PER_BANK		32
#ifdef CONFIG_MX28
#define dtd_fsl_imx_gpio dtd_fsl_imx28_gpio
#else /* CONFIG_MX23 */
#define dtd_fsl_imx_gpio dtd_fsl_imx23_gpio
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#else
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifdef CONFIG_MX28
#else /* CONFIG_MX23 */
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#endif /* CONFIG_DM_GPIO */
