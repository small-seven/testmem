#include <common.h>
#include <init.h>
#include <malloc.h>
#include <asm/processor.h>
#include <asm/mach-types.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/arch/rmobile.h>
#define s_init_wait(cnt) \
#define USBCR1 0xE605810A
#define GPIO_ICCR (0xE60581A0)
#define ICCR_15BIT (1 << 15) /* any time 1 */
#define IIC0_CONTA (1 << 7)
#define IIC0_CONTB (1 << 6)
#define IIC1_CONTA (1 << 5)
#define IIC1_CONTB (1 << 4)
#define IIC0_PS33E (1 << 1)
#define IIC1_PS33E (1 << 0)
#define GPIO_ICCR_DATA	\
#define MSTPCR1         0xE6150134
#define TMU0_MSTP125    (1 << 25)
#define I2C0_MSTP116    (1 << 16)
#define MSTPCR3         0xE615013C
#define I2C1_MSTP323    (1 << 23)
#define GETHER_MSTP309	(1 << 9)
#define GPIO_SCIFA1_TXD (0xE60520C4)
#define GPIO_SCIFA1_RXD (0xE60520C3)
