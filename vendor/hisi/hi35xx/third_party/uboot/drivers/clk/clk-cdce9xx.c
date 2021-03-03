#include <common.h>
#include <dm.h>
#include <errno.h>
#include <clk-uclass.h>
#include <i2c.h>
#define MAX_NUMBER_OF_PLLS		4
#define MAX_NUMER_OF_OUTPUTS		9
#define CDCE9XX_REG_GLOBAL1		0x01
#define CDCE9XX_REG_Y1SPIPDIVH		0x02
#define CDCE9XX_REG_PDIV1L		0x03
#define CDCE9XX_REG_XCSEL		0x05
#define CDCE9XX_PDIV1_H_MASK		0x3
#define CDCE9XX_REG_PDIV(clk)		(0x16 + (((clk) - 1) & 1) + \
#define CDCE9XX_PDIV_MASK		0x7f
#define CDCE9XX_BYTE_TRANSFER		BIT(7)
