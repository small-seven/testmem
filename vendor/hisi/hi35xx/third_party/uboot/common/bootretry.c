#include <common.h>
#include <bootretry.h>
#include <cli.h>
#include <env.h>
#include <errno.h>
#include <time.h>
#include <watchdog.h>
#ifndef CONFIG_BOOT_RETRY_MIN
#define CONFIG_BOOT_RETRY_MIN CONFIG_BOOT_RETRY_TIME
#endif
