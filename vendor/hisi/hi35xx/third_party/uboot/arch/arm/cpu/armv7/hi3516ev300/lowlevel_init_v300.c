#include <compiler.h>
#include <asm/arch/platform.h>
#include <config.h>
#include <ddr_training_impl.h>
#define REG_BASE_RNG_GEN            0x10090000
#define TRNG_DSTA_FIFO_DATA_OFST    0x204
#define TRNG_DATA_ST_OFST           0x208
#define BIT_TRNG_FIFO_DATA_CNT      0x8
#define TRNG_FIFO_DATA_CNT_MASK     0xff
#define REG_PERI_CRG104             0x1a0
#define TRNG_CLK_ENABLE             (0x1<<3)
#define TRNG_CLK_DISABLE            ~(0x1<<3)
#define TRNG_CTRL_DEF_VAL           0xa
#define HISEC_COM_TRNG_CTRL_OFST    0x200
#define REG_BASE_MISC               0x12030000
#define DDR_CA0_OFST                0x28
#define DDR_CA1_OFST                0x2C
#define DDR_CA2_OFST                0x30
#define REG_BASE_DDRC               0x120d0000
#define DDRC_CTRL_SREF_OFST         (0x8000 + 0x0)
#define DDRC_CFG_DDRMODE_OFST       (0x8000 + 0x50)
#define DDRC_CURR_FUNC_OFST         (0x8000 + 0x294)
#define DDRC_CHANNEL_VALID_MASK     0xf
#define DDRC_SELF_REFURBISH_MASK    0x1
#define DDRC_SELF_REFURBISH_EN      0x1
#define DDRC_SELF_REFURBISH_EXIT    (0x1 << 1)
#define HPM_CORE_MIN 150
#define HPM_CORE_MAX 350
#define TEMPERATURE_MIN 117
#define TEMPERATURE_MAX 841
#define HPM_CORE_VALUE_MIN  190
#define HPM_CORE_VALUE_MAX  310
#undef reg_get
#undef reg_set
#define reg_get(addr) readl(addr)
#define reg_set(addr, val) writel(val, (unsigned int)(addr))
#define temperature_formula(val) (((((val) - 117) * 212) >> 10) - 40)
#define hpm_formula(hpm, temp)  ((hpm) + 4 + ((((temp) - 70) * 205) >> 10))
#define volt_formula(val) (1287 - ((1514 * (val)) >> 10))
#define duty_formula(val)  (((unsigned int)((1099 - (val)) * 460) >> 10) - 1)
#define svb_pwm_reg_val(val) ((((val) << 16) & 0XFFFF0000) + 0x0c75)
#define SVB_VER_16EV300             0x10
#define CYCLE_NUM 4
#define  HPM_CORE_REG0 0x120280d8
#define  HPM_CORE_REG1 0x120280dc
#define SVB_PWM_REG 0X120280b0
#define SVB_VER_REG         0x12020168
#define  HPM_CHECK_REG 0x1202015c
#define SYS_CTRL_VOLT_REG 0x12020158
#define TSENSOR_STATUS0 0x120280bc
#define OTP_HPM_CORE_REG 0x100a002c
#define DDR_REG_BASE_PHY0       0x120dc000
#define DDR_REG_BASE_DMC0       0x120d8000
#define DDR_REG_BASE_DMC1       0x120d8000
#ifdef DDR_REG_BASE_PHY1
#define DDR_REG_BASE_DMC2       0x120d9000
#define DDR_REG_BASE_DMC3       0x120d9000
#endif
#define CRG_REG_BASE            0x12010000
#define PERI_CRG_DDRT           0x198
#define DDR_REG_BASE_SYSCTRL    0x12020000
#define SYSCTRL_MISC_CTRL4      0x8010
#define DDR_PHY_DRAMCFG         0x2c    /* DRAM config register */
#define PHY_DRAMCFG_TYPE_MASK   0xf /* [3:0] */
#define PHY_DRAMCFG_TYPE_LPDDR4 0x6   /* [2:0] 110 LPDDR4 */
#define BYTE_NUM  2
#ifdef DDR_REG_BASE_PHY1
#endif
#ifdef DDR_REG_BASE_PHY1
#endif
#ifdef DDR_REG_BASE_PHY1
#endif
