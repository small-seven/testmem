#include <common.h>
#include <asm/sections.h>
#include <asm/io.h>
#include <asm/reboot.h>
#if defined(CONFIG_SOC_JR2) || defined(CONFIG_SOC_SERVALT)
#elif defined(CONFIG_SOC_SERVAL)
#else		/* Luton || Ocelot */
#endif
