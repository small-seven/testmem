#include <common.h>
#include <command.h>
#include <asm/arch/pmic_bus.h>
#include <axp_pmic.h>
#ifdef CONFIG_AXP_ALDO3_VOLT_SLOPE_08
#  define AXP209_VRC_SLOPE AXP209_VRC_LDO3_800uV_uS
#endif
#ifdef CONFIG_AXP_ALDO3_VOLT_SLOPE_16
#  define AXP209_VRC_SLOPE AXP209_VRC_LDO3_1600uV_uS
#endif
#if defined CONFIG_AXP_ALDO3_VOLT_SLOPE_NONE || !defined AXP209_VRC_SLOPE
#  define AXP209_VRC_SLOPE 0x00
#endif
#ifdef CONFIG_AXP_ALDO3_INRUSH_QUIRK
#endif
