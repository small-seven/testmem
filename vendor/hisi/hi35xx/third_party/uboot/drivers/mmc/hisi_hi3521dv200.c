#define PERI_CRG_MMC_CLK	(CRG_REG_BASE + 0x34c0)
#define  CRG_CLK_SEL_SHIFT	24
#define  CRG_CLK_SEL_MASK	(0x7 << CRG_CLK_SEL_SHIFT)
#define  CRG_DLL_SRST_REQ	(1 << 16)
#define  CRG_CLK_EN		(1 << 0)
#define  CRG_AHB_CLK_EN		(2 << 0)
#define PERI_CRG_MMC_P4_DLL	(CRG_REG_BASE + 0x34c4)
#define  CRG_P4_DLL_SRST_REQ	(1 << 1)
#define PERI_CRG_MMC_DRV_DLL	(CRG_REG_BASE + 0x34c8)
#define  CRG_DRV_PHASE_SEL_SHIFT	15
#define  CRG_DRV_PHASE_SEL_MASK	(0x1F << 15)
#define PERI_CRG_MMC_STAT	(CRG_REG_BASE + 0x34d8)
#define  CRG_SAM_DLL_READY	(1 << 12)
#define  CRG_DS_DLL_READY	(1 << 10)
#define  CRG_P4_DLL_LOCKED	(1 << 9)
#define REG_EMMC_SAMPL_DLL_STATUS	PERI_CRG_MMC_STAT
#define REG_SDIO0_SAMPL_DLL_STATUS	PERI_CRG_MMC_STAT
#define  SDIO_SAMPL_DLL_SLAVE_READY	CRG_SAM_DLL_READY
#define REG_EMMC_DRV_DLL_CTRL		PERI_CRG_MMC_DRV_DLL
#define REG_SDIO0_DRV_DLL_CTRL		PERI_CRG_MMC_DRV_DLL
#define  SDIO_DRV_PHASE_SEL_MASK	CRG_DRV_PHASE_SEL_MASK
#define  sdio_drv_sel(phase)		((phase) << CRG_DRV_PHASE_SEL_SHIFT)
#define REG_EMMC_SAMPLB_DLL_CTRL	0x34d4
#define SDIO_SAMPLB_DLL_CLK_MASK	0xf
#define sdio_samplb_sel(phase)		(((phase) & 0xf) << 0)
#define REG_IO_CFG_BASE		0x10FF0000
#define REG_MMC_D0_IO		0xd0
#define REG_MMC_D1_IO		0xd4
#define REG_MMC_D2_IO		0xd8
#define REG_MMC_D3_IO		0xdc
#define REG_MMC_CLK_IO		0xc8
#define REG_MMC_CMD_IO		0xcc
#define REG_MMC_RST_IO		0xc4
#define REG_MMC_D4_IO		0xec
#define REG_MMC_D6_IO		0xf0
#define REG_MMC_D5_IO		0xe0
#define REG_MMC_D7_IO		0xe4
#define REG_MMC_DQS_IO		0xf4
#define  IO_CFG_DRV_STR_MASK		(0xf << 4)
#define  io_cfg_drv_str_sel(str)	((str) << 4)
#define  IO_CFG_PULL_UP			(0x1 << 8)
#define  IO_CFG_PULL_DOWN		(0x1 << 9)
#define  IO_CFG_SR			(0x1 << 10)
#define  IO_CFG_SDIO_MASK		(IO_CFG_DRV_STR_MASK | IO_CFG_PULL_UP |\
#define MMC_IO_MUX			0x1
#define SD_IO_MUX			0x2
#define IO_MUX_MASK			0x3
#define MMC_BUS_WIDTH_4_BIT		4
#define MMC_BUS_WIDTH_8_BIT		8
#define BOOT_FROM_NAND_FLAG		(0x1  << 2)
#define BOOT_FLAG_MASK			(0x3  << 2)
#define EMMC_BOOT_8BIT			(0x1  << 11)
#define IO_CLK				0
#define IO_CMD				1
#define IO_DATA				2
#define IO_RST				3
#define IO_DS				4
#define EMMC_IO_TYPE_NUM		5
#define CLK_400K	400000
#define CLK_24P75M	24750000
#define CLK_49P5M	49500000
#define CLK_99M		99000000
#define CLK_148P5M	148500000
#define DRIVE		0
#define SAMPLE		1
#define PHASE_TYPE_NUM	2
#ifdef CONFIG_TARGET_HI3521DV200
#else /* CONFIG_TARGET_HI3520DV500 */
#endif
#define DEVICE_TYPE_EMMC	1
#define DEVICE_TYPE_SD	0
