#include <common.h>
#include <env.h>
#include <env_internal.h>
#include <init.h>
#include <led.h>
#include <net.h>
#include <spi.h>
#include <spi_flash.h>
#include <u-boot/crc.h>
#include <uuid.h>
#include <linux/ctype.h>
#include <linux/io.h>
#define MT76XX_AGPIO_CFG	0x1000003c
#define FACTORY_DATA_OFFS	0xc0000
#define FACTORY_DATA_SECT_SIZE	0x10000
#if ((CONFIG_ENV_OFFSET_REDUND + CONFIG_ENV_SIZE) > FACTORY_DATA_OFFS)
#error "U-Boot image with environment too big (overlapping with factory-data)!"
#endif
#define FACTORY_DATA_USER_OFFS	0x140
#define FACTORY_DATA_SIZE	0x1f0
#define FACTORY_DATA_CRC_LEN	(FACTORY_DATA_SIZE -			\
#define FACTORY_DATA_MAGIC	0xCAFEBABE
