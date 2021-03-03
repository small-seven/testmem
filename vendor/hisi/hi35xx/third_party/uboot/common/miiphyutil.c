#include <common.h>
#include <dm.h>
#include <miiphy.h>
#include <phy.h>
#include <asm/types.h>
#include <linux/list.h>
#include <malloc.h>
#include <net.h>
#undef MII_DEBUG
#undef debug
#ifdef MII_DEBUG
#define debug(fmt, args...)	printf(fmt, ##args)
#else
#define debug(fmt, args...)
#endif /* MII_DEBUG */
void mdio_free(struct mii_dev *bus)
{
	free(bus);
}
#ifndef CONFIG_PHYLIB
#ifdef CONFIG_PHY_RESET_DELAY
#endif
#endif /* !PHYLIB */
#if defined(CONFIG_PHY_GIGE)
#endif /* CONFIG_PHY_GIGE */
#if defined(CONFIG_PHY_GIGE)
#endif /* CONFIG_PHY_GIGE */
#if defined(CONFIG_PHY_GIGE)
#else
#endif
#ifdef CONFIG_SYS_FAULT_ECHO_LINK_DOWN
#endif
