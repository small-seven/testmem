#define EMMC_PHY_INIT_CTRL      (EMMC_PHY_BASE + 0x4)
#define PHY_INIT_EN             BIT(0)
#define PHY_DLYMEAS_EN          BIT(2)
#define PHY_ZCAL_EN             BIT(3)
#define EMMC_PHY_DLY_CTL1       (EMMC_PHY_BASE + 0x254)
#define PHY_INV_CLK             BIT(31)
#define EMMC_PHY_IOCTL_PUPD     (EMMC_PHY_BASE + 0x260)
#define RG_EMMC_PUPD_EN         0x7ff
#define RG_EMMC_PULL_UP         0x2ff
#define EMMC_PHY_IOCTL_RONSEL_1_0   (EMMC_PHY_BASE + 0x264)
#define RG_EMMC_RONSEL1             0x7ff
#define RG_EMMC_RONSEL0             0x7ff
#define EMMC_PHY_IOCTL_OD_RONSEL_2  (EMMC_PHY_BASE + 0x268)
#define EMMC_PHY_IOCTL_IOE      (EMMC_PHY_BASE + 0x26c)
#define DA_EMMC_IE              0x7ff
#define DA_EMMC_E               0x6ff
#define EMMC_RSTN_PULL_UP_EN	BIT(8)
#define PIN_SEL_EMMC_FUNC	0x1
#define PIN_SEL_EMMC_POWER_EN	0x2
#define REG_PERI_STAT	(SYS_CTRL_REG_BASE + 0x30)
#define EMMC_PULL_UP_DISABLE    BIT(13)
#define REG_MISC_CTRL17         (MISC_REG_BASE + MISC_CTRL17)
#define REG_MISC_CTRL18         (MISC_REG_BASE + MISC_CTRL18)
#define SDIO0_PWRSW_SEL_1V8		BIT(5)
#define SDIO0_PWR_EN			BIT(4)
#define SDIO0_IO_MODE_SEL_1V8	BIT(1)
#define SDIO0_PWR_CTRL_BY_MISC  BIT(0)
#define SDIO_SAMPL_DLL_SRST_REQ	(0x1 << 30)
#define SDIO_DRV_DLL_SRST_REQ	(0x1 << 29)
#define SDIO_CLK_EN		(0x1 << 28)
#define SDIO_SRST_REQ	(0x1 << 27)
#define REG_EMMC_DRV_DLL_CTRL	(CRG_REG_BASE + 0x1b0)
#define REG_SDIO0_DRV_DLL_CTRL  (CRG_REG_BASE + 0x1d4)
#define SDIO_DRV_PHASE_SEL_MASK (0x1f << 24)
#define sdio_drv_sel(phase)     ((phase) << 24)
#define REG_EMMC_DS_DLL_CTRL		(CRG_REG_BASE + 0x1b4)
#define EMMC_DS_DLL_MODE_SSEL       BIT(13)
#define EMMC_DS_DLL_SSEL_MASK       0x1fff
#define REG_EMMC_DS180_DLL_CTRL     (CRG_REG_BASE + 0x1b8)
#define EMMC_DS180_DLL_BYPASS       BIT(15)
#define REG_EMMC_DS_DLL_STATUS      (CRG_REG_BASE + 0x1c8)
#define EMMC_DS_DLL_LOCK            BIT(15)
#define EMMC_DS_DLL_MDLY_TAP_MASK   0x1fff
#define REG_EMMC_DRV_DLL_STATUS     (CRG_REG_BASE + 0x1c4)
#define REG_SDIO0_DRV_DLL_STATUS    (CRG_REG_BASE + 0x1e8)
#define SDIO_DRV_DLL_LOCK           BIT(15)
#define REG_EMMC_SAMPL_DLL_CTRL     (CRG_REG_BASE + 0x1a8)
#define REG_SDIO0_SAMPL_DLL_CTRL    (CRG_REG_BASE + 0x1ec)
#define SDIO_SAMPL_DLL_SLAVE_EN     BIT(16)
#define REG_EMMC_SAMPL_DLL_STATUS   (CRG_REG_BASE + 0x1bc)
#define REG_SDIO0_SAMPL_DLL_STATUS  (CRG_REG_BASE + 0x1e0)
#define SDIO_SAMPL_DLL_SLAVE_READY  BIT(14)
#define REG_EMMC_SAMPLB_DLL_CTRL    0x1ac
#define SDIO_SAMPLB_DLL_CLK_MASK    (0x1f << 24)
#define sdio_samplb_sel(phase)      ((phase) << 24)
#define REG_IO_CFG_0_BASE		0x04058000
#define EMMC_MUXCTRL_REG_START  0x8c    /* iocfg_reg35 */
#define EMMC_MUXCTRL_REG_END    0xbc    /* iocfg_reg47 */
#define IO_CFG_REG46            0xb8
#define IO_CFG_REG47            0xbc
#define REG_BASE_MISC			0x04528000
#define DRV50_VAL				0x000
#define BIT_RG_EMMC_LHEN_IN		(0x3f << 17)
#define BIT_EMMC_ISO_EN			(0x1 << 16)
#define DRV50_NO_OD_VAL			0xfff
#define PERI_CRG_EMMC			0x1a8
#define MMC_CLK_SEL_SHIFT		24
#define MMC_RST				(0x1 << 27)
#define MMC_CLK_EN			(0x1 << 28)
#define MMC_DRV_DLL_RST			(0x1 << 29)
#define MMC_SAM_DLL_RST			(0x1 << 30)
#define MMC_DRV_PHASE_MASK		(0x1f << 24)
#define SW_TUNING_EN			(0x1 << 4)
#define MMC_CLK_50M			0x2
#define SW_TUNING_45			0x4
#define SW_TUNING_0			0x0
#define PERI_EMMC_DRV_DLL		0x1c4
#define CLK_100K	100000
#define CLK_400K	400000
#define CLK_25M		25000000
#define CLK_49P5M	50000000
#define CLK_99M		99000000
#define CLK_150M	150000000
#define CLK_187P5M	187000000
#define CLK_198M	198000000
#define SHIFT_16 	16
