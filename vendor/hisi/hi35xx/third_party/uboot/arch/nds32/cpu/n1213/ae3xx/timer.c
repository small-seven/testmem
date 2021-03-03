#ifndef CONFIG_TIMER
#include <common.h>
#include <asm/io.h>
#include <faraday/fttmr010.h>
#error "AE3XX timer only support DM flow"
#endif /* CONFIG_TIMER */
