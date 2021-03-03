#include <common.h>
#include <spi.h>
#include <clk.h>
#include <dm.h>
#include <regmap.h>
#include <errno.h>
#include <asm/io.h>
#include <linux/bitfield.h>
#define REG_CMD			0x00
#define REG_ADDR		0x04
#define REG_CTRL		0x08
#define REG_CTRL1		0x0c
#define REG_STATUS		0x10
#define REG_CTRL2		0x14
#define REG_CLOCK		0x18
#define REG_USER		0x1c
#define REG_USER1		0x20
#define REG_USER2		0x24
#define REG_USER3		0x28
#define REG_USER4		0x2c
#define REG_SLAVE		0x30
#define REG_SLAVE1		0x34
#define REG_SLAVE2		0x38
#define REG_SLAVE3		0x3c
#define REG_C0			0x40
#define REG_B8			0x60
#define REG_MAX			0x7c
#define CMD_USER		BIT(18)
#define CTRL_ENABLE_AHB		BIT(17)
#define CLOCK_SOURCE		BIT(31)
#define CLOCK_DIV_SHIFT		12
#define CLOCK_DIV_MASK		(0x3f << CLOCK_DIV_SHIFT)
#define CLOCK_CNT_HIGH_SHIFT	6
#define CLOCK_CNT_HIGH_MASK	(0x3f << CLOCK_CNT_HIGH_SHIFT)
#define CLOCK_CNT_LOW_SHIFT	0
#define CLOCK_CNT_LOW_MASK	(0x3f << CLOCK_CNT_LOW_SHIFT)
#define USER_DIN_EN_MS		BIT(0)
#define USER_CMP_MODE		BIT(2)
#define USER_CLK_NOT_INV	BIT(7)
#define USER_UC_DOUT_SEL	BIT(27)
#define USER_UC_DIN_SEL		BIT(28)
#define USER_UC_MASK		((BIT(5) - 1) << 27)
#define USER1_BN_UC_DOUT_SHIFT	17
#define USER1_BN_UC_DOUT_MASK	(0xff << 16)
#define USER1_BN_UC_DIN_SHIFT	8
#define USER1_BN_UC_DIN_MASK	(0xff << 8)
#define USER4_CS_POL_HIGH	BIT(23)
#define USER4_IDLE_CLK_HIGH	BIT(29)
#define USER4_CS_ACT		BIT(30)
#define SLAVE_TRST_DONE		BIT(4)
#define SLAVE_OP_MODE		BIT(30)
#define SLAVE_SW_RST		BIT(31)
#define SPIFC_BUFFER_SIZE	64
