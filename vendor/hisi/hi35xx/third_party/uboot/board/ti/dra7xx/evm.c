#include <common.h>
#include <env.h>
#include <init.h>
#include <palmas.h>
#include <sata.h>
#include <serial.h>
#include <linux/string.h>
#include <asm/gpio.h>
#include <usb.h>
#include <linux/usb/gadget.h>
#include <asm/omap_common.h>
#include <asm/omap_sec_common.h>
#include <asm/arch/gpio.h>
#include <asm/arch/dra7xx_iodelay.h>
#include <asm/emif.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/sata.h>
#include <dwc3-uboot.h>
#include <dwc3-omap-uboot.h>
#include <i2c.h>
#include <ti-usb-phy-uboot.h>
#include <miiphy.h>
#include "mux_data.h"
#include "../common/board_detect.h"
#define board_is_dra76x_evm()		board_ti_is("DRA76/7x")
#define board_is_dra74x_evm()		board_ti_is("5777xCPU")
#define board_is_dra72x_evm()		board_ti_is("DRA72x-T")
#define board_is_dra71x_evm()		board_ti_is("DRA79x,D")
#define board_is_dra74x_revh_or_later() (board_is_dra74x_evm() &&	\
#define board_is_dra72x_revc_or_later() (board_is_dra72x_evm() &&	\
#define board_ti_get_emif_size()	board_ti_get_emif1_size() +	\
#ifdef CONFIG_DRIVER_TI_CPSW
#include <cpsw.h>
#endif
#define GPIO_DDR_VTT_EN 203
#define SYSINFO_BOARD_NAME_MAX_LEN	37
#define NAND_PCF8575_ADDR	0x21
#define NAND_PCF8575_I2C_BUS_NUM	0
#if CONFIG_IS_ENABLED(DM_USB) && CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#if CONFIG_IS_ENABLED(DM_USB) && CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#ifdef CONFIG_SPL_BUILD
#else
#endif	/* CONFIG_SPL_BUILD */
#if defined(CONFIG_MTD_RAW_NAND)
#else
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
