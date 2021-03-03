#include <common.h>
#include <env.h>
#include <w1.h>
#include <w1-eeprom.h>
#include <dm/device-internal.h>
#define AT91_PDA_EEPROM_ID_OFFSET		15
#define AT91_PDA_EEPROM_ID_LENGTH		5
#define AT91_PDA_EEPROM_DEFAULT_BUS		0
#if defined CONFIG_W1
#else
#endif
