#include <common.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#define RZA1_WDT_BASE	0xfcfe0000
#define WTCSR		0x00
#define WTCNT		0x02
#define WRCSR		0x04
