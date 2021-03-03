#include <common.h>
#include <dm.h>
#include <dm/read.h>
#include <asm/io.h>
#include <linux/delay.h>
#include <misc.h>
#define SYS_CFGDATA		0xa0
#define SYS_CFGCTRL		0xa4
#define SYS_CFGCTRL_START	BIT(31)
#define SYS_CFGCTRL_WRITE	BIT(30)
#define SYS_CFGSTAT		0xa8
#define SYS_CFGSTAT_ERR		BIT(1)
#define SYS_CFGSTAT_COMPLETE	BIT(0)
