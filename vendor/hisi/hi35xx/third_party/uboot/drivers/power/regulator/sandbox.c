#include <common.h>
#include <fdtdec.h>
#include <errno.h>
#include <dm.h>
#include <i2c.h>
#include <power/pmic.h>
#include <power/regulator.h>
#include <power/sandbox_pmic.h>
#define MODE(_id, _val, _name) [_id] = {  \
#define RANGE(_min, _max, _step) { \
