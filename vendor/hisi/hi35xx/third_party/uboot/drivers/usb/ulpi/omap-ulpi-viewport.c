#include <common.h>
#include <asm/io.h>
#include <usb/ulpi.h>
#define OMAP_ULPI_WR_OPSEL	(2 << 22)
#define OMAP_ULPI_RD_OPSEL	(3 << 22)
#define OMAP_ULPI_START		(1 << 31)
