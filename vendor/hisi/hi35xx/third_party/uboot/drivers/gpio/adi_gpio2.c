#include <common.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#define RESOURCE_LABEL_SIZE	16
#define map_entry(m, i)      reserved_##m##_map[gpio_bank(i)]
#define is_reserved(m, i, e) (map_entry(m, i) & gpio_bit(i))
#define reserve(m, i)        (map_entry(m, i) |= gpio_bit(i))
#define unreserve(m, i)      (map_entry(m, i) &= ~gpio_bit(i))
#define DECLARE_RESERVED_MAP(m, c) unsigned short reserved_##m##_map[c]
#if defined(CONFIG_BF54x)
#endif
#if defined(CONFIG_BF54x)
#else
#endif
void peripheral_free(unsigned short per)
{
	unsigned short ident = P_IDENT(per);

	if (per & P_DONTCARE)
		return;

	if (!(per & P_DEFINED))
		return;

	if (unlikely(!is_reserved(peri, ident, 0)))
		return;

	if (!(per & P_MAYSHARE))
		port_setup(ident, GPIO_USAGE);

	unreserve(peri, ident);

	set_label(ident, "free");
}
int gpio_free(unsigned gpio)
{
	if (check_gpio(gpio) < 0)
		return -1;

	if (unlikely(!is_reserved(gpio, gpio, 0))) {
		gpio_error(gpio);
		return -1;
	}

	unreserve(gpio, gpio);

	set_label(gpio, "free");

	return 0;
}
#ifdef ADI_SPECIAL_GPIO_BANKS
void special_gpio_free(unsigned gpio)
{
	if (unlikely(!is_reserved(special_gpio, gpio, 0))) {
		gpio_error(gpio);
		return;
	}

	unreserve(special_gpio, gpio);
	unreserve(peri, gpio);
	set_label(gpio, "free");
}
#endif
#if defined(CONFIG_BF54x)
#else
#endif
#if defined(CONFIG_BF54x)
#else
#endif
