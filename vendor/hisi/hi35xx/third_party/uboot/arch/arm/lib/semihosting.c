#include <common.h>
#include <command.h>
#define SYSOPEN		0x01
#define SYSCLOSE	0x02
#define SYSREAD		0x06
#define SYSFLEN		0x0C
#define MODE_READ	0x0
#define MODE_READBIN	0x1
#if defined(CONFIG_ARM64)
#elif defined(CONFIG_CPU_V7M)
#else
#endif
