#include <common.h>
#include <command.h>
#include <env.h>
#include <lcd.h>
#include <libtizen.h>
#include <samsung/misc.h>
#include <errno.h>
#include <version.h>
#include <malloc.h>
#include <memalign.h>
#include <linux/sizes.h>
#include <asm/arch/cpu.h>
#include <asm/gpio.h>
#include <linux/input.h>
#include <dm.h>
#ifdef CONFIG_DM_PMIC_MAX77686
#include <power/max77686_pmic.h>
#endif
#ifdef CONFIG_DM_PMIC_MAX8998
#include <power/max8998_pmic.h>
#endif
#ifdef CONFIG_PMIC_MAX8997
#include <power/max8997_pmic.h>
#endif
#include <power/pmic.h>
#include <mmc.h>
#ifdef CONFIG_SET_DFU_ALT_INFO
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#ifdef CONFIG_REVISION_TAG
#endif
#ifdef CONFIG_OF_LIBFDT
#ifdef CONFIG_BOARD_TYPES
#endif
#endif
#endif /* CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG */
#ifdef CONFIG_LCD_MENU
#ifndef CONFIG_DM_I2C /* TODO(maintainer): Convert to driver model */
#else
#endif
#ifdef CONFIG_LCD
#ifdef CONFIG_MMC
#endif
#ifdef CONFIG_SYS_BOARD
#endif
#ifdef CONFIG_REVISION_TAG
#endif
#ifdef CONFIG_MMC
#endif
#endif
#ifdef CONFIG_LCD
#else
#endif
#ifdef CONFIG_LCD
#endif
#ifdef CONFIG_LCD
#endif
#endif /* CONFIG_LCD_MENU */
#ifdef CONFIG_CMD_BMP
#endif /* CONFIG_CMD_BMP */
