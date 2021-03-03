#include <common.h>
#include <asm/io.h>
#include <asm/i8254.h>
#define TIMER1_VALUE		18	/* 15.6us */
#define BEEP_FREQUENCY_HZ	440
#define SYSCTL_PORTB		0x61
#define PORTB_BEEP_ENABLE	0x3
