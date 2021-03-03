#include <common.h>
#include <i2c.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr_dimm_params.h>
#ifdef CONFIG_SPD_EEPROM
#ifdef SPD_EEPROM_ADDRESS
#elif defined(SPD_EEPROM_ADDRESS1)
#endif
#endif
