#include <common.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <asm/arch/omap.h>
#include <malloc.h>
#include <spi.h>
#include <spi-mem.h>
#include <dm.h>
#include <asm/gpio.h>
#include <asm/omap_gpio.h>
#include <asm/omap_common.h>
#include <asm/ti-common/ti-edma3.h>
#include <linux/kernel.h>
#include <regmap.h>
#include <syscon.h>
#define QSPI_TIMEOUT                    2000000
#define QSPI_FCLK			192000000
#define QSPI_DRA7XX_FCLK                76800000
#define QSPI_WLEN_MAX_BITS		128
#define QSPI_WLEN_MAX_BYTES		(QSPI_WLEN_MAX_BITS >> 3)
#define QSPI_WLEN_MASK			QSPI_WLEN(QSPI_WLEN_MAX_BITS)
#define QSPI_CLK_EN                     BIT(31)
#define QSPI_CLK_DIV_MAX                0xffff
#define QSPI_EN_CS(n)                   (n << 28)
#define QSPI_WLEN(n)                    ((n-1) << 19)
#define QSPI_3_PIN                      BIT(18)
#define QSPI_RD_SNGL                    BIT(16)
#define QSPI_WR_SNGL                    (2 << 16)
#define QSPI_INVAL                      (4 << 16)
#define QSPI_RD_QUAD                    (7 << 16)
#define QSPI_CKPHA(n)                   (1 << (2 + n*8))
#define QSPI_CSPOL(n)                   (1 << (1 + n*8))
#define QSPI_CKPOL(n)                   (1 << (n*8))
#define QSPI_WC                         BIT(1)
#define QSPI_BUSY                       BIT(0)
#define QSPI_WC_BUSY                    (QSPI_WC | QSPI_BUSY)
#define QSPI_XFER_DONE                  QSPI_WC
#define MM_SWITCH                       0x01
#define MEM_CS(cs)                      ((cs + 1) << 8)
#define MEM_CS_UNSELECT                 0xfffff8ff
#define QSPI_SETUP0_READ_NORMAL         (0x0 << 12)
#define QSPI_SETUP0_READ_DUAL           (0x1 << 12)
#define QSPI_SETUP0_READ_QUAD           (0x3 << 12)
#define QSPI_SETUP0_ADDR_SHIFT		(8)
#define QSPI_SETUP0_DBITS_SHIFT		(10)
#if defined(CONFIG_TI_EDMA3) && !defined(CONFIG_DMA)
#else
#endif
#if CONFIG_IS_ENABLED(SYSCON)
#else
#endif
