#include <common.h>
#include <fdtdec.h>
#include <errno.h>
#include <dm.h>
#include <vsprintf.h>
#include <dm/lists.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
#include <power/pmic.h>
#include <linux/ctype.h>
#if CONFIG_IS_ENABLED(PMIC_CHILDREN)
#endif
