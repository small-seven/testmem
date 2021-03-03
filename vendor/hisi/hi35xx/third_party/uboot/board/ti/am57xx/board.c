#include <common.h>
#include <env.h>
#include <init.h>
#include <palmas.h>
#include <sata.h>
#include <serial.h>
#include <usb.h>
#include <asm/omap_common.h>
#include <asm/omap_sec_common.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <asm/arch/gpio.h>
#include <asm/arch/clock.h>
#include <asm/arch/dra7xx_iodelay.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/sata.h>
#include <asm/arch/gpio.h>
#include <asm/arch/omap.h>
#include <usb.h>
#include <linux/usb/gadget.h>
#include <dwc3-uboot.h>
#include <dwc3-omap-uboot.h>
#include <ti-usb-phy-uboot.h>
#include <mmc.h>
#include <dm/uclass.h>
#include "../common/board_detect.h"
#include "mux_data.h"
#define board_is_x15()		board_ti_is("BBRDX15_")
#define board_is_x15_revb1()	(board_ti_is("BBRDX15_") && \
#define board_is_x15_revc()	(board_ti_is("BBRDX15_") && \
#define board_is_am572x_evm()	board_ti_is("AM572PM_")
#define board_is_am572x_evm_reva3()	\
#define board_is_am574x_idk()	board_ti_is("AM574IDK")
#define board_is_am572x_idk()	board_ti_is("AM572IDK")
#define board_is_am571x_idk()	board_ti_is("AM571IDK")
#ifdef CONFIG_DRIVER_TI_CPSW
#include <cpsw.h>
#endif
#define GPIO_ETH_LCD		GPIO_TO_PIN(2, 22)
#define GPIO_DDR_VTT_EN 203
#define OSD_TS_FT_BUS_ADDRESS	0
#define OSD_TS_FT_CHIP_ADDRESS	0x38
#define OSD_TS_FT_REG_ID	0xA3
#define OSD_TS_FT_ID_5x46	0x54
#define OSD_TS_FT_ID_5606	0x08
#define SYSINFO_BOARD_NAME_MAX_LEN	45
#define TPS65903X_PRIMARY_SECONDARY_PAD2	0xFB
#define TPS65903X_PAD2_POWERHOLD_MASK		0x20
#ifdef CONFIG_SPL_BUILD
#else	/* CONFIG_SPL_BUILD */
#endif	/* CONFIG_SPL_BUILD */
#if CONFIG_IS_ENABLED(DM_USB) && CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if !defined(CONFIG_SPL_BUILD)
#endif
#if CONFIG_IS_ENABLED(DM_USB) && CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#ifdef CONFIG_IODELAY_RECALIBRATION
#endif
#if defined(CONFIG_MMC)
#endif
#if defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_OS_BOOT)
#ifdef CONFIG_SPL_ENV_SUPPORT
#endif
#endif
#ifdef CONFIG_DRIVER_TI_CPSW
#define RGMII0_TXCTL_DLY_VAL		((0x3 << 5) + 0x8)
#define RGMII0_TXD0_DLY_VAL		((0x3 << 5) + 0x8)
#define RGMII0_TXD1_DLY_VAL		((0x3 << 5) + 0x2)
#define RGMII0_TXD2_DLY_VAL		((0x4 << 5) + 0x0)
#define RGMII0_TXD3_DLY_VAL		((0x4 << 5) + 0x0)
#define VIN2A_D13_DLY_VAL		((0x3 << 5) + 0x8)
#define VIN2A_D17_DLY_VAL		((0x3 << 5) + 0x8)
#define VIN2A_D16_DLY_VAL		((0x3 << 5) + 0x2)
#define VIN2A_D15_DLY_VAL		((0x4 << 5) + 0x0)
#define VIN2A_D14_DLY_VAL		((0x4 << 5) + 0x0)
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_F
#endif
#if defined(CONFIG_OF_LIBFDT) && defined(CONFIG_OF_BOARD_SETUP)
#endif
#ifdef CONFIG_SPL_LOAD_FIT
#endif
#if CONFIG_IS_ENABLED(FASTBOOT) && !CONFIG_IS_ENABLED(ENV_IS_NOWHERE)
#endif
#ifdef CONFIG_TI_SECURE_DEVICE
#endif
