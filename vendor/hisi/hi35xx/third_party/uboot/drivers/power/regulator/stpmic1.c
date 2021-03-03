#include <common.h>
#include <dm.h>
#include <errno.h>
#include <power/pmic.h>
#include <power/regulator.h>
#include <power/stpmic1.h>
#define STPMIC1_MODE(_id, _val, _name) { \
#define STPMIC1_RANGE(_min_uv, _min_sel, _max_sel, _step) { \
#define STPMIC1_OUTPUT(_ranges, _nbranges) { \
