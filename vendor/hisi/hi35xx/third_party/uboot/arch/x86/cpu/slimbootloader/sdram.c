#include <common.h>
#include <init.h>
#include <linux/sizes.h>
#include <asm/e820.h>
#include <asm/arch/slimbootloader.h>
#define for_each_if(condition) if (!(condition)) {} else
#define for_each_memory_map_entry_reversed(iter, entries) \
