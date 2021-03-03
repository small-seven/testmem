#include <common.h>
#include <malloc.h>
#include <mmc.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/dma.h>
#include <bouncebuf.h>
#define	MXSMMC_MAX_TIMEOUT	10000
#define MXSMMC_SMALL_TRANSFER	512
#if !CONFIG_IS_ENABLED(DM_MMC)
#else /* CONFIG_IS_ENABLED(DM_MMC) */
#include <dm/device.h>
#include <dm/read.h>
#include <dt-structs.h>
#ifdef CONFIG_MX28
#define dtd_fsl_imx_mmc dtd_fsl_imx28_mmc
#else /* CONFIG_MX23 */
#define dtd_fsl_imx_mmc dtd_fsl_imx23_mmc
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif /* CONFIG_IS_ENABLED(DM_MMC) */
#if !CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#endif
#if defined(CONFIG_MX23)
#elif defined(CONFIG_MX28)
#endif
#if CONFIG_IS_ENABLED(DM_MMC)
#define MXS_SSP_IMX23_CLKID_SSP0 33
#define MXS_SSP_IMX28_CLKID_SSP0 46
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#else
#endif
#ifdef CONFIG_MX28
#else /* CONFIG_MX23 */
#endif
#if CONFIG_IS_ENABLED(BLK)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifdef CONFIG_MX28
#else /* CONFIG_MX23 */
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(BLK)
#endif
#endif /* CONFIG_DM_MMC */
