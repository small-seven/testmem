#include <common.h>
#include <i2c.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "ddr3_init.h"
#if defined(MV88F78X60)
#include "ddr3_axp_config.h"
#elif defined(MV88F67XX)
#include "ddr3_a370_config.h"
#endif
#if defined(MV88F672X)
#include "ddr3_a375_config.h"
#endif
#ifdef DUNIT_SPD
#define SPD_DEV_TYPE_BYTE		2
#define SPD_MODULE_TYPE_BYTE		3
#define SPD_MODULE_MASK			0xf
#define SPD_MODULE_TYPE_RDIMM		1
#define SPD_MODULE_TYPE_UDIMM		2
#define SPD_DEV_DENSITY_BYTE		4
#define SPD_DEV_DENSITY_MASK		0xf
#define SPD_ROW_NUM_BYTE		5
#define SPD_ROW_NUM_MIN			12
#define SPD_ROW_NUM_OFF			3
#define SPD_ROW_NUM_MASK		(7 << SPD_ROW_NUM_OFF)
#define SPD_COL_NUM_BYTE		5
#define SPD_COL_NUM_MIN			9
#define SPD_COL_NUM_OFF			0
#define SPD_COL_NUM_MASK		(7 << SPD_COL_NUM_OFF)
#define SPD_MODULE_ORG_BYTE		7
#define SPD_MODULE_SDRAM_DEV_WIDTH_OFF 	0
#define SPD_MODULE_SDRAM_DEV_WIDTH_MASK	(7 << SPD_MODULE_SDRAM_DEV_WIDTH_OFF)
#define SPD_MODULE_BANK_NUM_MIN		1
#define SPD_MODULE_BANK_NUM_OFF		3
#define SPD_MODULE_BANK_NUM_MASK	(7 << SPD_MODULE_BANK_NUM_OFF)
#define SPD_BUS_WIDTH_BYTE		8
#define SPD_BUS_WIDTH_OFF		0
#define SPD_BUS_WIDTH_MASK		(7 << SPD_BUS_WIDTH_OFF)
#define SPD_BUS_ECC_OFF			3
#define SPD_BUS_ECC_MASK		(3 << SPD_BUS_ECC_OFF)
#define SPD_MTB_DIVIDEND_BYTE		10
#define SPD_MTB_DIVISOR_BYTE		11
#define SPD_TCK_BYTE			12
#define SPD_SUP_CAS_LAT_LSB_BYTE	14
#define SPD_SUP_CAS_LAT_MSB_BYTE	15
#define SPD_TAA_BYTE			16
#define SPD_TWR_BYTE			17
#define SPD_TRCD_BYTE			18
#define SPD_TRRD_BYTE			19
#define SPD_TRP_BYTE			20
#define SPD_TRAS_MSB_BYTE		21
#define SPD_TRAS_MSB_MASK		0xf
#define SPD_TRC_MSB_BYTE		21
#define SPD_TRC_MSB_MASK		0xf0
#define SPD_TRAS_LSB_BYTE		22
#define SPD_TRC_LSB_BYTE		23
#define SPD_TRFC_LSB_BYTE		24
#define SPD_TRFC_MSB_BYTE		25
#define SPD_TWTR_BYTE			26
#define SPD_TRTP_BYTE			27
#define SPD_TFAW_MSB_BYTE		28
#define SPD_TFAW_MSB_MASK		0xf
#define SPD_TFAW_LSB_BYTE		29
#define SPD_OPT_FEATURES_BYTE		30
#define SPD_THERMAL_REFRESH_OPT_BYTE	31
#define SPD_ADDR_MAP_BYTE		63
#define SPD_ADDR_MAP_MIRROR_OFFS	0
#define SPD_RDIMM_RC_BYTE		69
#define SPD_RDIMM_RC_NIBBLE_MASK	0xF
#define SPD_RDIMM_RC_NUM		16
#define SPD_MEM_TYPE_SDRAM		0x4
#define SPD_MEM_TYPE_DDR1		0x7
#define SPD_MEM_TYPE_DDR2		0x8
#define SPD_MEM_TYPE_DDR3		0xB
#define DIMM_MODULE_MANU_OFFS		64
#define DIMM_MODULE_MANU_SIZE		8
#define DIMM_MODULE_VEN_OFFS		73
#define DIMM_MODULE_VEN_SIZE		25
#define DIMM_MODULE_ID_OFFS		99
#define DIMM_MODULE_ID_SIZE		18
typedef struct dimm_info {
	/* DIMM dimensions */
	u32 num_of_module_ranks;
	u32 data_width;
	u32 rank_capacity;
	u32 num_of_devices;

	u32 sdram_width;
	u32 num_of_banks_on_each_device;
	u32 sdram_capacity;

	u32 num_of_row_addr;
	u32 num_of_col_addr;

	u32 addr_mirroring;

	u32 err_check_type;			/* ECC , PARITY.. */
	u32 type_info;				/* DDR2 only */

	/* DIMM timing parameters */
	u32 supported_cas_latencies;
	u32 refresh_interval;
	u32 min_cycle_time;
	u32 min_row_precharge_time;
	u32 min_row_active_to_row_active;
	u32 min_ras_to_cas_delay;
	u32 min_write_recovery_time;		/* DDR3/2 only */
	u32 min_write_to_read_cmd_delay;	/* DDR3/2 only */
	u32 min_read_to_prech_cmd_delay;	/* DDR3/2 only */
	u32 min_active_to_precharge;
	u32 min_refresh_recovery;		/* DDR3/2 only */
	u32 min_cas_lat_time;
	u32 min_four_active_win_delay;
	u8 dimm_rc[SPD_RDIMM_RC_NUM];

	/* DIMM vendor ID */
	u32 vendor;
} MV_DIMM_INFO;
#if !(defined(DB_88F6710) || defined(DB_88F6710_PCAC) || defined(RD_88F6710))
#endif
#if defined(MV88F78X60) || defined(MV88F672X)
#endif
#if defined(DB_88F6710) || defined(DB_88F6710_PCAC) || defined(RD_88F6710)
#else
#ifdef DUNIT_SPD
#ifdef MIXED_DIMM_STATIC
#else
#endif
#endif
#endif
#ifdef DUNIT_STATIC
#endif
#ifdef DUNIT_SPD
#endif
#ifdef DUNIT_STATIC
#endif
#ifdef DUNIT_SPD
#endif
#ifdef DUNIT_STATIC
#else
#endif
#ifdef DUNIT_STATIC
#endif
#ifndef MV88F67XX
#ifdef DUNIT_STATIC
#else
#endif
#else
#endif
#if defined(MV88F672X)
#endif
#ifdef TREFI_USER_EN
#endif
#if defined(MV88F672X)
#endif
#ifdef DUNIT_SPD
#endif
#if (defined(MV88F78X60) || defined(MV88F672X))
#else
#endif
#ifdef DUNIT_STATIC
#endif
#ifdef DUNIT_SPD
#endif
#if (defined(MV88F78X60) || defined(MV88F672X))
#else
#endif
#if defined(MV88F78X60) || defined(MV88F672X)
#endif
#ifdef MV88F67XX
#endif
#if defined(MV88F672X)
#endif
#if (defined(MV88F78X60) || defined(MV88F672X))
#endif
#if defined(MV88F672X)
#endif
#ifdef DUNIT_SPD
#endif
#ifdef DUNIT_SPD
#endif
#if defined(MV88F78X60)
#else
#if defined(MV88F672X)
#endif
#endif
#if (defined(MV88F78X60) || defined(MV88F672X))
#endif
#ifdef DUNIT_STATIC
#else
#endif
#ifdef DUNIT_STATIC
#else
#endif
#endif
