#include "hisvb.h"
#include <asm/io.h>
#include <div64.h>
#include "pwm-voltage-ctrl.h"
#include <configs/hi3556av100.h>
#define SVB_VERSION 0x10
#define HI_PMC_CTL_REG          0x04528000
#define HPM_CORE_VOL_REG        (HI_PMC_CTL_REG + 0x60)
#define HPM_CPU_VOL_REG         (HI_PMC_CTL_REG + 0x64)
#define HPM_MDA_VOL_REG         (HI_PMC_CTL_REG + 0x68)
#define CYCLE_NUM               4
#define HPM_CPU_REG0            0x1208
#define HPM_CPU_REG1            0x120c
#define HPM_MDA_REG0            0x1228
#define HPM_MDA_REG1            0x122c
#define HPM_CORE_REG0           0x1218
#define HPM_CORE_REG1           0x121c
#define HMP_CLK_REG             0x0451019c
#define HPM_CHECK_REG           0x04520158
#define VERSION_REG             0x0452015c
#define OTP_HPM_CORE_REG        0x040b0028
#define OTP_HPM_MEDIA_REG	0x040b002c
#define OTP_HPM_CPU_REG         0x040b0034
#define TSENSOR_CTRL            0x70
#define TSENSOR_STATUS0         0X78
#define VMIN_CORE	760
#define VMAX_CORE	900
#define VMIN_CPU	       750
#define VMAX_CPU	950
#define VMIN_MEDIA	680
#define VMAX_MEDIA	845
#define FREFIX_MEDIA_VOLTAGE    900 /* 900mV */
#define FREFIX_CORE_VOLTAGE 900
#define FREFIX_CPU_VOLTAGE  900
#define FREFIX_DDR_IO_VOLTAGE   1100    /* 1100mv */
#define TEMPERATURE_MIN  (-70)
#define TEMPERATURE_MAX  150
#define HPM_CORE_MIN 300
#define HPM_CORE_MAX 480
#define HPM_CPU_MIN 300
#define HPM_CPU_MAX 480
#define HPM_MDA_MIN 300
#define HPM_MDA_MAX 480
#define temperature_formula(val) (((((val) - 116) * 210) >> 10) - 40)
#define adjust_value_formula(val) ((4835 - 154 * (val)) >> 10)
#define hpm_core_voltage(val) (1317500 - 1250 * (val))
#define hpm_media_voltage(val) (1080770 - 842 * (val))
#define hpm_cpu_voltage(val) (1389000 - 1400 * (val))
#define I2C_PMU_DEBUG 0
#if (I2C_PMU_DEBUG == 1)
#endif
#ifdef I2C_PMU_ENABLE
#else
#endif
#ifdef I2C_PMU_ENABLE
#else
#endif
#ifdef I2C_PMU_ENABLE
#else
#endif
