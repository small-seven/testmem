#include <common.h>
#include <cpu_func.h>
#include <env.h>
#include <init.h>
#include <sata.h>
#include <ahci.h>
#include <scsi.h>
#include <malloc.h>
#include <wdt.h>
#include <asm/arch/clk.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/psu_init_gpl.h>
#include <asm/io.h>
#include <dm/device.h>
#include <dm/uclass.h>
#include <usb.h>
#include <dwc3-uboot.h>
#include <zynqmppl.h>
#include <zynqmp_firmware.h>
#include <g_dnl.h>
#include <linux/sizes.h>
#include "pm_cfg_obj.h"
#if defined(CONFIG_FPGA) && defined(CONFIG_FPGA_ZYNQMPPL) && \
#endif
#define ZYNQMP_VERSION_SIZE		9
#define ZYNQMP_PL_STATUS_BIT		9
#define ZYNQMP_IPDIS_VCU_BIT		8
#define ZYNQMP_PL_STATUS_MASK		BIT(ZYNQMP_PL_STATUS_BIT)
#define ZYNQMP_CSU_VERSION_MASK		~(ZYNQMP_PL_STATUS_MASK)
#define ZYNQMP_CSU_VCUDIS_VER_MASK	ZYNQMP_CSU_VERSION_MASK & \
#define MAX_VARIANTS_EV			3
#if defined(CONFIG_FPGA) && defined(CONFIG_FPGA_ZYNQMPPL) && \
#endif
#if defined(CONFIG_ZYNQMP_PSU_INIT_ENABLED)
#endif
#if defined(CONFIG_SPL_BUILD)
#endif
#if defined(CONFIG_FPGA) && defined(CONFIG_FPGA_ZYNQMPPL) && \
#endif
#if !defined(CONFIG_SYS_SDRAM_BASE) && !defined(CONFIG_SYS_SDRAM_SIZE)
#else
#if defined(CONFIG_NR_DRAM_BANKS)
#endif
#endif
#if defined(CONFIG_BOARD_LATE_INIT)
#if defined(CONFIG_USB_ETHER) && !defined(CONFIG_USB_GADGET_DOWNLOAD)
#endif
#endif
