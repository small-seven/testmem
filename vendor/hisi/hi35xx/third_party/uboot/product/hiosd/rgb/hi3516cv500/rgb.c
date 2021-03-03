#include "rgb.h"
#include <common.h>
#define IO_ADDRESS(x) (x)
#define SSP_BASE 0x120c1000
#define SSP_SIZE 0x1000
#define DEFAULT_MD_LEN 128
#define SSP_CR0   IO_ADDRESS(SSP_BASE + 0x00)
#define SSP_CR1   IO_ADDRESS(SSP_BASE + 0x04)
#define SSP_DR    IO_ADDRESS(SSP_BASE + 0x08)
#define SSP_SR    IO_ADDRESS(SSP_BASE + 0x0C)
#define SSP_CPSR  IO_ADDRESS(SSP_BASE + 0x10)
#define SSP_IMSC  IO_ADDRESS(SSP_BASE + 0x14)
#define SSP_RIS   IO_ADDRESS(SSP_BASE + 0x18)
#define SSP_MIS   IO_ADDRESS(SSP_BASE + 0x1C)
#define SSP_ICR   IO_ADDRESS(SSP_BASE + 0x20)
#define SSP_DMACR IO_ADDRESS(SSP_BASE + 0x24)
#define SPI_SR_BSY     (0x1 << 4) /* spi busy flag */
#define SPI_SR_TFE     (0x1 << 0) /* Whether to send fifo is empty */
#define SPI_DATA_WIDTH 9
#define SPI_SPO        1
#define SPI_SPH        1
#define SPI_SCR        8
#define SPI_CPSDVSR    8
#define SPI_FRAMEMODE  0
#define MAX_WAIT 10000
#define ssp_readw(addr, ret)    ((ret) = (*(volatile unsigned int *)(addr)))
#define ssp_writew(addr, value) ((*(volatile unsigned int *)(addr)) = (value))
#if CONFIG_RGB_INTFACE
#endif
#if CONFIG_RGB_INTFACE
#endif
#if CONFIG_RGB_INTFACE
#endif
