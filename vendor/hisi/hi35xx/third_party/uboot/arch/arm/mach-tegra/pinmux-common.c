#include <common.h>
#include <asm/io.h>
#include <asm/arch/pinmux.h>
#define pmux_pingrp_isvalid(pin) (((pin) >= 0) && ((pin) < PMUX_PINGRP_COUNT))
#define pmux_func_isvalid(func) \
#define pmux_pin_pupd_isvalid(pupd) \
#define pmux_pin_tristate_isvalid(tristate) \
#ifdef TEGRA_PMX_PINS_HAVE_E_INPUT
#define pmux_pin_io_isvalid(io) \
#endif
#ifdef TEGRA_PMX_PINS_HAVE_LOCK
#define pmux_pin_lock_isvalid(lock) \
#endif
#ifdef TEGRA_PMX_PINS_HAVE_OD
#define pmux_pin_od_isvalid(od) \
#endif
#ifdef TEGRA_PMX_PINS_HAVE_IO_RESET
#define pmux_pin_ioreset_isvalid(ioreset) \
#endif
#ifdef TEGRA_PMX_PINS_HAVE_RCV_SEL
#define pmux_pin_rcv_sel_isvalid(rcv_sel) \
#endif
#ifdef TEGRA_PMX_PINS_HAVE_E_IO_HV
#define pmux_pin_e_io_hv_isvalid(e_io_hv) \
#endif
#ifdef TEGRA_PMX_GRPS_HAVE_LPMD
#define pmux_lpmd_isvalid(lpm) \
#endif
#if defined(TEGRA_PMX_PINS_HAVE_SCHMT) || defined(TEGRA_PMX_GRPS_HAVE_SCHMT)
#define pmux_schmt_isvalid(schmt) \
#endif
#if defined(TEGRA_PMX_PINS_HAVE_HSM) || defined(TEGRA_PMX_GRPS_HAVE_HSM)
#define pmux_hsm_isvalid(hsm) \
#endif
#define _R(offset)	(u32 *)((unsigned long)NV_PA_APB_MISC_BASE + (offset))
#if defined(CONFIG_TEGRA20)
#define MUX_REG(grp)	_R(0x80 + ((tegra_soc_pingroups[grp].ctl_id / 16) * 4))
#define MUX_SHIFT(grp)	((tegra_soc_pingroups[grp].ctl_id % 16) * 2)
#define PULL_REG(grp)	_R(0xa0 + ((tegra_soc_pingroups[grp].pull_id / 16) * 4))
#define PULL_SHIFT(grp)	((tegra_soc_pingroups[grp].pull_id % 16) * 2)
#define TRI_REG(grp)	_R(0x14 + (((grp) / 32) * 4))
#define TRI_SHIFT(grp)	((grp) % 32)
#else
#define REG(pin)	_R(0x3000 + ((pin) * 4))
#define MUX_REG(pin)	REG(pin)
#define MUX_SHIFT(pin)	0
#define PULL_REG(pin)	REG(pin)
#define PULL_SHIFT(pin)	2
#define TRI_REG(pin)	REG(pin)
#define TRI_SHIFT(pin)	4
#endif /* CONFIG_TEGRA20 */
#define DRV_REG(group)	_R(TEGRA_PMX_SOC_DRV_GROUP_BASE_REG + ((group) * 4))
#define MIPIPADCTRL_REG(group)	_R(TEGRA_PMX_SOC_MIPIPADCTRL_BASE_REG + ((group) * 4))
#ifdef CONFIG_TEGRA210
#define IO_SHIFT	6
#define LOCK_SHIFT	7
#ifdef TEGRA_PMX_PINS_HAVE_HSM
#define HSM_SHIFT	9
#endif
#define E_IO_HV_SHIFT	10
#define OD_SHIFT	11
#ifdef TEGRA_PMX_PINS_HAVE_SCHMT
#define SCHMT_SHIFT	12
#endif
#else
#define IO_SHIFT	5
#define OD_SHIFT	6
#define LOCK_SHIFT	7
#define IO_RESET_SHIFT	8
#define RCV_SEL_SHIFT	9
#endif
#ifdef TEGRA_PMX_SOC_HAS_IO_CLAMPING
#define APB_MISC_PP_PINMUX_GLOBAL_0 0x40
#define CLAMP_INPUTS_WHEN_TRISTATED 1
#endif
#ifdef TEGRA_PMX_PINS_HAVE_E_INPUT
#endif
#ifdef TEGRA_PMX_PINS_HAVE_LOCK
#endif
#ifdef TEGRA_PMX_PINS_HAVE_OD
#endif
#ifdef TEGRA_PMX_PINS_HAVE_IO_RESET
#endif
#ifdef TEGRA_PMX_PINS_HAVE_RCV_SEL
#endif
#ifdef TEGRA_PMX_PINS_HAVE_E_IO_HV
#endif
#ifdef TEGRA_PMX_PINS_HAVE_SCHMT
#endif
#ifdef TEGRA_PMX_PINS_HAVE_HSM
#endif
#ifdef TEGRA_PMX_PINS_HAVE_E_INPUT
#endif
#ifdef TEGRA_PMX_PINS_HAVE_LOCK
#endif
#ifdef TEGRA_PMX_PINS_HAVE_OD
#endif
#ifdef TEGRA_PMX_PINS_HAVE_IO_RESET
#endif
#ifdef TEGRA_PMX_PINS_HAVE_RCV_SEL
#endif
#ifdef TEGRA_PMX_PINS_HAVE_E_IO_HV
#endif
#ifdef TEGRA_PMX_PINS_HAVE_SCHMT
#endif
#ifdef TEGRA_PMX_PINS_HAVE_HSM
#endif
#ifdef TEGRA_PMX_SOC_HAS_DRVGRPS
#define pmux_drvgrp_isvalid(pd) (((pd) >= 0) && ((pd) < PMUX_DRVGRP_COUNT))
#define pmux_slw_isvalid(slw) \
#define pmux_drv_isvalid(drv) \
#ifdef TEGRA_PMX_GRPS_HAVE_HSM
#define HSM_SHIFT	2
#endif
#ifdef TEGRA_PMX_GRPS_HAVE_SCHMT
#define SCHMT_SHIFT	3
#endif
#ifdef TEGRA_PMX_GRPS_HAVE_LPMD
#define LPMD_SHIFT	4
#define LPMD_MASK	(3 << LPMD_SHIFT)
#endif
#define DRVDN_SHIFT	12
#define DRVDN_MASK	(0x7F << DRVDN_SHIFT)
#define DRVUP_SHIFT	20
#define DRVUP_MASK	(0x7F << DRVUP_SHIFT)
#define SLWR_SHIFT	28
#define SLWR_MASK	(3 << SLWR_SHIFT)
#define SLWF_SHIFT	30
#define SLWF_MASK	(3 << SLWF_SHIFT)
#ifdef TEGRA_PMX_GRPS_HAVE_LPMD
#endif
#ifdef TEGRA_PMX_GRPS_HAVE_SCHMT
#endif
#ifdef TEGRA_PMX_GRPS_HAVE_HSM
#endif
#ifdef TEGRA_PMX_GRPS_HAVE_LPMD
#endif
#ifdef TEGRA_PMX_GRPS_HAVE_SCHMT
#endif
#ifdef TEGRA_PMX_GRPS_HAVE_HSM
#endif
#endif /* TEGRA_PMX_SOC_HAS_DRVGRPS */
#ifdef TEGRA_PMX_SOC_HAS_MIPI_PAD_CTRL_GRPS
#define pmux_mipipadctrlgrp_isvalid(pd) (((pd) >= 0) && ((pd) < PMUX_MIPIPADCTRLGRP_COUNT))
#endif /* TEGRA_PMX_SOC_HAS_MIPI_PAD_CTRL_GRPS */
