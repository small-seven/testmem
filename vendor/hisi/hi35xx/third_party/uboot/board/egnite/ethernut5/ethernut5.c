#include <common.h>
#include <net.h>
#include <netdev.h>
#include <miiphy.h>
#include <i2c.h>
#include <mmc.h>
#include <atmel_mci.h>
#include <asm/arch/at91sam9260.h>
#include <asm/arch/at91sam9260_matrix.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include "ethernut5_pwrman.h"
#ifdef CONFIG_CMD_NAND
#ifdef CONFIG_SYS_NAND_READY_PIN
#endif
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_GENERIC_ATMEL_MCI
#endif
