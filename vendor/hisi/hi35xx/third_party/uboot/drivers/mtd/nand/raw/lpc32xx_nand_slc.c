#include <common.h>
#include <nand.h>
#include <linux/mtd/nand_ecc.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/config.h>
#include <asm/arch/clk.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/dma.h>
#include <asm/arch/cpu.h>
#define CFG_CE_LOW		(1 << 5)
#define CFG_DMA_ECC		(1 << 4) /* Enable DMA ECC bit */
#define CFG_ECC_EN		(1 << 3) /* ECC enable bit */
#define CFG_DMA_BURST		(1 << 2) /* DMA burst bit */
#define CFG_DMA_DIR		(1 << 1) /* DMA write(0)/read(1) bit */
#define CTRL_SW_RESET		(1 << 2)
#define CTRL_ECC_CLEAR		(1 << 1) /* Reset ECC bit */
#define CTRL_DMA_START		(1 << 0) /* Start DMA channel bit */
#define STAT_DMA_FIFO		(1 << 2) /* DMA FIFO has data bit */
#define STAT_NAND_READY		(1 << 0)
#define INT_STAT_TC		(1 << 1)
#define INT_STAT_RDY		(1 << 0)
#define TAC_W_RDY(n)		(max_t(uint32_t, (n), 0xF) << 28)
#define TAC_W_WIDTH(n)		(max_t(uint32_t, (n), 0xF) << 24)
#define TAC_W_HOLD(n)		(max_t(uint32_t, (n), 0xF) << 20)
#define TAC_W_SETUP(n)		(max_t(uint32_t, (n), 0xF) << 16)
#define TAC_R_RDY(n)		(max_t(uint32_t, (n), 0xF) << 12)
#define TAC_R_WIDTH(n)		(max_t(uint32_t, (n), 0xF) << 8)
#define TAC_R_HOLD(n)		(max_t(uint32_t, (n), 0xF) << 4)
#define TAC_R_SETUP(n)		(max_t(uint32_t, (n), 0xF) << 0)
#if defined(CONFIG_DMA_LPC32XX) && !defined(CONFIG_SPL_BUILD)
#define ECCSTEPS	(CONFIG_SYS_NAND_PAGE_SIZE / CONFIG_SYS_NAND_ECCSIZE)
#define lpc32xx_dmac_next_lli(x)	((u32)x)
#define lpc32xx_dmac_set_dma_data()	((u32)&lpc32xx_nand_slc_regs->dma_data)
#define lpc32xx_dmac_set_ecc()		((u32)&lpc32xx_nand_slc_regs->ecc)
#endif
#if defined(CONFIG_DMA_LPC32XX) && !defined(CONFIG_SPL_BUILD)
#else
#endif
#if defined(CONFIG_DMA_LPC32XX) && !defined(CONFIG_SPL_BUILD)
#endif
#if defined(CONFIG_DMA_LPC32XX) && !defined(CONFIG_SPL_BUILD)
#else
#endif
#if defined(CONFIG_SYS_NAND_USE_FLASH_BBT)
#endif
