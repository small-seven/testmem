#include <common.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <netdev.h>
#include <i2c.h>
#define CS0BCR_D (0x06C00400)
#define CS4BCR_D (0x16c90400)
#define CS0WCR_D (0x55062C42)
#define CS4WCR_D (0x1e071dc3)
#define CMNCR_BROMMD0   (1 << 21)
#define CMNCR_BROMMD1   (1 << 22)
#define CMNCR_BROMMD	(CMNCR_BROMMD0|CMNCR_BROMMD1)
#define VCLKCR1_D	(0x27)
#define SMSTPCR1_CMT0	(1 << 24)
#define SMSTPCR1_I2C0	(1 << 16)
#define SMSTPCR3_USB	(1 << 22)
#define SMSTPCR3_I2C1	(1 << 23)
#define PORT32CR (0xE6051020)
#define PORT33CR (0xE6051021)
#define PORT34CR (0xE6051022)
#define PORT35CR (0xE6051023)
#ifdef CONFIG_SMC911X
#endif
