#include <common.h>
#include <cpu_func.h>
#include <malloc.h>
#include <memalign.h>
#include <spi.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/dma.h>
#define	MXS_SPI_MAX_TIMEOUT	1000000
#define	MXS_SPI_PORT_OFFSET	0x2000
#define MXS_SSP_CHIPSELECT_MASK		0x00300000
#define MXS_SSP_CHIPSELECT_SHIFT	20
#define MXSSSP_SMALL_TRANSFER	512
#if !CONFIG_IS_ENABLED(DM_SPI)
#else
#include <dm.h>
#include <errno.h>
#include <dt-structs.h>
#ifdef CONFIG_MX28
#define dtd_fsl_imx_spi dtd_fsl_imx28_spi
#else /* CONFIG_MX23 */
#define dtd_fsl_imx_spi dtd_fsl_imx23_spi
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#endif
#if !CONFIG_IS_ENABLED(DM_SPI)
#else
#endif
#if defined(CONFIG_MX23)
#elif defined(CONFIG_MX28)
#endif
#if !CONFIG_IS_ENABLED(DM_SPI)
#else
#endif
#if defined(CONFIG_MX23)
#elif defined(CONFIG_MX28)
#endif
#if !CONFIG_IS_ENABLED(DM_SPI)
#else
#endif
#ifdef CONFIG_MX28
#endif
#if !CONFIG_IS_ENABLED(DM_SPI)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_SPI)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_SPI)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_SPI)
#else /* CONFIG_DM_SPI */
#define MXS_SSP_IMX23_CLKID_SSP0 33
#define MXS_SSP_IMX28_CLKID_SSP0 46
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#else
#endif
#ifdef CONFIG_MX28
#else /* CONFIG_MX23 */
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifdef CONFIG_MX28
#else /* CONFIG_MX23 */
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#endif
