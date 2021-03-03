#include <common.h>
#include <cpu_func.h>
#include <linux/io.h>
#include <asm/cacheops.h>
#include <asm/io.h>
#include "mt76xx.h"
#define NUM_OF_CACHELINE	128
#define MIN_START		6
#define MIN_FINE_START		0xf
#define MAX_START		7
#define MAX_FINE_START		0x0
#define CPU_FRAC_DIV		1
#if defined(CONFIG_ONBOARD_DDR2_SIZE_256MBIT)
#define DRAM_BUTTOM 0x02000000
#endif
#if defined(CONFIG_ONBOARD_DDR2_SIZE_512MBIT)
#define DRAM_BUTTOM 0x04000000
#endif
#if defined(CONFIG_ONBOARD_DDR2_SIZE_1024MBIT)
#define DRAM_BUTTOM 0x08000000
#endif
#if defined(CONFIG_ONBOARD_DDR2_SIZE_2048MBIT)
#define DRAM_BUTTOM 0x10000000
#endif
static inline void cal_memcpy(void *src, void *dst, u32 size)
{
	u8 *psrc = (u8 *)src;
	u8 *pdst = (u8 *)dst;
	int i;

	for (i = 0; i < size; i++, psrc++, pdst++)
		*pdst = *psrc;
}
static inline void cal_memset(void *src, u8 pat, u32 size)
{
	u8 *psrc = (u8 *)src;
	int i;

	for (i = 0; i < size; i++, psrc++)
		*psrc = pat;
}
#define pref_op(hint, addr)						\
