#include <common.h>
#include <bitfield.h>
#include <dm.h>
#include <errno.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/io.h>
#include <dm/pinctrl.h>
#define MAX_STI_PINCONF_ENTRIES		7
#define OE			(1 << 27)
#define PU			(1 << 26)
#define OD			(1 << 25)
#define IN			(0)
#define IN_PU			(PU)
#define OUT			(OE)
#define OUT_PU			(OE | PU)
#define BIDIR			(OE | OD)
#define BIDIR_PU		(OE | PU | OD)
