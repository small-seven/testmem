#include "hisoc/usb3.h"
#include "linux/delay.h"
#include "board.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define USB2_CTRL               IO_ADDRESS(CRG_REG_BASE + 0x140)
#define USB2_CRG_DEFAULT_VAL    0x3B2F
#define USB2_UTMI_CKEN          (0x1U << 12)
#define USB2_PHY_APB_CKEN       (0x1U << 11)
#define USB2_REF_CKEN           (0x1U << 9)
#define USB2_BUS_CKEN           (0x1U << 8)
#define USB2_PHY_PLL_CKEN       (0x1U << 4)
#define USB2_PHY_XTAL_CKEN      (0x1U << 2)
#define USB2_FREECLK_CKSEL      (0x1U << 13)
#define USB2_PHY_APB_RST        (0x1U << 10)
#define USB2_VCC_SRST_REQ       (0x1U << 3)
#define USB2_PHY_REQ            (0x1U << 0)
#define USB2_PHY_PORT_TREQ      (0x1U << 1)
#define CTRL_BASE_REG           IO_DEVICE_ADDR(0x10030000)
#define GTXTHRCFG               IO_ADDRESS(CTRL_BASE_REG + 0xC108)
#define GRXTHRCFG               IO_ADDRESS(CTRL_BASE_REG + 0xC10C)
#define REG_GCTL                IO_ADDRESS(CTRL_BASE_REG + 0xC110)
#define REG_GUSB3PIPECTL0       IO_ADDRESS(CTRL_BASE_REG + 0xC2C0)
#define PCS_SSP_SOFT_RESET      (0x1U << 31)
#define PORT_CAP_DIR            (0x3U << 12)
#define PORT_SET_HOST           (0x1U << 12)
#define PORT_SET_DEVICE         (0x1U << 13)
#define PORT_DISABLE_SUSPEND    (0x1U << 17)
#define USB2_G_TXTHRCFG         0x23100000
#define USB2_G_RXTHRCFG         0x23100000
#define USB2_PHY_BASE_REG       IO_DEVICE_ADDR(0x100D0000)
#define RG_PLL_EN_MASK          0x0003U
#define RG_PLL_EN_VAL           0x0003U
#define RG_PLL_OFFSET           0x0014
#define USB2_VBUS_IO_BASE_REG   IO_DEVICE_ADDR(0x100C0000)
#define USB2_VBUS_IO_OFFSET     0x7C
#define USB_VBUS_IO_CONFIG_VAL  0x0531
#define USB_PWREN_CONFIG_REG    IO_DEVICE_ADDR(0x100C0080)
#define USB_PWREN_CONFIG_VAL    0x1
#define HIXVP_PHY_ANA_CFG_0_OFFSET          0x00
#define HIXVP_PHY_PRE_DRIVE_MASK            (0xFU << 24)
#define HIXVP_PHY_PRE_DRIVE_VAL             (0x4U << 24)
#define HIXVP_PHY_ANA_CFG_2_OFFSET          0x08
#define HIXVP_PHY_TX_TEST_BIT               (0x1U << 20)
#define HIXVP_PHY_DISCONNECT_REFERENCE_MASK (0x7U << 16)
#define HIXVP_PHY_DISCONNECT_REFERENCE_VAL  (0x2U << 16)
#define HIXVP_PHY_ANA_CFG_4_OFFSET          0x10
#define HIXVP_PHY_TX_REFERENCE_MASK         (0x7U << 4)
#define HIXVP_PHY_TX_REFERENCE_VAL          (0x5U << 4)
#define HIXVP_PHY_SQUELCH_MASK              (0x7U << 0)
#define HIXVP_PHY_SQUELCH_VAL               (0x5U << 0)
#define USB_TRIM_BASE_REG                   IO_DEVICE_ADDR(0x12028004)
#define USB_TRIM_VAL_MASK                   0x001FU
#define USB_TRIM_VAL_MIN                    0x0009
#define USB_TRIM_VAL_MAX                    0x001D
#define USB2_TRIM_OFFSET                    0x0008
#define USB2_TRIM_MASK                      0x1F00U
#define USB2_TRIM_VAL(a)                    (((a) << 8) & USB2_TRIM_MASK)
#define USB2_TRIM_DEFAULT_VAL               0x000EU
#define USB_SVB_BASE_REG                    IO_DEVICE_ADDR(0x12020158)
#define USB_SVB_OFFSET                      0x00
#define USB_SVB_MASK                        (0x0FU << 24)
#define USB_SVB_PREDEV_5_MIN                0x2BC
#define USB_SVB_PREDEV_5_MAX_4_MIN          0x32A
#define USB_SVB_PREDEV_4_MAX_3_MIN          0x398
#define USB_SVB_PREDEV_3_MAX_2_MIN          0x3CA
#define USB_SVB_PREDEV_2_MAX                0x44C
#define USB_SVB_PREDEV_5_PHY_VAL            (0x05U << 24)
#define USB_SVB_PREDEV_4_PHY_VAL            (0x04U << 24)
#define USB_SVB_PREDEV_3_PHY_VAL            (0x03U << 24)
#define USB_SVB_PREDEV_2_PHY_VAL            (0x02U << 24)
#define VBUS_CONFIG_WAIT_TIME               20
#define CTRL_CONFIG_WAIT_TIME               20
#define MODE_SWITCH_WAIT_TIME               20
#define USB_PHY_OFF_WAIT_TIME               2000
#define PLL_CONFIG_WAIT_TIME                2000
#define USB2_CTRL_CONFIG_WAIT_TIME          200
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
