#include <common.h>
#include <init.h>
#include <asm/arch/immap_ls102xa.h>
#include <asm/arch/clock.h>
#include <asm/arch/fsl_serdes.h>
#include <asm/arch/ls102xa_stream_id.h>
#include <asm/arch/ls102xa_devdis.h>
#include <asm/arch/ls102xa_soc.h>
#include <fsl_csu.h>
#include <fsl_immap.h>
#include <netdev.h>
#include <fsl_mdio.h>
#include <tsec.h>
#include <spl.h>
#include <fsl_validate.h>
#include "../common/sleep.h"
#define DDR_SIZE		0x40000000
#ifndef CONFIG_QSPI_BOOT
#endif
#if (!defined(CONFIG_SPL) || defined(CONFIG_SPL_BUILD))
#endif
#ifdef CONFIG_TSEC_ENET
#ifdef CONFIG_TSEC1
#endif
#ifdef CONFIG_TSEC2
#endif
#endif
#ifdef CONFIG_TSEC_ENET
#endif
#ifdef CONFIG_SPL_BUILD
#ifdef CONFIG_LAYERSCAPE_NS_ACCESS
#endif
#endif
#ifndef CONFIG_SYS_FSL_NO_SERDES
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#endif
#if defined(CONFIG_MISC_INIT_R)
#ifdef CONFIG_FSL_DEVICE_DISABLE
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#endif
#ifdef CONFIG_PCI
#endif
