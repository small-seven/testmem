#include <common.h>
#include <dm.h>
#include <linux/err.h>
#include <w1-eeprom.h>
#include <w1.h>
#define DS2502_PAGE_SIZE	32
#define DS2502_PAGE_COUNT	4
#define DS2502_STATUS_SIZE	8
#define DS2502_CMD_READ_STATUS	0xAA
#define DS2502_CMD_READ_GEN_CRC	0xC3
