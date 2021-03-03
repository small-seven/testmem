#include <common.h>
#include <asm/io.h>
#include <asm/arch/platform.h>
#include <hifmc_common.h>
#include "hifmc_spi_ids.h"
#define REG_IO_BASE 0x1f002000
#define REG_NF_CSN  (REG_IO_BASE + 0x38)
#define REG_NF_REN  (REG_IO_BASE + 0x34)
#define REG_NF_WEN  (REG_IO_BASE + 0x40)
#define REG_NF_ALE  (REG_IO_BASE + 0x44)
#define REG_NF_CLE  (REG_IO_BASE + 0x3c)
#define REG_NF_RDY  (REG_IO_BASE + 0x48)
#define REG_SPI_CLK         (REG_IO_BASE + 0x34)
#define REG_SPI_MOSI_IO0    (REG_IO_BASE + 0x38)
#define REG_SPI_MISO_IO1    (REG_IO_BASE + 0x3C)
#define REG_SPI_WP_IO2      (REG_IO_BASE + 0x40)
#define REG_SPI_HOLD_IO3    (REG_IO_BASE + 0x44)
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif
#ifdef CONFIG_DTR_MODE_SUPPORT
#endif/* CONFIG_DTR_MODE_SUPPORT */
