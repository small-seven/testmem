#include <common.h>
#include <dm.h>
#include <env.h>
#include <errno.h>
#include <i8042.h>
#include <input.h>
#include <keyboard.h>
#include <asm/io.h>
#define in8(p)		inb(p)
#define out8(p, v)	outb(v, p)
static int i8042_kbd_remove(struct udevice *dev)
{
	if (i8042_disable())
		log_debug("i8042_disable() failed. fine, continue.\n");
	i8042_flush();

	return 0;
}
