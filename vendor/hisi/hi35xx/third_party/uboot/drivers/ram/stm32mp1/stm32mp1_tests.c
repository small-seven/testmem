#include <common.h>
#include <console.h>
#include <watchdog.h>
#include <asm/io.h>
#include <linux/log2.h>
#include "stm32mp1_tests.h"
#define ADDR_INVALID	0xFFFFFFFF
#define CHUNK_SIZE	0x8000000
#define PATTERN_SIZE	8
#define NB_PATTERN	5
#define NB_TEST_INFINITE 2
