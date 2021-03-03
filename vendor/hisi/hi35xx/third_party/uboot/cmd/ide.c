#include <common.h>
#include <blk.h>
#include <config.h>
#include <watchdog.h>
#include <command.h>
#include <image.h>
#include <asm/byteorder.h>
#include <asm/io.h>
#include <ide.h>
#include <ata.h>
#ifdef CONFIG_LED_STATUS
# include <status_led.h>
#endif
