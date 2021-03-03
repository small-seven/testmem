#include <common.h>
#include <asm/arch/gpio.h>
#include <asm/arch/pmic_bus.h>
#include <asm/gpio.h>
#include <axp_pmic.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/root.h>
#include <errno.h>
#ifdef AXP_GPIO2_CTRL
#endif
#ifdef AXP_GPIO3_CTRL
#endif
#ifndef CONFIG_AXP152_POWER /* NA on axp152 */
#endif
#ifdef AXP_MISC_CTRL_N_VBUSEN_FUNC
#endif
#ifndef CONFIG_AXP152_POWER /* NA on axp152 */
#endif
#ifdef AXP_MISC_CTRL_N_VBUSEN_FUNC
#endif
#ifdef AXP_MISC_CTRL_N_VBUSEN_FUNC
#endif
