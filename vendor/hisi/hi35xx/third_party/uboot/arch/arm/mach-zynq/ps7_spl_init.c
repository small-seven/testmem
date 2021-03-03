#include <asm/io.h>
#include <asm/spl.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/ps7_init_gpl.h>
#define SCU_GLOBAL_TIMER_COUNT_L32	0xF8F00200
#define SCU_GLOBAL_TIMER_COUNT_U32	0xF8F00204
#define SCU_GLOBAL_TIMER_CONTROL	0xF8F00208
#define SCU_GLOBAL_TIMER_AUTO_INC	0xF8F00218
#define APU_FREQ  666666666
#define PS7_MASK_POLL_TIME 100000000
