#include <common.h>
#include <fuse.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#if defined(CONFIG_MX51) || defined(CONFIG_MX53)
#include <asm/arch/clock.h>
#endif
#define STAT_BUSY		0x80
#define STAT_PRGD		0x02
#define STAT_SNSD		0x01
#define STATM_PRGD_M		0x02
#define STATM_SNSD_M		0x01
#define ERR_PRGE		0x80
#define ERR_WPE			0x40
#define ERR_OPE			0x20
#define ERR_RPE			0x10
#define ERR_WLRE		0x08
#define ERR_SNSE		0x04
#define ERR_PARITYE		0x02
#define EMASK_PRGE_M		0x80
#define EMASK_WPE_M		0x40
#define EMASK_OPE_M		0x20
#define EMASK_RPE_M		0x10
#define EMASK_WLRE_M		0x08
#define EMASK_SNSE_M		0x04
#define EMASK_PARITYE_M		0x02
#define FCTL_DPC		0x80
#define FCTL_PRG_LENGTH_MASK	0x70
#define FCTL_ESNS_N		0x08
#define FCTL_ESNS_0		0x04
#define FCTL_ESNS_1		0x02
#define FCTL_PRG		0x01
#define UA_A_BANK_MASK		0x38
#define UA_A_ROWH_MASK		0x07
#define LA_A_ROWL_MASK		0xf8
#define LA_A_BIT_MASK		0x07
#define PREV_PROD_REV_MASK	0xf8
#define PREV_PROD_VT_MASK	0x07
#if __BYTE_ORDER == __LITTLE_ENDIAN
#define iim_read32		in_le32
#define iim_write32		out_le32
#define iim_clrsetbits32	clrsetbits_le32
#define iim_clrbits32		clrbits_le32
#define iim_setbits32		setbits_le32
#elif __BYTE_ORDER == __BIG_ENDIAN
#define iim_read32		in_be32
#define iim_write32		out_be32
#define iim_clrsetbits32	clrsetbits_be32
#define iim_clrbits32		clrbits_be32
#define iim_setbits32		setbits_be32
#else
#error Endianess is not defined: please fix to continue
#endif
#if !defined(CONFIG_MX51) && !defined(CONFIG_MX53)
#define enable_efuse_prog_supply(enable)
#endif
