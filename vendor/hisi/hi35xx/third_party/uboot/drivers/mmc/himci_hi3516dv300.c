#define REG_CRG82   0x0148
#define EMMC_CRG    REG_CRG82
#define EMMC_SRST   (1<<0)
#define EMMC_CLK_EN (1<<1)
#define EMMC_CLK_SEL_MASK   (0x3<<2)
#define EMMC_CLK_SEL_50M    0x2
#define EMMC_CLK_SEL_100M    0x1
#define EMMC_CLK_SEL_150M    0x0
#define EMMC_CLK_SEL_SHIFT  0x2
#define HIMCI_PHASE_SCALE       8
#define REG_CRG88   0x0160
#define SDIO0_CRG    REG_CRG88
#define SDIO0_SRST   (1<<0)
#define SDIO0_CLK_EN (1<<1)
#define SDIO0_CLK_SEL_MASK   (0x3<<2)
#define SDIO0_CLK_SEL_50M    0x2
#define SDIO0_CLK_SEL_SHIFT  0x2
#define REG_CTRL_EMMC_START     (0x10ff0000 + 0x0)
#define REG_CTRL_SDIO0_START	(0x10ff0000 + 0x24)
#define DRV_PHASE_180   (0x4<<23)
#define DRV_PHASE_135   (0x3<<23)
#define DRV_PHASE_90    (0x2<<23)
#define SMP_PHASE_45    (0x1<<16)
#define SMP_PHASE_0     (0x0<<16)
