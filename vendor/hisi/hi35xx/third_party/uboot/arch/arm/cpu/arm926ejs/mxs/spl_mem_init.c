#include <common.h>
#include <config.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <linux/compiler.h>
#include "mxs_init.h"
#if defined(CONFIG_MX28)
#elif defined(CONFIG_MX23)
#else
#error Unsupported memory initialization
#endif
#ifdef CONFIG_MX28
#else
#endif
#if defined(CONFIG_MX23)
#elif defined(CONFIG_MX28)
#endif
#ifdef CONFIG_MX23
static void mx23_mem_init(void)
{
	debug("SPL: Initialising mx23 SDRAM Controller\n");

	/*
	 * Reset/ungate the EMI block. This is essential, otherwise the system
	 * suffers from memory instability. This thing is mx23 specific and is
	 * no longer present on mx28.
	 */
	mxs_reset_block((struct mxs_register_32 *)MXS_EMI_BASE);

	mx23_mem_setup_vddmem();

	/*
	 * Configure the DRAM registers
	 */

	/* Clear START and SREFRESH bit from DRAM_CTL8 */
	clrbits_le32(MXS_DRAM_BASE + 0x20, (1 << 16) | (1 << 8));

	initialize_dram_values();

	/* Set START bit in DRAM_CTL8 */
	setbits_le32(MXS_DRAM_BASE + 0x20, 1 << 16);

	clrbits_le32(MXS_DRAM_BASE + 0x40, 1 << 17);

	/* Wait for EMI_STAT bit DRAM_HALTED */
	for (;;) {
		if (!(readl(MXS_EMI_BASE + 0x10) & (1 << 1)))
			break;
		early_delay(1000);
	}

	/* Adjust EMI port priority. */
	clrsetbits_le32(0x80020000, 0x1f << 16, 0x2);
	early_delay(20000);

	setbits_le32(MXS_DRAM_BASE + 0x40, 1 << 19);
	setbits_le32(MXS_DRAM_BASE + 0x40, 1 << 11);
}
#endif
#ifdef CONFIG_MX28
static void mx28_mem_init(void)
{
	struct mxs_pinctrl_regs *pinctrl_regs =
		(struct mxs_pinctrl_regs *)MXS_PINCTRL_BASE;

	debug("SPL: Initialising mx28 SDRAM Controller\n");

	/* Set DDR2 mode */
	writel(PINCTRL_EMI_DS_CTRL_DDR_MODE_DDR2,
		&pinctrl_regs->hw_pinctrl_emi_ds_ctrl_set);

	/*
	 * Configure the DRAM registers
	 */

	/* Clear START bit from DRAM_CTL16 */
	clrbits_le32(MXS_DRAM_BASE + 0x40, 1);

	initialize_dram_values();

	/* Clear SREFRESH bit from DRAM_CTL17 */
	clrbits_le32(MXS_DRAM_BASE + 0x44, 1);

	/* Set START bit in DRAM_CTL16 */
	setbits_le32(MXS_DRAM_BASE + 0x40, 1);

	/* Wait for bit 20 (DRAM init complete) in DRAM_CTL58 */
	while (!(readl(MXS_DRAM_BASE + 0xe8) & (1 << 20)))
		;
}
#endif
void mxs_mem_init(void)
{
	early_delay(11000);

	mxs_mem_init_clock();

	mxs_mem_setup_vdda();

#if defined(CONFIG_MX23)
	mx23_mem_init();
#elif defined(CONFIG_MX28)
	mx28_mem_init();
#endif

	early_delay(10000);

	mxs_mem_setup_cpu_and_hbus();
}
