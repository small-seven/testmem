#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <spi.h>
#include <clk.h>
#include <wait_bit.h>
#include <asm/io.h>
#define MVEBU_SPI_A3700_XFER_RDY		BIT(1)
#define MVEBU_SPI_A3700_FIFO_FLUSH		BIT(9)
#define MVEBU_SPI_A3700_BYTE_LEN		BIT(5)
#define MVEBU_SPI_A3700_CLK_PHA			BIT(6)
#define MVEBU_SPI_A3700_CLK_POL			BIT(7)
#define MVEBU_SPI_A3700_FIFO_EN			BIT(17)
#define MVEBU_SPI_A3700_SPI_EN_0		BIT(16)
#define MVEBU_SPI_A3700_CLK_PRESCALE_MASK	0x1f
static int mvebu_spi_remove(struct udevice *bus)
{
	struct mvebu_spi_platdata *plat = dev_get_platdata(bus);

	clk_free(&plat->clk);

	return 0;
}
