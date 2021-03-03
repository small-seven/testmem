#include "asm/platform.h"
#include "los_hwi.h"
#include "los_tick_pri.h"
#define OS_CYCLE_PER_TICK (TIMER_FREQ / LOSCFG_BASE_CORE_TICK_PER_SECOND)
typedef struct {
    UINT32 load;        /* Private Timer Load Register */
    UINT32 count;       /* Private Timer Counter Register */
    UINT32 control;     /* Private Timer Control Register */
    UINT32 intStatus;   /* Private Timer Interrupt Status Register */
} PrivateTimer;
typedef struct {
    UINT32 low;         /* Global Timer Counter Registers, low bits */
    UINT32 high;        /* Global Timer Counter Registers, high bits */
    UINT32 control;     /* Global Timer Control Register */
    UINT32 intStatus;   /* Global Timer Interrupt Status Register */
    UINT32 compareLow;  /* Comparator Value Registers, low bits */
    UINT32 compareHigh; /* Comparator Value Registers, high bits */
    UINT32 increment;   /* Auto-increment Register */
} GlobalTimer;
