#include <common.h>
#include <asm/io.h>
#include <asm/arch/sysmap.h>
#define GPIO_BASE				(void *)GPIO2_BASE_ADDR
#define GPIO_PASSWD				0x00a5a501
#define GPIO_PER_BANK				32
#define GPIO_MAX_BANK_NUM			8
#define GPIO_BANK(gpio)				((gpio) >> 5)
#define GPIO_BITMASK(gpio)	\
#define GPIO_OUT_STATUS(bank)			(0x00000000 + ((bank) << 2))
#define GPIO_IN_STATUS(bank)			(0x00000020 + ((bank) << 2))
#define GPIO_OUT_SET(bank)			(0x00000040 + ((bank) << 2))
#define GPIO_OUT_CLEAR(bank)			(0x00000060 + ((bank) << 2))
#define GPIO_INT_STATUS(bank)			(0x00000080 + ((bank) << 2))
#define GPIO_INT_MASK(bank)			(0x000000a0 + ((bank) << 2))
#define GPIO_INT_MSKCLR(bank)			(0x000000c0 + ((bank) << 2))
#define GPIO_CONTROL(bank)			(0x00000100 + ((bank) << 2))
#define GPIO_PWD_STATUS(bank)			(0x00000500 + ((bank) << 2))
#define GPIO_GPPWR_OFFSET			0x00000520
#define GPIO_GPCTR0_DBR_SHIFT			5
#define GPIO_GPCTR0_DBR_MASK			0x000001e0
#define GPIO_GPCTR0_ITR_SHIFT			3
#define GPIO_GPCTR0_ITR_MASK			0x00000018
#define GPIO_GPCTR0_ITR_CMD_RISING_EDGE		0x00000001
#define GPIO_GPCTR0_ITR_CMD_FALLING_EDGE	0x00000002
#define GPIO_GPCTR0_ITR_CMD_BOTH_EDGE		0x00000003
#define GPIO_GPCTR0_IOTR_MASK			0x00000001
#define GPIO_GPCTR0_IOTR_CMD_0UTPUT		0x00000000
#define GPIO_GPCTR0_IOTR_CMD_INPUT		0x00000001
int gpio_free(unsigned gpio)
{
	unsigned int value, off;

	writel(GPIO_PASSWD, GPIO_BASE + GPIO_GPPWR_OFFSET);
	off = GPIO_PWD_STATUS(GPIO_BANK(gpio));
	value = readl(GPIO_BASE + off) | GPIO_BITMASK(gpio);
	writel(value, GPIO_BASE + off);

	return 0;
}
