#include <asm/arch/platform.h>
#include <config.h>
#include <ddr_interface.h>
#define HI_SYS_CTL_REG  SYS_CTRL_REG_BASE
#define OK 0
#define ERROR (-1)
#define DDR_CA0_OFST        0x88
#define DDR_CA1_OFST        0x8c
#define DDR_CA2_OFST        0x90
#define DDRC_CTRL_SREF_OFST     (0x8000 + 0x0)
#define DDRC_CFG_DDRMODE_OFST   (0x8000 + 0X50)
#define DDRC_CURR_FUNC_OFST     (0x8000 + 0x294)
#define DDRC1_CTRL_SREF_OFST    (0x9000 + 0x0)
#define DDRC1_CFG_DDRMODE_OFST  (0x9000 + 0X50)
#define DDRC1_CURR_FUNC_OFST    (0x9000 + 0x294)
#define DDRC2_CTRL_SREF_OFST    (0xa000 + 0x0)
#define DDRC2_CFG_DDRMODE_OFST  (0xa000 + 0X50)
#define DDRC2_CURR_FUNC_OFST    (0xa000 + 0x294)
#define DDRC3_CTRL_SREF_OFST    (0xb000 + 0x0)
#define DDRC3_CFG_DDRMODE_OFST  (0xb000 + 0X50)
#define DDRC3_CURR_FUNC_OFST    (0xb000 + 0x294)
#define DDRC_SELF_REFURBISH_MASK    0x1
#define DDR_REG_BASE_PHY0       0x0460c000
#define DDR_REG_BASE_DMC0       0x04608000
#define DDR_REG_BASE_DMC1       0x04609000
#ifdef DDR_REG_BASE_PHY1
#define DDR_REG_BASE_DMC2       0x0460a000
#define DDR_REG_BASE_DMC3       0x0460b000
#endif
#define DDR_PHY_DRAMCFG     0x2c    /* DRAM config register */
#define PHY_DRAMCFG_TYPE_MASK   0xf /* [3:0] */
#define PHY_DRAMCFG_TYPE_LPDDR4 0x6   /* [2:0] 110 LPDDR4 */
#ifdef DDR_SCRAMB_ENABLE
#define REG_BASE_MISC       0x04528000
#define MISC_CTRL88_OFST    0x88
#define MISC_CTRL8C_OFST    0x8c
#define MISC_CTRL90_OFST    0x90
#define REG_BASE_DDRC       DDRC0_REG_BASE
#define DDRC_0_CTRL_SREF_OFST   0x8000 + 0x0
#define DDRC_0_CURR_FUNC_OFST   0x8000 + 0x294
#define DDRC_1_CTRL_SREF_OFST   0x9000 + 0x0
#define DDRC_1_CURR_FUNC_OFST   0x9000 + 0x294
#define REG_BASE_RNG_GEN        0x04090000
#define TRNG_DSTA_FIFO_DATA_OFST    0x204
#define TRNG_DATA_ST_OFST       0x208
#define HISEC_COM_TRNG_CTRL_OFST    0x200
#define REG_PERI_CRG101         0x0194
#define BIT_TRNG_FIFO_DATA_CNT      0x8
#define TRNG_FIFO_DATA_CNT_MASK     0xff
#define TRNG_CTRL_DEF_VAL       0xa
#define TRNG_CLK_ENABLE         (0x1 << 13)
#define TRNG_DO_SRST            (0x1 << 12)
#define TRNG_CLK_DISABLE        ~(0x1 << 13)
#define TRNG_UNDO_SRST          ~(0x1 << 12)
#undef reg_get
#define reg_get(addr) (*(volatile unsigned int *)((long)addr))
#undef reg_set
#define reg_set(addr, val) (*(volatile unsigned int *)((long)addr) = (val))
#endif /* DDR_SCRAMB_ENABLE */
#define SVB_VERSION 0x10
#define HI_PMC_CTL_REG      0x04528000
#define HPM_CORE_VOL_REG    (HI_PMC_CTL_REG + 0x60)
#define HPM_MDA_VOL_REG   (HI_PMC_CTL_REG + 0x68)
#define CYCLE_NUM       4
#define HPM_CPU_REG0    0x1208
#define HPM_CPU_REG1    0x120c
#define HPM_MDA_REG0    0x1228
#define HPM_MDA_REG1    0x122c
#define HPM_CORE_REG0   0x1218
#define HPM_CORE_REG1   0x121c
#define HMP_CLK_REG 0x0451019c
#define HPM_CHECK_REG 0x04520158
#define VERSION_REG 0x0452015c
#define OTP_HPM_CORE_REG    0x040b0028
#define OTP_HPM_MDA_REG 0x040b002c
#define OTP_HPM_CPU_REG 0x040b0034
#define TSENSOR_CTRL    0x70
#define TSENSOR_STATUS0 0X78
#define VMIN_CORE 840000
#define VMAX_CORE 940000
#define VMIN_MDA 868000
#define VMAX_MDA 973000
#define HPM_CORE_MIN 300
#define HPM_CORE_MAX 480
#define HPM_CPU_MIN 300
#define HPM_CPU_MAX 480
#define HPM_MDA_MIN 300
#define HPM_MDA_MAX 480
#define TEMPERATURE_MIN  (-70)
#define TEMPERATURE_MAX  150
#define temperature_formula(val)  (((((val) - 116) * 210) >> 10) - 40)
#define adjust_value_formula(val)  ((4835 - 154 * (val)) >> 10)
#define hpm_core_vol_reg_val(val)  ((((943000 - (val)) * 80) & 0xffff0000) + 0x19f5)
#define hpm_mda_vol_reg_val(val) ((((1000000 - (val)) * 68) & 0xffff0000) + 0x19f5)
#define hpm_core_mv1000(val) (1377500 - 1250 * (unsigned long long)(val))
#define hpm_mda_mv1000(val) (1477000 - 1400 * (unsigned long long)(val))
#ifdef DDR_REG_BASE_PHY1
#endif
#ifdef DDR_SCRAMB_ENABLE
#endif
