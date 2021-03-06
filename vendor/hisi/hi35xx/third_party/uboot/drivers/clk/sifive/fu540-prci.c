#include <common.h>
#include <asm/io.h>
#include <clk-uclass.h>
#include <clk.h>
#include <div64.h>
#include <dm.h>
#include <errno.h>
#include <linux/math64.h>
#include <linux/clk/analogbits-wrpll-cln28hpc.h>
#include <dt-bindings/clock/sifive-fu540-prci.h>
#define EXPECTED_CLK_PARENT_COUNT	2
#define PRCI_COREPLLCFG0_OFFSET		0x4
#define PRCI_COREPLLCFG0_DIVR_SHIFT	0
#define PRCI_COREPLLCFG0_DIVR_MASK	(0x3f << PRCI_COREPLLCFG0_DIVR_SHIFT)
#define PRCI_COREPLLCFG0_DIVF_SHIFT	6
#define PRCI_COREPLLCFG0_DIVF_MASK	(0x1ff << PRCI_COREPLLCFG0_DIVF_SHIFT)
#define PRCI_COREPLLCFG0_DIVQ_SHIFT	15
#define PRCI_COREPLLCFG0_DIVQ_MASK	(0x7 << PRCI_COREPLLCFG0_DIVQ_SHIFT)
#define PRCI_COREPLLCFG0_RANGE_SHIFT	18
#define PRCI_COREPLLCFG0_RANGE_MASK	(0x7 << PRCI_COREPLLCFG0_RANGE_SHIFT)
#define PRCI_COREPLLCFG0_BYPASS_SHIFT	24
#define PRCI_COREPLLCFG0_BYPASS_MASK	(0x1 << PRCI_COREPLLCFG0_BYPASS_SHIFT)
#define PRCI_COREPLLCFG0_FSE_SHIFT	25
#define PRCI_COREPLLCFG0_FSE_MASK	(0x1 << PRCI_COREPLLCFG0_FSE_SHIFT)
#define PRCI_COREPLLCFG0_LOCK_SHIFT	31
#define PRCI_COREPLLCFG0_LOCK_MASK	(0x1 << PRCI_COREPLLCFG0_LOCK_SHIFT)
#define PRCI_DDRPLLCFG0_OFFSET		0xc
#define PRCI_DDRPLLCFG0_DIVR_SHIFT	0
#define PRCI_DDRPLLCFG0_DIVR_MASK	(0x3f << PRCI_DDRPLLCFG0_DIVR_SHIFT)
#define PRCI_DDRPLLCFG0_DIVF_SHIFT	6
#define PRCI_DDRPLLCFG0_DIVF_MASK	(0x1ff << PRCI_DDRPLLCFG0_DIVF_SHIFT)
#define PRCI_DDRPLLCFG0_DIVQ_SHIFT	15
#define PRCI_DDRPLLCFG0_DIVQ_MASK	(0x7 << PRCI_DDRPLLCFG0_DIVQ_SHIFT)
#define PRCI_DDRPLLCFG0_RANGE_SHIFT	18
#define PRCI_DDRPLLCFG0_RANGE_MASK	(0x7 << PRCI_DDRPLLCFG0_RANGE_SHIFT)
#define PRCI_DDRPLLCFG0_BYPASS_SHIFT	24
#define PRCI_DDRPLLCFG0_BYPASS_MASK	(0x1 << PRCI_DDRPLLCFG0_BYPASS_SHIFT)
#define PRCI_DDRPLLCFG0_FSE_SHIFT	25
#define PRCI_DDRPLLCFG0_FSE_MASK	(0x1 << PRCI_DDRPLLCFG0_FSE_SHIFT)
#define PRCI_DDRPLLCFG0_LOCK_SHIFT	31
#define PRCI_DDRPLLCFG0_LOCK_MASK	(0x1 << PRCI_DDRPLLCFG0_LOCK_SHIFT)
#define PRCI_DDRPLLCFG1_OFFSET		0x10
#define PRCI_DDRPLLCFG1_CKE_SHIFT	24
#define PRCI_DDRPLLCFG1_CKE_MASK	(0x1 << PRCI_DDRPLLCFG1_CKE_SHIFT)
#define PRCI_GEMGXLPLLCFG0_OFFSET	0x1c
#define PRCI_GEMGXLPLLCFG0_DIVR_SHIFT	0
#define PRCI_GEMGXLPLLCFG0_DIVR_MASK	\
#define PRCI_GEMGXLPLLCFG0_DIVF_SHIFT	6
#define PRCI_GEMGXLPLLCFG0_DIVF_MASK	\
#define PRCI_GEMGXLPLLCFG0_DIVQ_SHIFT	15
#define PRCI_GEMGXLPLLCFG0_DIVQ_MASK	(0x7 << PRCI_GEMGXLPLLCFG0_DIVQ_SHIFT)
#define PRCI_GEMGXLPLLCFG0_RANGE_SHIFT	18
#define PRCI_GEMGXLPLLCFG0_RANGE_MASK	\
#define PRCI_GEMGXLPLLCFG0_BYPASS_SHIFT 24
#define PRCI_GEMGXLPLLCFG0_BYPASS_MASK	\
#define PRCI_GEMGXLPLLCFG0_FSE_SHIFT	25
#define PRCI_GEMGXLPLLCFG0_FSE_MASK	\
#define PRCI_GEMGXLPLLCFG0_LOCK_SHIFT	31
#define PRCI_GEMGXLPLLCFG0_LOCK_MASK	(0x1 << PRCI_GEMGXLPLLCFG0_LOCK_SHIFT)
#define PRCI_GEMGXLPLLCFG1_OFFSET	0x20
#define PRCI_GEMGXLPLLCFG1_CKE_SHIFT	24
#define PRCI_GEMGXLPLLCFG1_CKE_MASK	(0x1 << PRCI_GEMGXLPLLCFG1_CKE_SHIFT)
#define PRCI_CORECLKSEL_OFFSET		0x24
#define PRCI_CORECLKSEL_CORECLKSEL_SHIFT 0
#define PRCI_CORECLKSEL_CORECLKSEL_MASK \
#define PRCI_DEVICESRESETREG_OFFSET	0x28
#define PRCI_DEVICESRESETREG_DDR_CTRL_RST_N_SHIFT 0
#define PRCI_DEVICESRESETREG_DDR_CTRL_RST_N_MASK \
#define PRCI_DEVICESRESETREG_DDR_AXI_RST_N_SHIFT 1
#define PRCI_DEVICESRESETREG_DDR_AXI_RST_N_MASK \
#define PRCI_DEVICESRESETREG_DDR_AHB_RST_N_SHIFT 2
#define PRCI_DEVICESRESETREG_DDR_AHB_RST_N_MASK \
#define PRCI_DEVICESRESETREG_DDR_PHY_RST_N_SHIFT 3
#define PRCI_DEVICESRESETREG_DDR_PHY_RST_N_MASK \
#define PRCI_DEVICESRESETREG_GEMGXL_RST_N_SHIFT 5
#define PRCI_DEVICESRESETREG_GEMGXL_RST_N_MASK \
#define PRCI_CLKMUXSTATUSREG_OFFSET		0x2c
#define PRCI_CLKMUXSTATUSREG_TLCLKSEL_STATUS_SHIFT 1
#define PRCI_CLKMUXSTATUSREG_TLCLKSEL_STATUS_MASK \
