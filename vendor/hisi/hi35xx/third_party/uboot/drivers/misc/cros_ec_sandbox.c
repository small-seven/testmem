#include <common.h>
#include <cros_ec.h>
#include <dm.h>
#include <ec_commands.h>
#include <errno.h>
#include <hash.h>
#include <malloc.h>
#include <os.h>
#include <u-boot/sha256.h>
#include <spi.h>
#include <asm/state.h>
#include <asm/sdl.h>
#include <linux/input.h>
#define KEYBOARD_ROWS	8
#define KEYBOARD_COLS	13
