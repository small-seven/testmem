#include <common.h>
#include <console.h>
#include "e1000.h"
#include <linux/compiler.h>
#ifdef CONFIG_E1000_SPI_GENERIC
#endif /* not CONFIG_E1000_SPI_GENERIC */
#ifdef CONFIG_CMD_E1000
#define SPI_EEPROM_ENABLE_WR	0x06
#define SPI_EEPROM_DISABLE_WR	0x04
#define SPI_EEPROM_WRITE_STATUS	0x01
#define SPI_EEPROM_READ_STATUS	0x05
#define SPI_EEPROM_WRITE_PAGE	0x02
#define SPI_EEPROM_READ_PAGE	0x03
#define SPI_EEPROM_STATUS_BUSY	0x01
#define SPI_EEPROM_STATUS_WREN	0x02
#endif /* not CONFIG_CMD_E1000 */
