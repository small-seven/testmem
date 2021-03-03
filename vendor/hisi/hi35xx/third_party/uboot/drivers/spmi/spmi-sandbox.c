#include <common.h>
#include <dm.h>
#include <errno.h>
#include <spmi/spmi.h>
#include <asm/gpio.h>
#include <asm/io.h>
#define EMUL_GPIO_PID_START 0xC0
#define EMUL_GPIO_PID_END   0xC3
#define EMUL_GPIO_COUNT 4
#define EMUL_GPIO_REG_END 0x46 /* Last valid register */
#define EMUL_PERM_R 0x1
#define EMUL_PERM_W 0x2
#define EMUL_PERM_RW (EMUL_PERM_R | EMUL_PERM_W)
