#include <common.h>
#include <asm/io.h>
#include <asm/arch/ehci-rmobile.h>
#include "ehci.h"
#if defined(CONFIG_R8A7740)
#elif defined(CONFIG_R8A7790)
#elif defined(CONFIG_R8A7791) || defined(CONFIG_R8A7793) || \
#else
#error rmobile EHCI USB driver not supported on this platform
#endif
