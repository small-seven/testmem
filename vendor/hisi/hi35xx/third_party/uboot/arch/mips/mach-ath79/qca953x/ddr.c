#include <common.h>
#include <asm/io.h>
#include <asm/addrspace.h>
#include <asm/types.h>
#include <mach/ar71xx_regs.h>
#include <mach/ath79.h>
#define DDR_CTRL_UPD_EMR3S      BIT(5)
#define DDR_CTRL_UPD_EMR2S      BIT(4)
#define DDR_CTRL_PRECHARGE      BIT(3)
#define DDR_CTRL_AUTO_REFRESH   BIT(2)
#define DDR_CTRL_UPD_EMRS       BIT(1)
#define DDR_CTRL_UPD_MRS        BIT(0)
#define DDR_REFRESH_EN          BIT(14)
#define DDR_REFRESH_M           0x3ff
#define DDR_REFRESH(x)          ((x) & DDR_REFRESH_M)
#define DDR_REFRESH_VAL         (DDR_REFRESH_EN | DDR_REFRESH(312))
#define DDR_TRAS_S              0
#define DDR_TRAS_M              0x1f
#define DDR_TRAS(x)             (((x) & DDR_TRAS_M) << DDR_TRAS_S)
#define DDR_TRCD_M              0xf
#define DDR_TRCD_S              5
#define DDR_TRCD(x)             (((x) & DDR_TRCD_M) << DDR_TRCD_S)
#define DDR_TRP_M               0xf
#define DDR_TRP_S               9
#define DDR_TRP(x)              (((x) & DDR_TRP_M) << DDR_TRP_S)
#define DDR_TRRD_M              0xf
#define DDR_TRRD_S              13
#define DDR_TRRD(x)             (((x) & DDR_TRRD_M) << DDR_TRRD_S)
#define DDR_TRFC_M              0x7f
#define DDR_TRFC_S              17
#define DDR_TRFC(x)             (((x) & DDR_TRFC_M) << DDR_TRFC_S)
#define DDR_TMRD_M              0xf
#define DDR_TMRD_S              23
#define DDR_TMRD(x)             (((x) & DDR_TMRD_M) << DDR_TMRD_S)
#define DDR_CAS_L_M             0x17
#define DDR_CAS_L_S             27
#define DDR_CAS_L(x)            (((x) & DDR_CAS_L_M) << DDR_CAS_L_S)
#define DDR_OPEN                BIT(30)
#define DDR1_CONF_REG_VAL       (DDR_TRAS(16) | DDR_TRCD(6) | \
#define DDR2_CONF_REG_VAL       (DDR_TRAS(27) | DDR_TRCD(9) | \
#define DDR_BURST_LEN_S         0
#define DDR_BURST_LEN_M         0xf
#define DDR_BURST_LEN(x)        ((x) << DDR_BURST_LEN_S)
#define DDR_BURST_TYPE          BIT(4)
#define DDR_CNTL_OE_EN          BIT(5)
#define DDR_PHASE_SEL           BIT(6)
#define DDR_CKE                 BIT(7)
#define DDR_TWR_S               8
#define DDR_TWR_M               0xf
#define DDR_TWR(x)              (((x) & DDR_TWR_M) << DDR_TWR_S)
#define DDR_TRTW_S              12
#define DDR_TRTW_M              0x1f
#define DDR_TRTW(x)             (((x) & DDR_TRTW_M) << DDR_TRTW_S)
#define DDR_TRTP_S              17
#define DDR_TRTP_M              0xf
#define DDR_TRTP(x)             (((x) & DDR_TRTP_M) << DDR_TRTP_S)
#define DDR_TWTR_S              21
#define DDR_TWTR_M              0x1f
#define DDR_TWTR(x)             (((x) & DDR_TWTR_M) << DDR_TWTR_S)
#define DDR_G_OPEN_L_S          26
#define DDR_G_OPEN_L_M          0xf
#define DDR_G_OPEN_L(x)         ((x) << DDR_G_OPEN_L_S)
#define DDR_HALF_WIDTH_LOW      BIT(31)
#define DDR1_CONF2_REG_VAL      (DDR_BURST_LEN(8) | DDR_CNTL_OE_EN | \
#define DDR2_CONF2_REG_VAL      (DDR_BURST_LEN(8) | DDR_CNTL_OE_EN | \
#define DDR_TWR_MSB             BIT(3)
#define DDR_TRAS_MSB            BIT(2)
#define DDR_TRFC_MSB_M          0x3
#define DDR_TRFC_MSB(x)         (x)
#define DDR1_CONF3_REG_VAL      0
#define DDR2_CONF3_REG_VAL      (DDR_TWR_MSB | DDR_TRFC_MSB(2))
#define DDR_CTL_SRAM_TSEL       BIT(30)
#define DDR_CTL_SRAM_GE0_SYNC   BIT(20)
#define DDR_CTL_SRAM_GE1_SYNC   BIT(19)
#define DDR_CTL_SRAM_USB_SYNC   BIT(18)
#define DDR_CTL_SRAM_PCIE_SYNC  BIT(17)
#define DDR_CTL_SRAM_WMAC_SYNC  BIT(16)
#define DDR_CTL_SRAM_MISC1_SYNC BIT(15)
#define DDR_CTL_SRAM_MISC2_SYNC BIT(14)
#define DDR_CTL_PAD_DDR2_SEL    BIT(6)
#define DDR_CTL_HALF_WIDTH      BIT(1)
#define DDR_CTL_CONFIG_VAL      (DDR_CTL_SRAM_TSEL | \
#define DDR_BURST_GE0_MAX_BL_S  0
#define DDR_BURST_GE0_MAX_BL_M  0xf
#define DDR_BURST_GE0_MAX_BL(x) \
#define DDR_BURST_GE1_MAX_BL_S  4
#define DDR_BURST_GE1_MAX_BL_M  0xf
#define DDR_BURST_GE1_MAX_BL(x) \
#define DDR_BURST_PCIE_MAX_BL_S 8
#define DDR_BURST_PCIE_MAX_BL_M 0xf
#define DDR_BURST_PCIE_MAX_BL(x) \
#define DDR_BURST_USB_MAX_BL_S  12
#define DDR_BURST_USB_MAX_BL_M  0xf
#define DDR_BURST_USB_MAX_BL(x) \
#define DDR_BURST_CPU_MAX_BL_S  16
#define DDR_BURST_CPU_MAX_BL_M  0xf
#define DDR_BURST_CPU_MAX_BL(x) \
#define DDR_BURST_RD_MAX_BL_S   20
#define DDR_BURST_RD_MAX_BL_M   0xf
#define DDR_BURST_RD_MAX_BL(x) \
#define DDR_BURST_WR_MAX_BL_S   24
#define DDR_BURST_WR_MAX_BL_M   0xf
#define DDR_BURST_WR_MAX_BL(x) \
#define DDR_BURST_RWP_MASK_EN_S 28
#define DDR_BURST_RWP_MASK_EN_M 0x3
#define DDR_BURST_RWP_MASK_EN(x) \
#define DDR_BURST_CPU_PRI_BE    BIT(30)
#define DDR_BURST_CPU_PRI       BIT(31)
#define DDR_BURST_VAL           (DDR_BURST_CPU_PRI_BE | \
#define DDR_BURST_WMAC_MAX_BL_S 0
#define DDR_BURST_WMAC_MAX_BL_M 0xf
#define DDR_BURST_WMAC_MAX_BL(x) \
#define DDR_BURST2_VAL          DDR_BURST_WMAC_MAX_BL(4)
#define DDR2_CONF_TWL_S         10
#define DDR2_CONF_TWL_M         0xf
#define DDR2_CONF_TWL(x) \
#define DDR2_CONF_ODT           BIT(9)
#define DDR2_CONF_TFAW_S        2
#define DDR2_CONF_TFAW_M        0x3f
#define DDR2_CONF_TFAW(x) \
#define DDR2_CONF_EN            BIT(0)
#define DDR2_CONF_VAL           (DDR2_CONF_TWL(5) | \
#define DDR1_EXT_MODE_VAL       0
#define DDR2_EXT_MODE_VAL       0x402
#define DDR2_EXT_MODE_OCD_VAL   0x782
#define DDR1_MODE_DLL_VAL       0x133
#define DDR2_MODE_DLL_VAL       0x143
#define DDR1_MODE_VAL           0x33
#define DDR2_MODE_VAL           0x43
#define DDR1_TAP_VAL            0x20
#define DDR2_TAP_VAL            0x10
#define DDR_REG_BIST_MASK_ADDR_0        0x2c
#define DDR_REG_BIST_MASK_ADDR_1        0x30
#define DDR_REG_BIST_MASK_AHB_GE0_0     0x34
#define DDR_REG_BIST_COMP_AHB_GE0_0     0x38
#define DDR_REG_BIST_MASK_AHB_GE1_0     0x3c
#define DDR_REG_BIST_COMP_AHB_GE1_0     0x40
#define DDR_REG_BIST_COMP_ADDR_0        0x64
#define DDR_REG_BIST_COMP_ADDR_1        0x68
#define DDR_REG_BIST_MASK_AHB_GE0_1     0x6c
#define DDR_REG_BIST_COMP_AHB_GE0_1     0x70
#define DDR_REG_BIST_MASK_AHB_GE1_1     0x74
#define DDR_REG_BIST_COMP_AHB_GE1_1     0x78
#define DDR_REG_BIST                    0x11c
#define DDR_REG_BIST_STATUS             0x120
#define DDR_BIST_COMP_CNT_S     1
#define DDR_BIST_COMP_CNT_M     0xff
#define DDR_BIST_COMP_CNT(x) \
#define DDR_BIST_COMP_CNT_MASK \
#define DDR_BIST_TEST_START     BIT(0)
#define DDR_BIST_STATUS_DONE    BIT(0)
#define DDR_BIST_MASK_ADDR_VAL  0xfa5de83f
#define DDR_TAP_MAGIC_VAL       0xaa55aa55
#define DDR_TAP_MAX_VAL         0x40
