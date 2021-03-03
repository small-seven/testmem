#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <panel.h>
#include <syscon.h>
#include <video_bridge.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch-tegra/dc.h>
#include "displayport.h"
#include "sor.h"
#define DEBUG_SOR 0
#define APBDEV_PMC_DPD_SAMPLE				0x20
#define APBDEV_PMC_DPD_SAMPLE_ON_DISABLE		0
#define APBDEV_PMC_DPD_SAMPLE_ON_ENABLE			1
#define APBDEV_PMC_SEL_DPD_TIM				0x1c8
#define APBDEV_PMC_SEL_DPD_TIM_SEL_DPD_TIM_DEFAULT	0x7f
#define APBDEV_PMC_IO_DPD2_REQ				0x1c0
#define APBDEV_PMC_IO_DPD2_REQ_LVDS_SHIFT		25
#define APBDEV_PMC_IO_DPD2_REQ_LVDS_OFF			(0 << 25)
#define APBDEV_PMC_IO_DPD2_REQ_LVDS_ON			(1 << 25)
#define APBDEV_PMC_IO_DPD2_REQ_CODE_SHIFT               30
#define APBDEV_PMC_IO_DPD2_REQ_CODE_DEFAULT_MASK        (0x3 << 30)
#define APBDEV_PMC_IO_DPD2_REQ_CODE_IDLE                (0 << 30)
#define APBDEV_PMC_IO_DPD2_REQ_CODE_DPD_OFF             (1 << 30)
#define APBDEV_PMC_IO_DPD2_REQ_CODE_DPD_ON              (2 << 30)
#define APBDEV_PMC_IO_DPD2_STATUS			0x1c4
#define APBDEV_PMC_IO_DPD2_STATUS_LVDS_SHIFT		25
#define APBDEV_PMC_IO_DPD2_STATUS_LVDS_OFF		(0 << 25)
#define APBDEV_PMC_IO_DPD2_STATUS_LVDS_ON		(1 << 25)
#if DEBUG_SOR
#define DUMP_REG(a) printk(BIOS_INFO, \
#endif
#if DEBUG_SOR
#endif
