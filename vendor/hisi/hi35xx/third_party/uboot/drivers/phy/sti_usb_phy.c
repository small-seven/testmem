#include <common.h>
#include <asm/io.h>
#include <bitfield.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <generic-phy.h>
#include <linux/libfdt.h>
#include <regmap.h>
#include <reset-uclass.h>
#include <syscon.h>
#include <wait_bit.h>
#include <linux/bitops.h>
#include <linux/compat.h>
#define STIH407_USB_PICOPHY_CTRL_PORT_CONF	0x6
#define STIH407_USB_PICOPHY_PARAM_DEF		0x39a4dc
#define PHYPARAM_REG	1
#define PHYCTRL_REG	2
#define PHYPARAM_NB	3
