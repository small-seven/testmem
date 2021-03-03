#include <asm/arch/platform.h>
#include <config.h>
#include "ddr_interface.h"
#define HI_SYS_CTL_REG  SYS_CTRL_REG_BASE
#define OK 0
#define ERROR (-1)
#define DDR_CA0_OFST        0x88
#define DDR_CA1_OFST        0x8c
#define DDR_CA2_OFST        0x90
#define REG_BASE_DDRC           0x12060000
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
#define DDR_REG_BASE_DMC0       0x12068000
#define DDR_REG_BASE_DMC1       0x12069000
#define DDR_REG_BASE_DMC2       0x1206a000
#define DDR_REG_BASE_DMC3       0x1206b000
#define DDR_REG_BASE_PHY0       0x1206c000
#define DDR_REG_BASE_PHY1       0x1206e000
#define DDR_PHY_DRAMCFG     0x2c    /* DRAM config register */
#define PHY_DRAMCFG_TYPE_MASK   0xf /* [3:0] */
#define PHY_DRAMCFG_TYPE_LPDDR4 0x6   /* [2:0] 110 LPDDR4 */
#define REG_BASE_MISC       0x12030000
#ifdef DDR_SCRAMB_ENABLE
#define MISC_CTRL104_OFST   0x104
#define MISC_CTRL108_OFST   0x108
#define MISC_CTRL10C_OFST   0x10c
#define DDRC_0_CTRL_SREF_OFST   (0x8000 + 0x0)
#define DDRC_0_CURR_FUNC_OFST   (0x8000 + 0x294)
#define DDRC_1_CTRL_SREF_OFST   (0x9000 + 0x0)
#define DDRC_1_CURR_FUNC_OFST   (0x9000 + 0x294)
#undef reg_get
#define reg_get(addr) (*(volatile unsigned int *)((long)addr))
#undef reg_set
#define reg_set(addr, val) (*(volatile unsigned int *)((long)addr) = (val))
#define REG_BASE_RNG_GEN        0x10230000
#define TRNG_DSTA_FIFO_DATA_OFST    0x204
#define TRNG_DATA_ST_OFST       0x208
#define HISEC_COM_TRNG_CTRL_OFST    0x200
#define REG_PERI_CRG101     0x0194
#define BIT_TRNG_FIFO_DATA_CNT      0x8
#define TRNG_FIFO_DATA_CNT_MASK     0xff
#define TRNG_CTRL_DEF_VAL       0xa
#define TRNG_CLK_ENABLE     (0x1 << 13)
#define TRNG_DO_SRST        (0x1 << 12)
#define TRNG_CLK_DISABLE    ~(0x1 << 13)
#define TRNG_UNDO_SRST      ~(0x1 << 12)
#endif /* DDR_SCRAMB_ENABLE */
#ifdef SVB_ENABLE
#define HI_PMC_CTL_REG      0x12030000
#define HPM_CORE_VOL_REG    (HI_PMC_CTL_REG + 0x60)
#define HPM_GPU_VOL_REG     (HI_PMC_CTL_REG + 0x64)
#define HPM_MDA_VOL_REG     (HI_PMC_CTL_REG + 0x68)
#define HPM_CPU_VOL_REG     (HI_PMC_CTL_REG + 0x6c)
#define CYCLE_NUM       8
#define HPM_CPU_REG0    0x1208
#define HPM_CPU_REG1    0x120c
#define HPM_MDA_REG0    0x1218
#define HPM_MDA_REG1    0x121c
#define HPM_GPU_REG0    0x1228
#define HPM_GPU_REG1    0x122C
#define HPM_CORE_REG0   0x1238
#define HPM_CORE_REG1   0x123c
#define HMP_CLK_REG     0x1201019c
#define CPU_ISO_REG     0x1d821104
#define TSENSOR_CTRL    0x70
#define TSENSOR_STATUS0 0X78
#define OTP_CPU_IF_REG       0x10250000
#define OTP_HPM_CORE_OFFSET  0x0028
#define OTP_HPM_MDA_OFFSET   0x002c
#define OTP_HPM_GPU_OFFSET   0x0030
#define OTP_HPM_CPU_OFFSET   0x0034
#define OTP_IDDQ_SENSORHUB_OFFSET     0x004c
#define SYSCTRL_BASE_REG     0x12020000
#define HPM_CORE_STORAGE_REG 0x300
#define HPM_MDA_STORAGE_REG  0x304
#define HPM_GPU_STORAGE_REG  0x308
#define HPM_CPU_STORAGE_REG  0x30c
#define CORE_VOLT_MAX    943
#define CORE_VOLT_MIN    603
#define MDA_VOLT_MAX     935
#define MDA_VOLT_MIN     603
#define GPU_VOLT_MAX     943
#define GPU_VOLT_MIN     603
#define CPU_VOLT_MAX     1078
#define CPU_VOLT_MIN     597
#define CORE_CURVE_VLOT_MAX    900
#define CORE_CURVE_VLOT_MIN    840
#define CORE_CURVE_B           13200
#define CORE_CURVE_A           12
#define MEDIA_CURVE_VLOT_MAX   880
#define MEDIA_CURVE_VLOT_MIN   780
#define MEDIA_CURVE_B          12210
#define MEDIA_CURVE_A          11
#define GPU_CURVE_VLOT_MAX     950
#define GPU_CURVE_VLOT_MIN     858
#define GPU_CURVE_B            14180
#define GPU_CURVE_A            14
#define CPU_CURVE_VLOT_MAX     988
#define CPU_CURVE_VLOT_MIN     888
#define CPU_CURVE_B            15180
#define CPU_CURVE_A            14
#define temperature_formula(val)  (((((val) - 116) * 165) / 806) - 40)
#define duty_formula(max, min, val) (((max - val) * 416 + \
#define volt_regval_formula(val) (((val) << 16) + ((416 - 1) << 4) + 0x5)
#define SVB_VER_REG         0x12020150
#define SVB_VER             0x30303030
#endif
#ifdef SVB_ENABLE
#endif
#ifdef DDR_SCRAMB_ENABLE
#endif
