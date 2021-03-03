#include <config.h>
#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <net.h>
#include <command.h>
#include <tsec.h>
#include <fsl_mdio.h>
#include <linux/errno.h>
#include <asm/processor.h>
#include <asm/io.h>
#ifndef CONFIG_DM_ETH
#ifdef CONFIG_TSEC1
#endif
#ifdef CONFIG_TSEC2
#endif
#ifdef CONFIG_MPC85XX_FEC
#endif
#ifdef CONFIG_TSEC3
#endif
#ifdef CONFIG_TSEC4
#endif
#endif /* CONFIG_DM_ETH */
#define TBIANA_SETTINGS ( \
#ifndef CONFIG_TSEC_TBICR_SETTINGS
#define CONFIG_TSEC_TBICR_SETTINGS ( \
#endif /* CONFIG_TSEC_TBICR_SETTINGS */
#define CRCPOLY_LE 0xedb88320
#ifndef CONFIG_DM_ETH
#else
#endif
#ifndef CONFIG_DM_ETH
#else
#endif
#ifndef CONFIG_DM_ETH
#else
#endif
#ifndef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_NMG_ETSEC129
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_NMG_ETSEC129
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_NMG_ETSEC129
#endif
#ifndef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifndef CONFIG_DM_ETH
#else /* CONFIG_DM_ETH */
int tsec_remove(struct udevice *dev)
{
	struct tsec_private *priv = dev->priv;

	free(priv->phydev);
	mdio_unregister(priv->bus);
	mdio_free(priv->bus);

	return 0;
}
#endif /* CONFIG_DM_ETH */
