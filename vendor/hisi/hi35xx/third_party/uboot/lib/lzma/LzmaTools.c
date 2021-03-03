#include <config.h>
#include <common.h>
#include <watchdog.h>
#ifdef CONFIG_LZMA
#define LZMA_PROPERTIES_OFFSET 0
#define LZMA_SIZE_OFFSET       LZMA_PROPS_SIZE
#define LZMA_DATA_OFFSET       LZMA_SIZE_OFFSET+sizeof(uint64_t)
#include "LzmaTools.h"
#include "LzmaDec.h"
#include <linux/string.h>
#include <malloc.h>
#endif
