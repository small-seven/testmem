#include "amba_pl011.h"
#include "asm/platform.h"
#include "uart.h"
#include "los_hwi.h"
#include "los_spinlock.h"
#include "los_event.h"
#include "los_task_pri.h"
#define REG32(addr) ((volatile UINT32 *)(UINTPTR)(addr))
#define UARTREG(base, reg)  (*REG32((base) + (reg)))
#define UART_FR_TXFF (0x1U << 5)
