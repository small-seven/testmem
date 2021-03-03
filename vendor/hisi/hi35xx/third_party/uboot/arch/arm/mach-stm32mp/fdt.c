#include <common.h>
#include <fdt_support.h>
#include <asm/arch/sys_proto.h>
#include <dt-bindings/pinctrl/stm32-pinfunc.h>
#include <linux/io.h>
#define ETZPC_DECPROT(n)	(STM32_ETZPC_BASE + 0x10 + 4 * (n))
#define ETZPC_DECPROT_NB	6
#define DECPROT_MASK		0x03
#define NB_PROT_PER_REG		0x10
#define DECPROT_NB_BITS		2
#define DECPROT_SECURED		0x00
#define DECPROT_WRITE_SECURE	0x01
#define DECPROT_MCU_ISOLATION	0x02
#define DECPROT_NON_SECURED	0x03
#define ETZPC_RESERVED		0xffffffff
