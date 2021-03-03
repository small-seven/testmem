#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <os.h>
#include <rtc.h>
#include <asm/rtc.h>
#include <asm/test.h>
#ifdef DEBUG
#define debug_buffer print_buffer
#else
#define debug_buffer(x, ...)
#endif
