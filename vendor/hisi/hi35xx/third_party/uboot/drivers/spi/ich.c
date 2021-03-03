#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <pch.h>
#include <pci.h>
#include <pci_ids.h>
#include <spi.h>
#include <asm/io.h>
#include <spi-mem.h>
#include <div64.h>
#include "ich.h"
#ifdef DEBUG_TRACE
#define debug_trace(fmt, args...) debug(fmt, ##args)
#else
#define debug_trace(x, args...)
#endif
static int ich_spi_remove(struct udevice *bus)
{
	/*
	 * Configure SPI controller so that the Linux MTD driver can fully
	 * access the SPI NOR chip
	 */
	ich_spi_config_opcode(bus);

	return 0;
}
