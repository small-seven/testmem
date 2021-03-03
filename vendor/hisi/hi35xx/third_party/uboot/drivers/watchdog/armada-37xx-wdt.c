#include <common.h>
#include <dm.h>
#include <wdt.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#define CNTR_CTRL(id)			((id) * 0x10)
#define CNTR_CTRL_ENABLE		0x0001
#define CNTR_CTRL_ACTIVE		0x0002
#define CNTR_CTRL_MODE_MASK		0x000c
#define CNTR_CTRL_MODE_ONESHOT		0x0000
#define CNTR_CTRL_MODE_HWSIG		0x000c
#define CNTR_CTRL_TRIG_SRC_MASK		0x00f0
#define CNTR_CTRL_TRIG_SRC_PREV_CNTR	0x0050
#define CNTR_CTRL_PRESCALE_MASK		0xff00
#define CNTR_CTRL_PRESCALE_MIN		2
#define CNTR_CTRL_PRESCALE_SHIFT	8
#define CNTR_COUNT_LOW(id)		(CNTR_CTRL(id) + 0x4)
#define CNTR_COUNT_HIGH(id)		(CNTR_CTRL(id) + 0x8)
