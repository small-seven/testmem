#include <common.h>
#include <linux/bitops.h>
#include <clk-uclass.h>
#include <clk.h>
#include <asm/arch/sys_proto.h>
#include <dm.h>
#define CRF_APB_APLL_CTRL		(zynqmp_crf_apb_clkc_base + 0x00)
#define CRF_APB_DPLL_CTRL		(zynqmp_crf_apb_clkc_base + 0x0c)
#define CRF_APB_VPLL_CTRL		(zynqmp_crf_apb_clkc_base + 0x18)
#define CRF_APB_PLL_STATUS		(zynqmp_crf_apb_clkc_base + 0x24)
#define CRF_APB_APLL_TO_LPD_CTRL	(zynqmp_crf_apb_clkc_base + 0x28)
#define CRF_APB_DPLL_TO_LPD_CTRL	(zynqmp_crf_apb_clkc_base + 0x2c)
#define CRF_APB_VPLL_TO_LPD_CTRL	(zynqmp_crf_apb_clkc_base + 0x30)
#define CRF_APB_ACPU_CTRL		(zynqmp_crf_apb_clkc_base + 0x40)
#define CRF_APB_DBG_TRACE_CTRL		(zynqmp_crf_apb_clkc_base + 0x44)
#define CRF_APB_DBG_FPD_CTRL		(zynqmp_crf_apb_clkc_base + 0x48)
#define CRF_APB_DP_VIDEO_REF_CTRL	(zynqmp_crf_apb_clkc_base + 0x50)
#define CRF_APB_DP_AUDIO_REF_CTRL	(zynqmp_crf_apb_clkc_base + 0x54)
#define CRF_APB_DP_STC_REF_CTRL		(zynqmp_crf_apb_clkc_base + 0x5c)
#define CRF_APB_DDR_CTRL		(zynqmp_crf_apb_clkc_base + 0x60)
#define CRF_APB_GPU_REF_CTRL		(zynqmp_crf_apb_clkc_base + 0x64)
#define CRF_APB_SATA_REF_CTRL		(zynqmp_crf_apb_clkc_base + 0x80)
#define CRF_APB_PCIE_REF_CTRL		(zynqmp_crf_apb_clkc_base + 0x94)
#define CRF_APB_GDMA_REF_CTRL		(zynqmp_crf_apb_clkc_base + 0x98)
#define CRF_APB_DPDMA_REF_CTRL		(zynqmp_crf_apb_clkc_base + 0x9c)
#define CRF_APB_TOPSW_MAIN_CTRL		(zynqmp_crf_apb_clkc_base + 0xa0)
#define CRF_APB_TOPSW_LSBUS_CTRL	(zynqmp_crf_apb_clkc_base + 0xa4)
#define CRF_APB_GTGREF0_REF_CTRL	(zynqmp_crf_apb_clkc_base + 0xa8)
#define CRF_APB_DBG_TSTMP_CTRL		(zynqmp_crf_apb_clkc_base + 0xd8)
#define CRL_APB_IOPLL_CTRL		(zynqmp_crl_apb_clkc_base + 0x00)
#define CRL_APB_RPLL_CTRL		(zynqmp_crl_apb_clkc_base + 0x10)
#define CRL_APB_PLL_STATUS		(zynqmp_crl_apb_clkc_base + 0x20)
#define CRL_APB_IOPLL_TO_FPD_CTRL	(zynqmp_crl_apb_clkc_base + 0x24)
#define CRL_APB_RPLL_TO_FPD_CTRL	(zynqmp_crl_apb_clkc_base + 0x28)
#define CRL_APB_USB3_DUAL_REF_CTRL	(zynqmp_crl_apb_clkc_base + 0x2c)
#define CRL_APB_GEM0_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x30)
#define CRL_APB_GEM1_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x34)
#define CRL_APB_GEM2_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x38)
#define CRL_APB_GEM3_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x3c)
#define CRL_APB_USB0_BUS_REF_CTRL	(zynqmp_crl_apb_clkc_base + 0x40)
#define CRL_APB_USB1_BUS_REF_CTRL	(zynqmp_crl_apb_clkc_base + 0x44)
#define CRL_APB_QSPI_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x48)
#define CRL_APB_SDIO0_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x4c)
#define CRL_APB_SDIO1_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x50)
#define CRL_APB_UART0_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x54)
#define CRL_APB_UART1_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x58)
#define CRL_APB_SPI0_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x5c)
#define CRL_APB_SPI1_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x60)
#define CRL_APB_CAN0_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x64)
#define CRL_APB_CAN1_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x68)
#define CRL_APB_CPU_R5_CTRL		(zynqmp_crl_apb_clkc_base + 0x70)
#define CRL_APB_IOU_SWITCH_CTRL		(zynqmp_crl_apb_clkc_base + 0x7c)
#define CRL_APB_CSU_PLL_CTRL		(zynqmp_crl_apb_clkc_base + 0x80)
#define CRL_APB_PCAP_CTRL		(zynqmp_crl_apb_clkc_base + 0x84)
#define CRL_APB_LPD_SWITCH_CTRL		(zynqmp_crl_apb_clkc_base + 0x88)
#define CRL_APB_LPD_LSBUS_CTRL		(zynqmp_crl_apb_clkc_base + 0x8c)
#define CRL_APB_DBG_LPD_CTRL		(zynqmp_crl_apb_clkc_base + 0x90)
#define CRL_APB_NAND_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x94)
#define CRL_APB_ADMA_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x98)
#define CRL_APB_PL0_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0xa0)
#define CRL_APB_PL1_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0xa4)
#define CRL_APB_PL2_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0xa8)
#define CRL_APB_PL3_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0xac)
#define CRL_APB_PL0_THR_CNT		(zynqmp_crl_apb_clkc_base + 0xb4)
#define CRL_APB_PL1_THR_CNT		(zynqmp_crl_apb_clkc_base + 0xbc)
#define CRL_APB_PL2_THR_CNT		(zynqmp_crl_apb_clkc_base + 0xc4)
#define CRL_APB_PL3_THR_CNT		(zynqmp_crl_apb_clkc_base + 0xdc)
#define CRL_APB_GEM_TSU_REF_CTRL	(zynqmp_crl_apb_clkc_base + 0xe0)
#define CRL_APB_DLL_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0xe4)
#define CRL_APB_AMS_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0xe8)
#define CRL_APB_I2C0_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x100)
#define CRL_APB_I2C1_REF_CTRL		(zynqmp_crl_apb_clkc_base + 0x104)
#define CRL_APB_TIMESTAMP_REF_CTRL	(zynqmp_crl_apb_clkc_base + 0x108)
#define ZYNQ_CLK_MAXDIV		0x3f
#define CLK_CTRL_DIV1_SHIFT	16
#define CLK_CTRL_DIV1_MASK	(ZYNQ_CLK_MAXDIV << CLK_CTRL_DIV1_SHIFT)
#define CLK_CTRL_DIV0_SHIFT	8
#define CLK_CTRL_DIV0_MASK	(ZYNQ_CLK_MAXDIV << CLK_CTRL_DIV0_SHIFT)
#define CLK_CTRL_SRCSEL_SHIFT	0
#define CLK_CTRL_SRCSEL_MASK	(0x3 << CLK_CTRL_SRCSEL_SHIFT)
#define PLLCTRL_FBDIV_MASK	0x7f00
#define PLLCTRL_FBDIV_SHIFT	8
#define PLLCTRL_RESET_MASK	1
#define PLLCTRL_RESET_SHIFT	0
#define PLLCTRL_BYPASS_MASK	0x8
#define PLLCTRL_BYPASS_SHFT	3
#define PLLCTRL_POST_SRC_SHFT	24
#define PLLCTRL_POST_SRC_MASK	(0x7 << PLLCTRL_POST_SRC_SHFT)
#define PLLCTRL_PRE_SRC_SHFT	20
#define PLLCTRL_PRE_SRC_MASK	(0x7 << PLLCTRL_PRE_SRC_SHFT)
#define NUM_MIO_PINS	77
