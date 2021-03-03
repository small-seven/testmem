#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <spi.h>
#include <asm/io.h>
#include <linux/log2.h>
#include <clk.h>
#define SIFIVE_SPI_MAX_CS		32
#define SIFIVE_SPI_DEFAULT_DEPTH	8
#define SIFIVE_SPI_DEFAULT_BITS		8
#define SIFIVE_SPI_REG_SCKDIV            0x00 /* Serial clock divisor */
#define SIFIVE_SPI_REG_SCKMODE           0x04 /* Serial clock mode */
#define SIFIVE_SPI_REG_CSID              0x10 /* Chip select ID */
#define SIFIVE_SPI_REG_CSDEF             0x14 /* Chip select default */
#define SIFIVE_SPI_REG_CSMODE            0x18 /* Chip select mode */
#define SIFIVE_SPI_REG_DELAY0            0x28 /* Delay control 0 */
#define SIFIVE_SPI_REG_DELAY1            0x2c /* Delay control 1 */
#define SIFIVE_SPI_REG_FMT               0x40 /* Frame format */
#define SIFIVE_SPI_REG_TXDATA            0x48 /* Tx FIFO data */
#define SIFIVE_SPI_REG_RXDATA            0x4c /* Rx FIFO data */
#define SIFIVE_SPI_REG_TXMARK            0x50 /* Tx FIFO watermark */
#define SIFIVE_SPI_REG_RXMARK            0x54 /* Rx FIFO watermark */
#define SIFIVE_SPI_REG_FCTRL             0x60 /* SPI flash interface control */
#define SIFIVE_SPI_REG_FFMT              0x64 /* SPI flash instruction format */
#define SIFIVE_SPI_REG_IE                0x70 /* Interrupt Enable Register */
#define SIFIVE_SPI_REG_IP                0x74 /* Interrupt Pendings Register */
#define SIFIVE_SPI_SCKDIV_DIV_MASK       0xfffU
#define SIFIVE_SPI_SCKMODE_PHA           BIT(0)
#define SIFIVE_SPI_SCKMODE_POL           BIT(1)
#define SIFIVE_SPI_SCKMODE_MODE_MASK     (SIFIVE_SPI_SCKMODE_PHA | \
#define SIFIVE_SPI_CSMODE_MODE_AUTO      0U
#define SIFIVE_SPI_CSMODE_MODE_HOLD      2U
#define SIFIVE_SPI_CSMODE_MODE_OFF       3U
#define SIFIVE_SPI_DELAY0_CSSCK(x)       ((u32)(x))
#define SIFIVE_SPI_DELAY0_CSSCK_MASK     0xffU
#define SIFIVE_SPI_DELAY0_SCKCS(x)       ((u32)(x) << 16)
#define SIFIVE_SPI_DELAY0_SCKCS_MASK     (0xffU << 16)
#define SIFIVE_SPI_DELAY1_INTERCS(x)     ((u32)(x))
#define SIFIVE_SPI_DELAY1_INTERCS_MASK   0xffU
#define SIFIVE_SPI_DELAY1_INTERXFR(x)    ((u32)(x) << 16)
#define SIFIVE_SPI_DELAY1_INTERXFR_MASK  (0xffU << 16)
#define SIFIVE_SPI_FMT_PROTO_SINGLE      0U
#define SIFIVE_SPI_FMT_PROTO_DUAL        1U
#define SIFIVE_SPI_FMT_PROTO_QUAD        2U
#define SIFIVE_SPI_FMT_PROTO_MASK        3U
#define SIFIVE_SPI_FMT_ENDIAN            BIT(2)
#define SIFIVE_SPI_FMT_DIR               BIT(3)
#define SIFIVE_SPI_FMT_LEN(x)            ((u32)(x) << 16)
#define SIFIVE_SPI_FMT_LEN_MASK          (0xfU << 16)
#define SIFIVE_SPI_TXDATA_DATA_MASK      0xffU
#define SIFIVE_SPI_TXDATA_FULL           BIT(31)
#define SIFIVE_SPI_RXDATA_DATA_MASK      0xffU
#define SIFIVE_SPI_RXDATA_EMPTY          BIT(31)
#define SIFIVE_SPI_IP_TXWM               BIT(0)
#define SIFIVE_SPI_IP_RXWM               BIT(1)
