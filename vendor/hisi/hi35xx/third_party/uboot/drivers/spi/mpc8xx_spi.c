#include <common.h>
#include <dm.h>
#include <mpc8xx.h>
#include <spi.h>
#include <asm/cpm_8xx.h>
#include <asm/io.h>
#define CPM_SPI_BASE_RX	CPM_SPI_BASE
#define CPM_SPI_BASE_TX	(CPM_SPI_BASE + sizeof(cbd_t))
#define MAX_BUFFER	0x104
