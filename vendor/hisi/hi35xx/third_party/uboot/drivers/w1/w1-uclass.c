#include <common.h>
#include <dm.h>
#include <w1.h>
#include <w1-eeprom.h>
#include <dm/device-internal.h>
#define W1_MATCH_ROM	0x55
#define W1_SKIP_ROM	0xcc
#define W1_SEARCH	0xf0
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
