#include <common.h>
#include <dm.h>
#include <errno.h>
#include <asm/io.h>
#include <i2c.h>
#include <k3-avs.h>
#include <power/regulator.h>
#define AM6_VTM_DEVINFO(i)	(priv->base + 0x100 + 0x20 * (i))
#define AM6_VTM_OPPVID_VD(i)	(priv->base + 0x104 + 0x20 * (i))
#define AM6_VTM_AVS0_SUPPORTED	BIT(12)
#define AM6_VTM_OPP_SHIFT(opp)	(8 * (opp))
#define AM6_VTM_OPP_MASK	0xff
#define VD_FLAG_INIT_DONE	BIT(0)
