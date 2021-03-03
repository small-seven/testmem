#include <linux/errno.h>
#include <common.h>
#include <i2c.h>
#include <linux/ctype.h>
#include "ventana_eeprom.h"
#include "gsc.h"
#if defined(CONFIG_CMD_GSC) && !defined(CONFIG_SPL_BUILD)
#endif /* CONFIG_CMD_GSC */
