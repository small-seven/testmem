#include <common.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/dram.h>
#include <asm/arch/cpu.h>
#include <linux/kconfig.h>
#ifdef CONFIG_MACH_SUN8I_R40
#endif
#define MBUS_CONF(port, bwlimit, qos, acs, bwl0, bwl1, bwl2)	\
#if defined CONFIG_SUNXI_DRAM_DW_16BIT
#else
#endif
#if defined CONFIG_SUNXI_DRAM_DDR3
#elif defined CONFIG_SUNXI_DRAM_DDR2
#elif defined CONFIG_SUNXI_DRAM_LPDDR3
#else
#error Unsupported DRAM type!
#endif
#define DX_GCR_ODT_DYNAMIC	(0x0 << 4)
#define DX_GCR_ODT_ALWAYS_ON	(0x1 << 4)
#define DX_GCR_ODT_OFF		(0x2 << 4)
#if defined CONFIG_SUNXI_DRAM_DW_32BIT
#elif defined CONFIG_SUNXI_DRAM_DW_16BIT
#else
#error Unsupported DRAM bus width!
#endif
#if defined CONFIG_SUNXI_DRAM_DW_32BIT
#endif
#if defined CONFIG_SUNXI_DRAM_DW_32BIT
#elif defined CONFIG_SUNXI_DRAM_DW_16BIT
#endif
#define SUN8I_H3_DX_READ_DELAYS					\
#define SUN8I_H3_DX_WRITE_DELAYS				\
#define SUN8I_H3_AC_DELAYS					\
#define SUN8I_R40_DX_READ_DELAYS				\
#define SUN8I_R40_DX_WRITE_DELAYS				\
#define SUN8I_R40_AC_DELAYS					\
#define SUN50I_A64_DX_READ_DELAYS				\
#define SUN50I_A64_DX_WRITE_DELAYS				\
#define SUN50I_A64_AC_DELAYS					\
#define SUN8I_H5_DX_READ_DELAYS					\
#define SUN8I_H5_DX_WRITE_DELAYS				\
#define SUN8I_H5_AC_DELAYS					\
#if defined(CONFIG_MACH_SUN8I_H3)
#elif defined(CONFIG_MACH_SUN8I_R40)
#elif defined(CONFIG_MACH_SUN50I)
#elif defined(CONFIG_MACH_SUN50I_H5)
#endif
#if defined(CONFIG_MACH_SUN8I_H3)
#elif defined(CONFIG_MACH_SUN8I_R40)
#elif defined(CONFIG_MACH_SUN8I_V3S)
#elif defined(CONFIG_MACH_SUN50I)
#elif defined(CONFIG_MACH_SUN50I_H5)
#endif
