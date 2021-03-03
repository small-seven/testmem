#include <common.h>
#include <dm.h>
#include <power-domain-uclass.h>
#include <regmap.h>
#include <syscon.h>
#include <reset.h>
#include <clk.h>
#include <dt-bindings/power/meson-g12a-power.h>
#include <dt-bindings/power/meson-sm1-power.h>
#define AO_RTI_GEN_PWR_SLEEP0		(0x3a << 2)
#define AO_RTI_GEN_PWR_ISO0		(0x3b << 2)
#define HHI_MEM_PD_REG0			(0x40 << 2)
#define HHI_VPU_MEM_PD_REG0		(0x41 << 2)
#define HHI_VPU_MEM_PD_REG1		(0x42 << 2)
#define HHI_VPU_MEM_PD_REG3		(0x43 << 2)
#define HHI_VPU_MEM_PD_REG4		(0x44 << 2)
#define HHI_AUDIO_MEM_PD_REG0		(0x45 << 2)
#define HHI_NANOQ_MEM_PD_REG0		(0x46 << 2)
#define HHI_NANOQ_MEM_PD_REG1		(0x47 << 2)
#define HHI_VPU_MEM_PD_REG2		(0x4d << 2)
#define SM1_EE_PD(__bit)					\
#define VPU_MEMPD(__reg)					\
#define VPU_HHI_MEMPD(__reg)					\
#define VPU_PD(__name, __top_pd, __mem, __get_power, __resets, __clks)	\
#define TOP_PD(__name, __top_pd, __mem, __get_power)			\
#define MEM_PD(__name, __mem)						\
static int meson_ee_pwrc_free(struct power_domain *power_domain)
{
	return 0;
}
