#include <common.h>
#include <i2c.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr_dimm_params.h>
typedef struct board_memctl_options {
	uint16_t datarate_mhz_low;
	uint16_t datarate_mhz_high;
	uint8_t clk_adjust;
	uint8_t cpo_override;
	uint8_t write_data_delay;
} board_memctl_options_t;
