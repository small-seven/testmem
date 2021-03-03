#include "pwm-voltage-ctrl.h"
#define HI_PMC_CTL_REG      0x04528000
#define PMC_VOLT_CORE_REG   (HI_PMC_CTL_REG + 0x60)
#define PMC_VOLT_CPU_REG    (HI_PMC_CTL_REG + 0x64)
#define PMC_VOLT_MEDIA_REG  (HI_PMC_CTL_REG + 0x68)
#define core_voltage(val) ((943000 - (val) * 1000) * 80)
#define cpu_voltage(val) ((1000000 - (val) * 1000) * 68)
#define media_voltage(val) ((943000 - (val) * 1000) * 80)
