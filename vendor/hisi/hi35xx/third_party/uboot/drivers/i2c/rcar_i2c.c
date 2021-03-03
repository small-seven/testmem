#include <common.h>
#include <clk.h>
#include <dm.h>
#include <i2c.h>
#include <asm/io.h>
#include <wait_bit.h>
#define RCAR_I2C_ICSCR			0x00 /* slave ctrl */
#define RCAR_I2C_ICMCR			0x04 /* master ctrl */
#define RCAR_I2C_ICMCR_MDBS		BIT(7) /* non-fifo mode switch */
#define RCAR_I2C_ICMCR_FSCL		BIT(6) /* override SCL pin */
#define RCAR_I2C_ICMCR_FSDA		BIT(5) /* override SDA pin */
#define RCAR_I2C_ICMCR_OBPC		BIT(4) /* override pins */
#define RCAR_I2C_ICMCR_MIE		BIT(3) /* master if enable */
#define RCAR_I2C_ICMCR_TSBE		BIT(2)
#define RCAR_I2C_ICMCR_FSB		BIT(1) /* force stop bit */
#define RCAR_I2C_ICMCR_ESG		BIT(0) /* enable start bit gen */
#define RCAR_I2C_ICSSR			0x08 /* slave status */
#define RCAR_I2C_ICMSR			0x0c /* master status */
#define RCAR_I2C_ICMSR_MASK		0x7f
#define RCAR_I2C_ICMSR_MNR		BIT(6) /* Nack */
#define RCAR_I2C_ICMSR_MAL		BIT(5) /* Arbitration lost */
#define RCAR_I2C_ICMSR_MST		BIT(4) /* Stop */
#define RCAR_I2C_ICMSR_MDE		BIT(3)
#define RCAR_I2C_ICMSR_MDT		BIT(2)
#define RCAR_I2C_ICMSR_MDR		BIT(1)
#define RCAR_I2C_ICMSR_MAT		BIT(0)
#define RCAR_I2C_ICSIER			0x10 /* slave irq enable */
#define RCAR_I2C_ICMIER			0x14 /* master irq enable */
#define RCAR_I2C_ICCCR			0x18 /* clock dividers */
#define RCAR_I2C_ICCCR_SCGD_OFF		3
#define RCAR_I2C_ICSAR			0x1c /* slave address */
#define RCAR_I2C_ICMAR			0x20 /* master address */
#define RCAR_I2C_ICRXD_ICTXD		0x24 /* data port */
#define RCAR_I2C_ICFBSCR		0x38
#define RCAR_I2C_ICFBSCR_TCYC17		0x0f /* 17*Tcyc */
