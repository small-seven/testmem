#include <common.h>
#include <command.h>
#include <env.h>
#include <image.h>
#include <u-boot/zlib.h>
#include <bzlib.h>
#include <watchdog.h>
#include <asm/byteorder.h>
#ifdef CONFIG_SHOW_BOOT_PROGRESS
# include <status_led.h>
#endif
#define PHYSADDR(x) x
#define LINUX_MAX_ENVS		256
#define LINUX_MAX_ARGS		256
