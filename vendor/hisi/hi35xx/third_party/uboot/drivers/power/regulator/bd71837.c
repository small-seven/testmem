#include <common.h>
#include <dm.h>
#include <power/bd71837.h>
#include <power/pmic.h>
#include <power/regulator.h>
#define HW_STATE_CONTROL 0
#define DEBUG
#define BD_RANGE(_min, _vstep, _sel_low, _sel_hi, _range_sel) \
#define BD_DATA(_name, enreg, enmask, vreg, vmask, _range, rmask, _dvs, sel) \
