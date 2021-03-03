#include <common.h>
#include <command.h>
#include <console.h>
#include <g_dnl.h>
#include <fastboot.h>
#include <net.h>
#include <usb.h>
#include <watchdog.h>
#if CONFIG_IS_ENABLED(UDP_FUNCTION_FASTBOOT)
#else
#endif
#if CONFIG_IS_ENABLED(USB_FUNCTION_FASTBOOT)
#else
#endif
#ifdef CONFIG_SYS_LONGHELP
#endif
