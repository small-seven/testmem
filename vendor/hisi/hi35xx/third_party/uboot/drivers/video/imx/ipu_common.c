#include <common.h>
#include <linux/types.h>
#include <linux/err.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/sys_proto.h>
#include <div64.h>
#include "ipu.h"
#include "ipu_regs.h"
#define ipu_ch_param_addr(ch) (((struct ipu_ch_param *)ipu_cpmem_base) + (ch))
#define _param_word(base, w) \
#define ipu_ch_param_set_field(base, w, bit, size, v) { \
#define ipu_ch_param_mod_field(base, w, bit, size, v) { \
#define ipu_ch_param_read_field(base, w, bit, size) ({ \
#define IPU_SW_RST_TOUT_USEC	(10000)
#define IPUV3_CLK_MX51		133000000
#define IPUV3_CLK_MX53		200000000
#define IPUV3_CLK_MX6Q		264000000
#define IPUV3_CLK_MX6DL		198000000
#if defined(CONFIG_MX51) || defined(CONFIG_MX53)
#endif
#if defined(CONFIG_MX51) || defined(CONFIG_MX53)
#endif
#if defined(CONFIG_MX51) || defined(CONFIG_MX53)
#else
#endif
#if !defined CONFIG_SYS_LDB_CLOCK
#define CONFIG_SYS_LDB_CLOCK 65000000
#endif
#define idma_is_valid(ch)	(ch != NO_DMA)
#define idma_mask(ch)		(idma_is_valid(ch) ? (1UL << (ch & 0x1F)) : 0)
#define idma_is_set(reg, dma)	(__raw_readl(reg(dma)) & idma_mask(dma))
#if defined CONFIG_MX51
#endif
#if defined(CONFIG_MX51)
#elif defined(CONFIG_MX53)
#else
#endif
#ifdef DEBUG
#endif
