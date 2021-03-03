#include <common.h>
#include <malloc.h>
#include <spi.h>
#include <asm/immap_85xx.h>
#define to_fsl_spi_slave(s) container_of(s, struct fsl_spi_slave, slave)
#define US_PER_SECOND		1000000UL
#define ESPI_MAX_CS_NUM		4
#define ESPI_FIFO_WIDTH_BIT	32
#define ESPI_EV_RNE		BIT(9)
#define ESPI_EV_TNF		BIT(8)
#define ESPI_EV_DON		BIT(14)
#define ESPI_EV_TXE		BIT(15)
#define ESPI_EV_RFCNT_SHIFT	24
#define ESPI_EV_RFCNT_MASK	(0x3f << ESPI_EV_RFCNT_SHIFT)
#define ESPI_MODE_EN		BIT(31)	/* Enable interface */
#define ESPI_MODE_TXTHR(x)	((x) << 8)	/* Tx FIFO threshold */
#define ESPI_MODE_RXTHR(x)	((x) << 0)	/* Rx FIFO threshold */
#define ESPI_COM_CS(x)		((x) << 30)
#define ESPI_COM_TRANLEN(x)	((x) << 0)
#define ESPI_CSMODE_CI_INACTIVEHIGH	BIT(31)
#define ESPI_CSMODE_CP_BEGIN_EDGCLK	BIT(30)
#define ESPI_CSMODE_REV_MSB_FIRST	BIT(29)
#define ESPI_CSMODE_DIV16		BIT(28)
#define ESPI_CSMODE_PM(x)		((x) << 24)
#define ESPI_CSMODE_POL_ASSERTED_LOW	BIT(20)
#define ESPI_CSMODE_LEN(x)		((x) << 16)
#define ESPI_CSMODE_CSBEF(x)		((x) << 12)
#define ESPI_CSMODE_CSAFT(x)		((x) << 8)
#define ESPI_CSMODE_CSCG(x)		((x) << 3)
#define ESPI_CSMODE_INIT_VAL (ESPI_CSMODE_POL_ASSERTED_LOW | \
#define ESPI_MAX_DATA_TRANSFER_LEN 0xFFF0
