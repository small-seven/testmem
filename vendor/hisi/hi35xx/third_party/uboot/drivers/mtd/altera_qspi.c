#include <common.h>
#include <console.h>
#include <dm.h>
#include <errno.h>
#include <fdt_support.h>
#include <flash.h>
#include <mtd.h>
#include <asm/io.h>
#define QUADSPI_SR_BP0				BIT(2)
#define QUADSPI_SR_BP1				BIT(3)
#define QUADSPI_SR_BP2				BIT(4)
#define QUADSPI_SR_BP2_0			GENMASK(4, 2)
#define QUADSPI_SR_BP3				BIT(6)
#define QUADSPI_SR_TB				BIT(5)
#define QUADSPI_MEM_OP_BULK_ERASE		0x00000001
#define QUADSPI_MEM_OP_SECTOR_ERASE		0x00000002
#define QUADSPI_MEM_OP_SECTOR_PROTECT		0x00000003
#define QUADSPI_ISR_ILLEGAL_ERASE		BIT(0)
#define QUADSPI_ISR_ILLEGAL_WRITE		BIT(1)
