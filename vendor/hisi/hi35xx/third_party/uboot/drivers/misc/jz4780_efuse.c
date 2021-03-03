#include <common.h>
#include <asm/io.h>
#include <asm/unaligned.h>
#include <errno.h>
#include <mach/jz4780.h>
#include <wait_bit.h>
#define EFUSE_EFUCTRL			0xd0
#define EFUSE_EFUCFG			0xd4
#define EFUSE_EFUSTATE			0xd8
#define EFUSE_EFUDATA(n)		(0xdc + ((n) * 4))
#define EFUSE_EFUCTRL_RD_EN		BIT(0)
#define EFUSE_EFUCTRL_LEN_BIT		16
#define EFUSE_EFUCTRL_LEN_MASK		0x1f
#define EFUSE_EFUCTRL_ADDR_BIT		21
#define EFUSE_EFUCTRL_ADDR_MASK		0x1ff
#define EFUSE_EFUCTRL_CS		BIT(30)
#define EFUSE_EFUCFG_RD_STROBE_BIT	16
#define EFUSE_EFUCFG_RD_STROBE_MASK	0xf
#define EFUSE_EFUCFG_RD_ADJ_BIT		20
#define EFUSE_EFUCFG_RD_ADJ_MASK	0xf
#define EFUSE_EFUSTATE_RD_DONE		BIT(0)
