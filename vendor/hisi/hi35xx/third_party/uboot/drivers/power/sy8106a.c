#include <common.h>
#include <i2c.h>
#include <sy8106a.h>
#define SY8106A_I2C_ADDR 0x65
#define SY8106A_VOUT1_SEL 1
#define SY8106A_VOUT1_SEL_ENABLE (1 << 7)
#ifdef CONFIG_SPL_BUILD
#endif
