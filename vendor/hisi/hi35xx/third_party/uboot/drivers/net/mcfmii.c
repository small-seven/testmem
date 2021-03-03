#include <common.h>
#include <config.h>
#include <net.h>
#include <netdev.h>
#ifdef CONFIG_MCF547x_8x
#include <asm/fsl_mcdmafec.h>
#else
#include <asm/fec.h>
#endif
#include <asm/immap.h>
#include <linux/mii.h>
#if defined(CONFIG_CMD_NET)
#undef MII_DEBUG
#undef ET_DEBUG
#if defined(CONFIG_SYS_DISCOVER_PHY) || defined(CONFIG_CMD_MII)
#include <miiphy.h>
#define mk_mii_read(ADDR, REG)		(0x60020000 | ((ADDR << 23) | \
#define mk_mii_write(ADDR, REG, VAL)	(0x50020000 | ((ADDR << 23) | \
#ifndef CONFIG_SYS_UNSPEC_PHYID
#	define CONFIG_SYS_UNSPEC_PHYID		0
#endif
#ifndef CONFIG_SYS_UNSPEC_STRID
#	define CONFIG_SYS_UNSPEC_STRID		0
#endif
#ifdef CONFIG_MCF547x_8x
typedef struct fec_info_dma FEC_INFO_T;
#define FEC_T fecdma_t
#else
typedef struct fec_info_s FEC_INFO_T;
#define FEC_T fec_t
#endif

typedef struct phy_info_struct {
	u32 phyid;
	char *strid;
} phy_info_t;
#if defined(CONFIG_SYS_UNSPEC_PHYID) && defined(CONFIG_SYS_UNSPEC_STRID)
#endif
#ifdef ET_DEBUG
#endif
#endif				/* CONFIG_SYS_DISCOVER_PHY || (CONFIG_MII) */
#if defined(CONFIG_SYS_DISCOVER_PHY)
#define MAX_PHY_PASSES 11
#ifdef ET_DEBUG
#endif
#ifdef ET_DEBUG
#endif
#ifdef ET_DEBUG
#endif
#ifdef ET_DEBUG
#endif
#endif				/* CONFIG_SYS_DISCOVER_PHY */
#ifdef MII_DEBUG
#endif
#ifdef MII_DEBUG
#endif
#ifdef MII_DEBUG
#endif
#endif				/* CONFIG_CMD_NET */
