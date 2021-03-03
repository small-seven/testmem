#include <common.h>
#include <i2c.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr_dimm_params.h>
typedef struct {
	unsigned short datarate_mhz_low;
	unsigned short datarate_mhz_high;
	unsigned char clk_adjust;
	unsigned char cpo;
} board_specific_parameters_t;
