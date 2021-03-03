#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <linux/libfdt.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <asm/armv8/mmu.h>
#define MVEBU_GPIO_NB_REG_BASE		(MVEBU_REGISTER(0x13800))
#define MVEBU_TEST_PIN_LATCH_N		(MVEBU_GPIO_NB_REG_BASE + 0x8)
#define MVEBU_XTAL_MODE_MASK		BIT(9)
#define MVEBU_XTAL_MODE_OFFS		9
#define MVEBU_XTAL_CLOCK_25MHZ		0x0
#define MVEBU_XTAL_CLOCK_40MHZ		0x1
#define MVEBU_NB_WARM_RST_REG		(MVEBU_GPIO_NB_REG_BASE + 0x40)
#define MVEBU_NB_WARM_RST_MAGIC_NUM	0x1d1e
