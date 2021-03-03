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
#define DDR_REFRESH(x)          ((x) & 0x3ff)
#define DDR_REFRESH_VAL_25M     (DDR_REFRESH_EN | DDR_REFRESH(390))
#define DDR_REFRESH_VAL_40M     (DDR_REFRESH_EN | DDR_REFRESH(624))
#define DDR_TRAS_S              0
#define DDR_TRAS_M              0x1f
#define DDR_TRAS(x)             ((x) << DDR_TRAS_S)
#define DDR_TRCD_M              0xf
#define DDR_TRCD_S              5
#define DDR_TRCD(x)             ((x) << DDR_TRCD_S)
#define DDR_TRP_M               0xf
#define DDR_TRP_S               9
#define DDR_TRP(x)              ((x) << DDR_TRP_S)
#define DDR_TRRD_M              0xf
#define DDR_TRRD_S              13
#define DDR_TRRD(x)             ((x) << DDR_TRRD_S)
#define DDR_TRFC_M              0x7f
#define DDR_TRFC_S              17
#define DDR_TRFC(x)             ((x) << DDR_TRFC_S)
#define DDR_TMRD_M              0xf
#define DDR_TMRD_S              23
#define DDR_TMRD(x)             ((x) << DDR_TMRD_S)
#define DDR_CAS_L_M             0x17
#define DDR_CAS_L_S             27
#define DDR_CAS_L(x)            (((x) & DDR_CAS_L_M) << DDR_CAS_L_S)
#define DDR_OPEN                BIT(30)
#define DDR_CONF_REG_VAL        (DDR_TRAS(16) | DDR_TRCD(6) | \
#define DDR_BURST_LEN_S         0
#define DDR_BURST_LEN_M         0xf
#define DDR_BURST_LEN(x)        ((x) << DDR_BURST_LEN_S)
#define DDR_BURST_TYPE          BIT(4)
#define DDR_CNTL_OE_EN          BIT(5)
#define DDR_PHASE_SEL           BIT(6)
#define DDR_CKE                 BIT(7)
#define DDR_TWR_S               8
#define DDR_TWR_M               0xf
#define DDR_TWR(x)              ((x) << DDR_TWR_S)
#define DDR_TRTW_S              12
#define DDR_TRTW_M              0x1f
#define DDR_TRTW(x)             ((x) << DDR_TRTW_S)
#define DDR_TRTP_S              17
#define DDR_TRTP_M              0xf
#define DDR_TRTP(x)             ((x) << DDR_TRTP_S)
#define DDR_TWTR_S              21
#define DDR_TWTR_M              0x1f
#define DDR_TWTR(x)             ((x) << DDR_TWTR_S)
#define DDR_G_OPEN_L_S          26
#define DDR_G_OPEN_L_M          0xf
#define DDR_G_OPEN_L(x)         ((x) << DDR_G_OPEN_L_S)
#define DDR_HALF_WIDTH_LOW      BIT(31)
#define DDR_CONF2_REG_VAL       (DDR_BURST_LEN(8) | DDR_CNTL_OE_EN | \
#define DDR2_CONF_TWL_S         10
#define DDR2_CONF_TWL_M         0xf
#define DDR2_CONF_TWL(x)        (((x) & DDR2_CONF_TWL_M) << DDR2_CONF_TWL_S)
#define DDR2_CONF_ODT           BIT(9)
#define DDR2_CONF_TFAW_S        2
#define DDR2_CONF_TFAW_M        0x3f
#define DDR2_CONF_TFAW(x)       (((x) & DDR2_CONF_TFAW_M) << DDR2_CONF_TFAW_S)
#define DDR2_CONF_EN            BIT(0)
#define DDR2_CONF_VAL           (DDR2_CONF_TWL(2) | DDR2_CONF_ODT | \
#define DDR1_EXT_MODE_VAL       0x02
#define DDR2_EXT_MODE_VAL       0x402
#define DDR2_EXT_MODE_OCD_VAL   0x382
#define DDR1_MODE_DLL_VAL       0x133
#define DDR2_MODE_DLL_VAL       0x100
#define DDR1_MODE_VAL           0x33
#define DDR2_MODE_VAL           0xa33
#define DDR_TAP_VAL0            0x08
#define DDR_TAP_VAL1            0x09
