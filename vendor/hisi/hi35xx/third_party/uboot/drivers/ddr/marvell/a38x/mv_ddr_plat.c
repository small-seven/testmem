#include "ddr3_init.h"
#include "mv_ddr_training_db.h"
#include "mv_ddr_regs.h"
#include "mv_ddr_sys_env_lib.h"
#define DDR_INTERFACES_NUM		1
#define DDR_INTERFACE_OCTETS_NUM	5
#define L2_FILTER_FOR_MAX_MEMORY_SIZE	0xC0000000 /* temporary limit l2 filter to 3gb (LSP issue) */
#define ADDRESS_FILTERING_END_REGISTER	0x8c04
#define DYNAMIC_CS_SIZE_CONFIG
#define DISABLE_L2_FILTERING_DURING_DDR_TRAINING
#define TSEN_CONTROL_LSB_REG		0xE4070
#define TSEN_CONTROL_LSB_TC_TRIM_OFFSET	0
#define TSEN_CONTROL_LSB_TC_TRIM_MASK	(0x7 << TSEN_CONTROL_LSB_TC_TRIM_OFFSET)
#define TSEN_CONTROL_MSB_REG		0xE4074
#define TSEN_CONTROL_MSB_RST_OFFSET	8
#define TSEN_CONTROL_MSB_RST_MASK	(0x1 << TSEN_CONTROL_MSB_RST_OFFSET)
#define TSEN_STATUS_REG			0xe4078
#define TSEN_STATUS_READOUT_VALID_OFFSET	10
#define TSEN_STATUS_READOUT_VALID_MASK	(0x1 <<				\
#define TSEN_STATUS_TEMP_OUT_OFFSET	0
#define TSEN_STATUS_TEMP_OUT_MASK	(0x3ff << TSEN_STATUS_TEMP_OUT_OFFSET)
#define ODPG_ENABLE_REG				0x186d4
#define ODPG_EN_OFFS				0
#define ODPG_EN_MASK				0x1
#define ODPG_EN_ENA				1
#define ODPG_EN_DONE				0
#define ODPG_DIS_OFFS				8
#define ODPG_DIS_MASK				0x1
#define ODPG_DIS_DIS				1
#define DRAM_INIT_CTRL_STATUS_REG	0x18488
#define TRAINING_TRIGGER_OFFS		0
#define TRAINING_TRIGGER_MASK		0x1
#define TRAINING_TRIGGER_ENA		1
#define TRAINING_DONE_OFFS		1
#define TRAINING_DONE_MASK		0x1
#define TRAINING_DONE_DONE		1
#define TRAINING_DONE_NOT_DONE		0
#define TRAINING_RESULT_OFFS		2
#define TRAINING_RESULT_MASK		0x1
#define TRAINING_RESULT_PASS		0
#define TRAINING_RESULT_FAIL		1
#define DM_PAD	10
#if defined(CONFIG_ARMADA_39X)
#else
#endif
#ifdef CONFIG_ARMADA_39X
#else
#endif
#ifdef DEVICE_MAX_DRAM_ADDRESS_SIZE
#endif
#ifdef DEVICE_MAX_DRAM_ADDRESS_SIZE
#endif
#if defined DYNAMIC_CS_SIZE_CONFIG
#else
#endif
#ifdef DISABLE_L2_FILTERING_DURING_DDR_TRAINING
#endif