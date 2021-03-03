#include <common.h>
#include <exports.h>
#include "../drivers/net/smc91111.h"
#ifndef SMC91111_EEPROM_INIT
# define SMC91111_EEPROM_INIT()
#endif
#define SMC_BASE_ADDRESS CONFIG_SMC91111_BASE
#define EEPROM		0x1
#define MAC		0x2
#define UNKNOWN		0x4
