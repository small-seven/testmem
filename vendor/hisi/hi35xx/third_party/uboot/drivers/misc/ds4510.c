#include <common.h>
#include <i2c.h>
#include <command.h>
#include "ds4510.h"
static int ds4510_mem_write(uint8_t chip, int offset, uint8_t *buf, int count)
{
	int wrlen;
	int i = 0;

	do {
		wrlen = DS4510_EEPROM_PAGE_SIZE -
			DS4510_EEPROM_PAGE_OFFSET(offset);
		if (count < wrlen)
			wrlen = count;
		if (i2c_write(chip, offset, 1, &buf[i], wrlen))
			return -1;

		/*
		 * This delay isn't needed for SRAM writes but shouldn't delay
		 * things too much, so do it unconditionally for simplicity
		 */
		udelay(DS4510_EEPROM_PAGE_WRITE_DELAY_MS * 1000);
		count -= wrlen;
		offset += wrlen;
		i += wrlen;
	} while (count > 0);

	return 0;
}
static int ds4510_mem_read(uint8_t chip, int offset, uint8_t *buf, int count)
{
	return i2c_read(chip, offset, 1, buf, count);
}
