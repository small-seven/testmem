#include <common.h>
#include <spi.h>
#include <power/pmic.h>
#include <fsl_pmic.h>
#include <errno.h>
#if defined(CONFIG_POWER_FSL_MC13892)
#define FSL_PMIC_I2C_LENGTH	3
#elif defined(CONFIG_POWER_FSL_MC34704)
#define FSL_PMIC_I2C_LENGTH	1
#endif
#if defined(CONFIG_POWER_SPI)
#endif
#if defined(CONFIG_POWER_SPI)
#elif defined(CONFIG_POWER_I2C)
#else
#error "You must select CONFIG_POWER_SPI or CONFIG_POWER_I2C"
#endif
