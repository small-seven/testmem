#include <common.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/video.h>
#include <i2c.h>
#include <input.h>
#include <ipu_pixfmt.h>
#include <linux/fb.h>
#include <linux/input.h>
#include <malloc.h>
#include <stdio_dev.h>
#include "novena.h"
#define IT6251_VENDOR_ID_LOW				0x00
#define IT6251_VENDOR_ID_HIGH				0x01
#define IT6251_DEVICE_ID_LOW				0x02
#define IT6251_DEVICE_ID_HIGH				0x03
#define IT6251_SYSTEM_STATUS				0x0d
#define IT6251_SYSTEM_STATUS_RINTSTATUS			(1 << 0)
#define IT6251_SYSTEM_STATUS_RHPDSTATUS			(1 << 1)
#define IT6251_SYSTEM_STATUS_RVIDEOSTABLE		(1 << 2)
#define IT6251_SYSTEM_STATUS_RPLL_IOLOCK		(1 << 3)
#define IT6251_SYSTEM_STATUS_RPLL_XPLOCK		(1 << 4)
#define IT6251_SYSTEM_STATUS_RPLL_SPLOCK		(1 << 5)
#define IT6251_SYSTEM_STATUS_RAUXFREQ_LOCK		(1 << 6)
#define IT6251_REF_STATE				0x0e
#define IT6251_REF_STATE_MAIN_LINK_DISABLED		(1 << 0)
#define IT6251_REF_STATE_AUX_CHANNEL_READ		(1 << 1)
#define IT6251_REF_STATE_CR_PATTERN			(1 << 2)
#define IT6251_REF_STATE_EQ_PATTERN			(1 << 3)
#define IT6251_REF_STATE_NORMAL_OPERATION		(1 << 4)
#define IT6251_REF_STATE_MUTED				(1 << 5)
#define IT6251_REG_PCLK_CNT_LOW				0x57
#define IT6251_REG_PCLK_CNT_HIGH			0x58
#define IT6521_RETRY_MAX				20
