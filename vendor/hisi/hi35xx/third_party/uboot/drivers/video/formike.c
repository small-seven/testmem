#include <common.h>
#include <errno.h>
#include <spi.h>
#define TAG_READ	0x80
#define TAG_WRITE	0x00
#define TAG_DATA	0x40
#define TAG_COMMAND	0x00
#define TAG_ADDR_H	0x20
#define TAG_ADDR_L	0x00
#ifdef KWH043ST20_F01_SPI_DEBUG
#endif /* KWH043ST20_F01_SPI_DEBUG */
