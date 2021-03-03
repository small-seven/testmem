#include <common.h>
#include <env.h>
#include <hwconfig.h>
#include <init.h>
#include <mpc8xx.h>
#include <fdt_support.h>
#include <serial.h>
#include <asm/io.h>
#include <dm/uclass.h>
#include <wdt.h>
#define SDRAM_MAX_SIZE			(32 * 1024 * 1024)
