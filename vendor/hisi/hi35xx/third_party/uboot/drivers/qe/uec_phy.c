#include <common.h>
#include <net.h>
#include <malloc.h>
#include <linux/errno.h>
#include <linux/immap_qe.h>
#include <asm/io.h>
#include "uccf.h"
#include "uec.h"
#include "uec_phy.h"
#include "miiphy.h"
#include <fsl_qe.h>
#include <phy.h>
#define ugphy_printk(format, arg...)  \
#define ugphy_dbg(format, arg...)	     \
#define ugphy_err(format, arg...)	     \
#define ugphy_info(format, arg...)	     \
#define ugphy_warn(format, arg...)	     \
#ifdef UEC_VERBOSE_DEBUG
#define ugphy_vdbg ugphy_dbg
#else
#define ugphy_vdbg(ugeth, fmt, args...) do { } while (0)
#endif /* UEC_VERBOSE_DEBUG */
#ifndef CONFIG_FIXED_PHY
#define CONFIG_FIXED_PHY	0xFFFFFFFF /* Fixed PHY (PHY-less) */
#endif
#ifndef CONFIG_SYS_FIXED_PHY_PORTS
#define CONFIG_SYS_FIXED_PHY_PORTS	/* default is an empty array */
#endif
#ifndef CONFIG_SYS_BITBANG_PHY_PORTS
#define CONFIG_SYS_BITBANG_PHY_PORTS	/* default is an empty array */
#endif
#if defined(CONFIG_BITBANGMII)
#endif /* CONFIG_BITBANGMII */
#if defined(CONFIG_BITBANGMII)
#endif /* CONFIG_BITBANGMII */
#if defined(CONFIG_BITBANGMII)
#endif /* CONFIG_BITBANGMII */
#ifdef CONFIG_PHY_MODE_NEED_CHANGE
#endif
