#include <common.h>
#include <asm/io.h>
#include <asm/arch/iomux.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <spl.h>
#define UART_PAD_CTRL  (PAD_CTL_PUS_100K_UP |			\
#ifdef CONFIG_UART2_EIM_D26_27
#elif defined(CONFIG_UART1_CSI0_DAT10_11)
#elif defined(CONFIG_UART1_SD3_DAT6_7)
#elif defined(CONFIG_UART1_UART1)
#else
#error select UART console pads
#endif
#ifdef CONFIG_DDR3
#define GRP_DDRTYPE	0x000C0000
#else
#define GRP_DDRTYPE	0x00080000
#endif
#define DDR_PKE		0
#define DDR_ODT	\
#define DRAM_DRIVE_STRENGTH \
#if CONFIG_DDRWIDTH == 32
#elif CONFIG_DDRWIDTH == 64
#else
#error missing CONFIG_DDRWIDTH
#endif
#ifdef CONFIG_DDR3
#else
#endif
#ifdef CONFIG_MT41K512M16TNA
#elif defined(CONFIG_MT41K128M16JT)
#elif defined(CONFIG_H5TQ4G63AFR)
#elif defined CONFIG_H5TQ2G63DFR
#elif defined(CONFIG_MT42L256M32D2LG)
#elif defined(CONFIG_MT29PZZZ4D4BKESK)
#else
#error please select DDR type using menuconfig
#endif
#ifdef CONFIG_IMXIMAGE_OUTPUT
#endif
#ifdef CONFIG_MX6SL
#else
#endif
