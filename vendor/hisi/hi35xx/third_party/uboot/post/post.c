#include <common.h>
#include <env.h>
#include <stdio_dev.h>
#include <time.h>
#include <watchdog.h>
#include <div64.h>
#include <post.h>
#ifdef CONFIG_SYS_POST_HOTKEYS_GPIO
#include <asm/gpio.h>
#endif
#define POST_MAX_NUMBER		32
#define BOOTMODE_MAGIC	0xDEAD0000
#ifdef CONFIG_SYS_POST_HOTKEYS_GPIO
#endif
#ifndef CONFIG_POST_SKIP_ENV_FLAGS
#endif
#ifndef CONFIG_POST_SKIP_ENV_FLAGS
#endif
#ifdef CONFIG_NEEDS_MANUAL_RELOC
#endif
#if defined(CONFIG_PPC) || defined(CONFIG_ARM)
#else
#warning "Not implemented yet"
#endif
