#include <common.h>
#include <console.h>
#include <malloc.h>
#include <spi.h>
#include <wait_bit.h>
#include <asm/arch/rmobile.h>
#include <asm/io.h>
#define SPCR_MSTR	0x08
#define SPCR_SPE	0x40
#define SPSR_SPRFF	0x80
#define SPSR_SPTEF	0x20
#define SPPCR_IO3FV	0x04
#define SPPCR_IO2FV	0x02
#define SPPCR_IO1FV	0x01
#define SPBDCR_RXBC0	BIT(0)
#define SPCMD_SCKDEN	BIT(15)
#define SPCMD_SLNDEN	BIT(14)
#define SPCMD_SPNDEN	BIT(13)
#define SPCMD_SSLKP	BIT(7)
#define SPCMD_BRDV0	BIT(2)
#define SPCMD_INIT1	SPCMD_SCKDEN | SPCMD_SLNDEN | \
#define SPCMD_INIT2	SPCMD_SPNDEN | SPCMD_SSLKP | \
#define SPBFCR_TXRST	BIT(7)
#define SPBFCR_RXRST	BIT(6)
#define SPBFCR_TXTRG	0x30
#define SPBFCR_RXTRG	0x07
#ifndef CONFIG_DM_SPI
#endif
#ifndef CONFIG_DM_SPI
#else
#include <dm.h>
#endif
