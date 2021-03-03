#include <common.h>
#include <asm/io.h>
#include <usb/ulpi.h>
#define ULPI_SS		(1 << 27)
#define ULPI_RWCTRL	(1 << 29)
#define ULPI_RWRUN	(1 << 30)
#define ULPI_WU		(1 << 31)
