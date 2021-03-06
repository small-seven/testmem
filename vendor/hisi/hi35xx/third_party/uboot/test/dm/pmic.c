#include <common.h>
#include <errno.h>
#include <dm.h>
#include <fdtdec.h>
#include <malloc.h>
#include <dm/device-internal.h>
#include <dm/root.h>
#include <dm/util.h>
#include <dm/test.h>
#include <dm/uclass-internal.h>
#include <power/pmic.h>
#include <power/sandbox_pmic.h>
#include <test/ut.h>
#include <fsl_pmic.h>
#define MC34708_PMIC_REG_COUNT 64
#define MC34708_PMIC_TEST_VAL 0x125534
