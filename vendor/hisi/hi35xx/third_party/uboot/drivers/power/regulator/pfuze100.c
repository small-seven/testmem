#include <common.h>
#include <fdtdec.h>
#include <errno.h>
#include <dm.h>
#include <i2c.h>
#include <power/pmic.h>
#include <power/regulator.h>
#include <power/pfuze100_pmic.h>
#define PFUZE100_FIXED_REG(_name, base, vol)				\
#define PFUZE100_SW_REG(_name, base, step)				\
#define PFUZE100_SWB_REG(_name, base, mask, step, voltages)		\
#define PFUZE100_SNVS_REG(_name, base, mask, voltages)			\
#define PFUZE100_VGEN_REG(_name, base, step)				\
#define PFUZE3000_VCC_REG(_name, base, step)				\
#define PFUZE3000_SW1_REG(_name, base, step)				\
#define PFUZE3000_SW2_REG(_name, base, step)				\
#define PFUZE3000_SW3_REG(_name, base, step)				\
#define MODE(_id, _val, _name) { \
