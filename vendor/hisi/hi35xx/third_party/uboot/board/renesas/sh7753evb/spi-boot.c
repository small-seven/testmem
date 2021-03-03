#include <common.h>
#define CONFIG_SPI_ADDR		0x00000000
#define PHYADDR(_addr)		((_addr & 0x1fffffff) | 0x40000000)
#define CONFIG_RAM_BOOT_PHYS	PHYADDR(CONFIG_SYS_TEXT_BASE)
#define SPIWDMADR	0xFE001018
#define SPIWDMCNTR	0xFE001020
#define SPIDMCOR	0xFE001028
#define SPIDMINTSR	0xFE001188
#define SPIDMINTMR	0xFE001190
#define SPIDMINTSR_DMEND	0x00000004
#define TBR	0xFE002000
#define RBR	0xFE002000
#define CR1	0xFE002008
#define CR2	0xFE002010
#define CR3	0xFE002018
#define CR4	0xFE002020
#define CR7	0xFE002038
#define CR8	0xFE002040
#define SPI_TBE		0x80
#define SPI_TBF		0x40
#define SPI_RBE		0x20
#define SPI_RBF		0x10
#define SPI_PFONRD	0x08
#define SPI_SSDB	0x04
#define SPI_SSD		0x02
#define SPI_SSA		0x01
#define SPI_RSTF	0x80
#define SPI_LOOPBK	0x40
#define SPI_CPOL	0x20
#define SPI_CPHA	0x10
#define SPI_L1M0	0x08
#define SPI_TBEI	0x80
#define SPI_TBFI	0x40
#define SPI_RBEI	0x20
#define SPI_RBFI	0x10
#define SPI_SpiS0	0x02
#define SPI_SSS		0x01
#define CR7_IDX_OR12	0x12
#define OR12_ADDR32	0x00000001
#define spi_write(val, addr)	(*(volatile unsigned long *)(addr)) = val
#define spi_read(addr)		(*(volatile unsigned long *)(addr))
#define M25_READ	0x03
#define M25_READ_4BYTE	0x13
#define __uses_spiboot2	__attribute__((section(".spiboot2.text")))
