#include <common.h>
#include <dm.h>
#include <power-domain-uclass.h>
#include <regmap.h>
#include <syscon.h>
#include <reset.h>
#include <clk.h>
#define AO_RTI_GEN_PWR_SLEEP0		(0x3a << 2)
#define GEN_PWR_VPU_HDMI		BIT(8)
#define GEN_PWR_VPU_HDMI_ISO		BIT(9)
#define HHI_MEM_PD_REG0			(0x40 << 2)
#define HHI_VPU_MEM_PD_REG0		(0x41 << 2)
#define HHI_VPU_MEM_PD_REG1		(0x42 << 2)
#define HHI_VPU_MEM_PD_REG2		(0x4d << 2)
static int meson_pwrc_vpu_free(struct power_domain *power_domain)
{
	return 0;
}
