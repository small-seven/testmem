#include <compiler.h>
#include <asm/arch/platform.h>
#include <config.h>
#include <ddr_interface.h>
#include <hicpu_common.h>
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
#define REG_BASE_DDRC               0x12060000
#define DDRC_CTRL_SREF_OFST         (0x8000 + 0x0)
#define DDRC_CFG_DDRMODE_OFST       (0x8000 + 0x50)
#define DDRC_CURR_FUNC_OFST         (0x8000 + 0x294)
#define DDRC_CHANNEL_VALID_MASK     0xf
#define DDRC_SELF_REFURBISH_MASK    0x1
#define DDRC_SELF_REFURBISH_EN      0x1
#define DDRC_SELF_REFURBISH_EXIT    (0x1 << 1)
#define  CHIP_3516DV300  0x3516D300
#define  CHIP_3516C500  0x3516C500
#define  CHIP_3559V200  0x35590200
#define  CHIP_3556V200  0x35560200
#define  CHIP_3516A300  0x3516A300
#undef reg_get
#undef reg_set
#define reg_get(addr) readl(addr)
#define reg_set(addr, val) writel(val, (unsigned int)(addr))
#define hpm_formula(hpm, temp)  ((hpm) + 6 + ((((unsigned int)(temp) - 70) * 205) >> 10))
#define temperature_formula(val)  (((((val) - 136) * 1704) >> 13) - 40)
#define svb_formula(val) ((((1050000 - (val)) * 31) & 0xffff0000) + 0x0c75)
#define SVB_VER_REG       0x120200ac
#define SVB_VER_16CV500   0x10
#define SVB_VER_16DV300   0x10
#define SVB_VER_16AV300   0x01
#define SVB_VER_59V200    0x10
#define SVB_VER_56V200    0x10
#define RATIO_16CV500     1500
#define RATIO_16DV300     1500
#define RATIO_16AV300     1500
#define RATIO_59V200      1500
#define RATIO_56V200      1634
#define HI_PMC_CTL_REG 0x120300b0
#define OTP_HPM_CORE_REG 0x100a002c
#define HMP_CLK_REG 0x120101c0
#define HI_HPM_CTL_REG 0x120300d0
#define CYCLE_NUM 4
#define  HPM_CORE_REG0 0x120300d8
#define  HPM_CORE_REG1 0x120300dc
#define  HPM_CHECK_REG 0x12020098
#define TSENSOR_CTRL 0xb4
#define TSENSOR_STATUS0 0xbc
#define SYS_CHIP_ID 0x12020ee0
#define VMIN_CORE_16CV500 820000
#define VMAX_CORE_16CV500 980000
#define Y_16CV500 1267203
#define VMIN_CORE_16DV300 830000
#define VMAX_CORE_16DV300 990000
#define Y_16DV300 1274198
#define VMIN_CORE_16AV300 850000
#define VMAX_CORE_16AV300 1010000
#define Y_16AV300 1294198
#define VMIN_CORE_59V200 820000
#define VMAX_CORE_59V200 980000
#define Y_59V200 1264198
#define VMIN_CORE_56V200 810000
#define VMAX_CORE_56V200 1000000
#define Y_56V200 1309061
#define HPM_CORE_MIN 150
#define HPM_CORE_MAX 350
#define TEMPERATURE_MIN  (-40)
#define TEMPERATURE_MAX  125
#define DDR_REG_BASE_PHY0       0x1206c000
#define DDR_REG_BASE_DMC0       0x12068000
#define DDR_REG_BASE_DMC1       0x12069000
#ifdef DDR_REG_BASE_PHY1
#define DDR_REG_BASE_DMC2       0x1206a000
#define DDR_REG_BASE_DMC3       0x1206b000
#endif
#define DDR_PHY_DRAMCFG		0x2c    /* DRAM config register */
#define PHY_DRAMCFG_TYPE_MASK   0xf /* [3:0] */
#define PHY_DRAMCFG_TYPE_LPDDR4 0x6   /* [2:0] 110 LPDDR4 */
#ifdef DDR_REG_BASE_PHY1
#endif
