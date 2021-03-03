#include <common.h>
#include <dm.h>
#include <smem.h>
#include <fdt_support.h>
#include <asm/arch/dram.h>
#define SMEM_USABLE_RAM_PARTITION_TABLE 402
#define RAM_PART_NAME_LENGTH            16
#define RAM_NUM_PART_ENTRIES            32
#define CATEGORY_SDRAM 0x0E
#define TYPE_SYSMEM 0x01
#ifndef MEMORY_BANKS_MAX
#define MEMORY_BANKS_MAX 4
#endif
