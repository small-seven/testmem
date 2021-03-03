#include <common.h>
#include <dm.h>
#include <fdt_support.h>
#include <asm/io.h>
#include <cpsw.h>
#define CTRL_MAC_REG(offset, id) ((offset) + 0x8 * (id))
