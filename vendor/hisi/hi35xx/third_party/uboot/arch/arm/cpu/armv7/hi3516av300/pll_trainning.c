#include <asm/arch/platform.h>
#include <config.h>
#include <asm/io.h>
#include <asm/string.h>
#ifdef CONFIG_EDMA_PLL_TRAINNING
#define __24MHZ	24000000
#define LOOP_COUNT  5
#define THE_CRG_BASE	0x12010000
#define PERI_CRG_PLL1	0x04
#define PERI_CRG32	0x80
#define PERI_CRG81	0x144
#define PERI_CRG101	0x194
#define PERI_CRG110	0x1b8
#define PERI_CRG111	0x1bc
#define PERI_CRG120	0x1e0
#define MISC_REG_BASE	0x12030000
#define SVB_CTRL_BASE	0x12030000
#define SVB_SYS_VOLTAGE_OFFSET  0xb0
#define UART0_REG_PHYS	0x120a0000
#define UART1_REG_PHYS	0x120a1000
#define UART2_REG_PHYS	0x120a2000
#define UART3_REG_PHYS	0x120a3000
#define UART4_REG_PHYS	0x120a4000
#define UART_DR 0x0
#define UART_CR	 0x30
#define HIEDMA0_REG_BASE 0x10060000
#define INT_TC1		 0x4
#define INT_TC1_RAW	 0x600
#define DMA_RXCHNL_CONFIG    0x47700005
#define DMA_TXCHNL_CONFIG    0x87700005
#define DMA_REG_CHNL0   0X830
#define DMA_REG_CHNL1   0X870
#define DMA_CHNL0_DONE	(1<<0)
#define DMA_CHNL1_DONE	(1<<1)
#define DDR_DATA_BASE 0x82000000
#define ioremap(physaddr, size) ((void *)(physaddr))
#define iounmap(physassr)  ((void)0)
#define array_size(x) (sizeof(x) / sizeof((x)[0]))
#define pll_trainning_debug(s)
#define pll_trainning_debug_hex(s)
#endif
