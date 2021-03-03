#include <common.h>
#include <config.h>
#include <cpu_func.h>
#include <env.h>
#include <init.h>
#include <irq_func.h>
#include <linux/printk.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include <asm/arcregs.h>
#include <fdt_support.h>
#include <dwmmc.h>
#include <malloc.h>
#include <usb.h>
#include "clk-lib.h"
#include "env-lib.h"
#define ALL_CPU_MASK		GENMASK(NR_CPUS - 1, 0)
#define MASTER_CPU_ID		0
#define APERTURE_SHIFT		28
#define NO_CCM			0x10
#define SLAVE_CPU_READY		0x12345678
#define BOOTSTAGE_1		1 /* after SP, FP setup, before HW init */
#define BOOTSTAGE_2		2 /* after HW init, before self halt */
#define BOOTSTAGE_3		3 /* after self halt */
#define BOOTSTAGE_4		4 /* before app launch */
#define BOOTSTAGE_5		5 /* after app launch, unreachable */
#define RESET_VECTOR_ADDR	0x0
#define CREG_BASE		(ARC_PERIPHERAL_BASE + 0x1000)
#define CREG_CPU_START		(CREG_BASE + 0x400)
#define CREG_CPU_START_MASK	0xF
#define SDIO_BASE		(ARC_PERIPHERAL_BASE + 0xA000)
#define SDIO_UHS_REG_EXT	(SDIO_BASE + 0x108)
#define SDIO_UHS_REG_EXT_DIV_2	(2 << 30)
#define arc_read_uncached_32(ptr)	\
#define arc_write_uncached_32(ptr, data)\
#define UPDATE_VAL	1
#define CREG_AXI_M_SLV0(m)  ((void __iomem *)(CREG_BASE + 0x020 * (m)))
#define CREG_AXI_M_SLV1(m)  ((void __iomem *)(CREG_BASE + 0x020 * (m) + 0x004))
#define CREG_AXI_M_OFT0(m)  ((void __iomem *)(CREG_BASE + 0x020 * (m) + 0x008))
#define CREG_AXI_M_OFT1(m)  ((void __iomem *)(CREG_BASE + 0x020 * (m) + 0x00C))
#define CREG_AXI_M_UPDT(m)  ((void __iomem *)(CREG_BASE + 0x020 * (m) + 0x014))
#define CREG_AXI_M_HS_CORE_BOOT	((void __iomem *)(CREG_BASE + 0x010))
#define CREG_PAE	((void __iomem *)(CREG_BASE + 0x180))
#define CREG_PAE_UPDT	((void __iomem *)(CREG_BASE + 0x194))
