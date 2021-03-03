#include <common.h>
#include <errno.h>
#include <hexdump.h>
#include <i2c.h>
#include <malloc.h>
#include <asm/bitops.h>
#include "gsc.h"
#include "ventana_eeprom.h"
#if defined(CONFIG_CMD_EECONFIG) && !defined(CONFIG_SPL_BUILD)
#endif /* CONFIG_CMD_EECONFIG */
