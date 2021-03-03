#include <common.h>
#include <clk.h>
#include <malloc.h>
#include <spi.h>
#include <asm/io.h>
#include <dm.h>
#define MAX_TRANSFER_LEN	512
#define CHUNK_SIZE		1
#define SPI_TIMEOUT		0x100000
#define SPI0_BUS		0
#define SPI1_BUS		1
#define SPI0_BASE		0xf0b00000
#define SPI1_BASE		0xf0f00000
#define NSPI_MAX_CS_NUM		1
#define DATA_LENGTH(x)	((x-1)<<8)
#define TRAMODE_OFFSET	24
#define TRAMODE_MASK	(0x0F<<TRAMODE_OFFSET)
#define TRAMODE_WR_SYNC	(0<<TRAMODE_OFFSET)
#define TRAMODE_WO	(1<<TRAMODE_OFFSET)
#define TRAMODE_RO	(2<<TRAMODE_OFFSET)
#define TRAMODE_WR	(3<<TRAMODE_OFFSET)
#define TRAMODE_RW	(4<<TRAMODE_OFFSET)
#define TRAMODE_WDR	(5<<TRAMODE_OFFSET)
#define TRAMODE_RDW	(6<<TRAMODE_OFFSET)
#define TRAMODE_NONE	(7<<TRAMODE_OFFSET)
#define TRAMODE_DW	(8<<TRAMODE_OFFSET)
#define TRAMODE_DR	(9<<TRAMODE_OFFSET)
#define WCNT_OFFSET	12
#define WCNT_MASK	(0x1FF<<WCNT_OFFSET)
#define RCNT_OFFSET	0
#define RCNT_MASK	(0x1FF<<RCNT_OFFSET)
#define TXFTH_OFFSET	16
#define RXFTH_OFFSET	8
#define TXDMAEN		(1<<4)
#define RXDMAEN		(1<<3)
#define TXFRST		(1<<2)
#define RXFRST		(1<<1)
#define SPIRST		(1<<0)
#define TXFFL		(1<<23)
#define TXEPTY		(1<<22)
#define TXFVE_MASK	(0x1F<<16)
#define RXFEM		(1<<14)
#define RXFVE_OFFSET	(8)
#define RXFVE_MASK	(0x1F<<RXFVE_OFFSET)
#define SPIBSY		(1<<0)
#define SCLK_DIV_MASK	0xFF
