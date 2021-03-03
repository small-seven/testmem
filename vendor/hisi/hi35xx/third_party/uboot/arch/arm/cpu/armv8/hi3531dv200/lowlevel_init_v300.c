#include <asm/arch/platform.h>
#include <config.h>
#include <compiler.h>
#include "ddr_training_impl.h"
#define HI_SYS_CTL_REG  SYS_CTRL_REG_BASE
#define OK			0
#define ERROR			-1
#define DDR_CA0_OFST		0x24
#define DDR_CA1_OFST		0x28
#define DDR_CA2_OFST		0x2c
#define REG_BASE_DDRC           0x11130000
#define DDRC_CTRL_SREF_OFST     0x8000 + 0x0
#define DDRC_CFG_DDRMODE_OFST   0x8000 + 0X50
#define DDRC_CURR_FUNC_OFST     0x8000 + 0x294
#define DDRC1_CTRL_SREF_OFST    0x9000 + 0x0
#define DDRC1_CFG_DDRMODE_OFST  0x9000 + 0X50
#define DDRC1_CURR_FUNC_OFST    0x9000 + 0x294
#define DDRC2_CTRL_SREF_OFST    0xa000 + 0x0
#define DDRC2_CFG_DDRMODE_OFST  0xa000 + 0X50
#define DDRC2_CURR_FUNC_OFST    0xa000 + 0x294
#define DDRC3_CTRL_SREF_OFST    0xb000 + 0x0
#define DDRC3_CFG_DDRMODE_OFST  0xb000 + 0X50
#define DDRC3_CURR_FUNC_OFST    0xb000 + 0x294
#define DDRC_SELF_REFURBISH_MASK    (0x1)
#define REG_BASE_MISC		0x11024000
#ifdef DDR_SCRAMB_ENABLE
#undef reg_get
#define reg_get(addr) (*(volatile unsigned int *)((long)addr))
#undef reg_set
#define reg_set(addr, val) (*(volatile unsigned int *)((long)addr) = (val))
#define REG_BASE_RNG_GEN		0x10130000
#define TRNG_DSTA_FIFO_DATA_OFST	0x204
#define TRNG_DATA_ST_OFST		0x208
#define HISEC_COM_TRNG_CTRL_OFST	0x200
#define BIT_TRNG_FIFO_DATA_CNT		0x8
#define TRNG_FIFO_DATA_CNT_MASK		0xff
#define TRNG_CTRL_DEF_VAL		0xa
#define REG_PERI_CRG_TRNG		0x2d80
#define TRNG_CLK_ENABLE			(0x1 << 4)
#define TRNG_DO_SRST			(0x1 << 0)
#define TRNG_CLK_DISABLE		~(0x1 << 4)
#define TRNG_UNDO_SRST			~(0x1 << 0)
#endif /* DDR_SCRAMB_ENABLE */
#define HPM_CORE_VOL_REG		0x11029000
#define HPM_CPU_VOL_REG			0x11029004
#define HMP_CLK_REG			0x11014A80
#define CPU_HPM_CTRL0_REG		0x1102B000
#define CORE_HPM_CTRL0_REG		0x1102B010
#define HPM_CPU_REG0			0x1102B008
#define HPM_CPU_REG1			0x1102B00c
#define HPM_CORE_REG0			0x1102B018
#define HPM_CORE_REG1			0x1102B01c
#define CYCLE_NUM			32
#define SVB_RECORD_REG0			0x11020340
#define SVB_RECORD_REG1			0x11020344
#define VOLTAGE_RECOED_REG		0x1102015C
#define SVB_VERSION_REG			0x11020168
#define SVB_VERSION			0x101
#define OTP_HPM_CORE_REG		0x11021504
#define OTP_HPM_CPU_REG			0x11021530
#define OTP_VOLTAGE_DELTA_CORE_REG	0x1102150C
#define OTP_VOLTAGE_DELTA_CPU_REG	0x11021518
#define TSENSOR_STATUS0			0X1102A008
#ifdef DDR_SCRAMB_ENABLE
#endif
