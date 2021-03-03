#include <common.h>
#include <serial.h>
#include <asm/io.h>
#include <env.h>
#include <usbdevice.h>
#include "ep0.h"
#include <usb/designware_udc.h>
#include <usb/udc.h>
#include <asm/arch/hardware.h>
#define UDC_INIT_MDELAY		80	/* Device settle delay */
#ifndef DEBUG_DWUSBTTY
#define UDCDBG(str)
#define UDCDBGA(fmt, args...)
#else
#define UDCDBG(str) serial_printf(str "\n")
#define UDCDBGA(fmt, args...) serial_printf(fmt "\n", ##args)
#endif
#ifndef CONFIG_USBD_HS
#else
#endif
