#include <common.h>
#include <miiphy.h>
#include <asm/setup.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <asm/arch/mpp.h>
#include "ds109.h"
#include <ns16550.h>
#define SOFTWARE_SHUTDOWN   0x31
#define SOFTWARE_REBOOT     0x43
#define CONFIG_SYS_NS16550_COM2		KW_UART1_BASE
#ifdef CONFIG_RESET_PHY_R
#endif /* CONFIG_RESET_PHY_R */
