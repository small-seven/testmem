#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <dm/read.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/cpu.h>
#include <asm/scu.h>
#include <linux/io.h>
#define BUFCFG_OFFSET				0x100
#define MRFLD_FAMILY_LEN			0x400
#define MRFLD_PINMODE_MASK			0x07
#define pin_to_bufno(f, p)			((p) - (f)->pin_base)
#define MRFLD_FAMILY(b, s, e)				\
