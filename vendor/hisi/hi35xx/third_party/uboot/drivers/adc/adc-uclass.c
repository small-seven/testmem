#include <common.h>
#include <errno.h>
#include <div64.h>
#include <dm.h>
#include <dm/lists.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
#include <adc.h>
#include <power/regulator.h>
#define ADC_UCLASS_PLATDATA_SIZE	sizeof(struct adc_uclass_platdata)
#define CHECK_NUMBER			true
#define CHECK_MASK			(!CHECK_NUMBER)
#ifdef CONFIG_SANDBOX_ARCH
#define sdelay(x)	udelay(x)
#else
#endif
