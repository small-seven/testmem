#include <common.h>
#include <dm.h>
#include <errno.h>
#include <dm/pinctrl.h>
#include <linux/kernel.h>
#include "sh_pfc.h"
#define CPU_ALL_PORT(fn, sfx)						\
#define ROW_GROUP_A(r) ('Z' - 'A' + 1 + (r))
#define PIN_NUMBER(r, c) (((r) - 'A') * 31 + (c) + 200)
#define PIN_A_NUMBER(r, c) PIN_NUMBER(ROW_GROUP_A(r), c)
