#include <common.h>
#include <fdtdec.h>
#include <errno.h>
#include <dm.h>
#include <i2c.h>
#include <power/pmic.h>
#include <power/regulator.h>
#include <power/palmas.h>
#define	REGULATOR_ON		0x1
#define	REGULATOR_OFF		0x0
#define	SMPS_MODE_MASK		0x3
#define	SMPS_MODE_SHIFT		0x0
#define	LDO_MODE_MASK		0x1
#define	LDO_MODE_SHIFT		0x0
