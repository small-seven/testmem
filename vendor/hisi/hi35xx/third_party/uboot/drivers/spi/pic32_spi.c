#include <common.h>
#include <clk.h>
#include <dm.h>
#include <linux/compat.h>
#include <malloc.h>
#include <spi.h>
#include <asm/types.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <dt-bindings/clock/microchip,clock.h>
#include <mach/pic32.h>
#define PIC32_SPI_CTRL_MSTEN	BIT(5) /* Enable SPI Master */
#define PIC32_SPI_CTRL_CKP	BIT(6) /* active low */
#define PIC32_SPI_CTRL_CKE	BIT(8) /* Tx on falling edge */
#define PIC32_SPI_CTRL_SMP	BIT(9) /* Rx at middle or end of tx */
#define PIC32_SPI_CTRL_BPW_MASK	0x03   /* Bits per word */
#define  PIC32_SPI_CTRL_BPW_8		0x0
#define  PIC32_SPI_CTRL_BPW_16		0x1
#define  PIC32_SPI_CTRL_BPW_32		0x2
#define PIC32_SPI_CTRL_BPW_SHIFT	10
#define PIC32_SPI_CTRL_ON	BIT(15) /* Macro enable */
#define PIC32_SPI_CTRL_ENHBUF	BIT(16) /* Enable enhanced buffering */
#define PIC32_SPI_CTRL_MCLKSEL	BIT(23) /* Select SPI Clock src */
#define PIC32_SPI_CTRL_MSSEN	BIT(28) /* SPI macro will drive SS */
#define PIC32_SPI_CTRL_FRMEN	BIT(31) /* Enable framing mode */
#define PIC32_SPI_STAT_RX_OV		BIT(6) /* err, s/w needs to clear */
#define PIC32_SPI_STAT_TF_LVL_MASK	0x1f
#define PIC32_SPI_STAT_TF_LVL_SHIFT	16
#define PIC32_SPI_STAT_RF_LVL_MASK	0x1f
#define PIC32_SPI_STAT_RF_LVL_SHIFT	24
#define PIC32_SPI_BAUD_MASK	0x1ff
#define BUILD_SPI_FIFO_RW(__name, __type, __bwl)		\
