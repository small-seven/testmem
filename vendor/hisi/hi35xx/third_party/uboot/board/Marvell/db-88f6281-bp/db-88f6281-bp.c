#include <common.h>
#include <linux/io.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <asm/arch/mpp.h>
#include <asm/arch/gpio.h>
#define DB_88F6281_OE_LOW	~(BIT(7))
#define DB_88F6281_OE_HIGH	~(BIT(15) | BIT(14) | BIT(13) | BIT(4))
#define DB_88F6281_OE_VAL_LOW	BIT(7)
#define DB_88F6281_OE_VAL_HIGH	0
#ifdef CONFIG_CMD_NAND
#else
#endif
#ifdef CONFIG_RESET_PHY_R
#endif
