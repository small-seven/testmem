#include "hisoc/usb3.h"
#include "los_atomic.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define USB3_CTRL_REG_BASE IO_DEVICE_ADDR(CONFIG_HIUSB_XHCI_IOBASE)
#define REG_USB2_CTRL      0x0140
#define USB2_UTMI_PCTRL         (0x1U << 15)
#define USB2_PHY_TEST_SRST_REQ  (0x1U << 14)
#define USB2_UTMI_CKSEL         (0x1U << 13)
#define USB2_UTMI_CKEN          (0x1U << 12)
#define USB2_REF_CKEN           (0x1U << 9)
#define USB2_BUS_CKEN           (0x1U << 8)
#define USB2_VCC_SRST_REQ       (0x1U << 3)
#define USB2_PHY_CKEN           (0x1U << 2)
#define USB2_PHY_PORT_TREQ      (0x1U << 1)
#define USB2_PHY_REQ            (0x1U << 0)
#define REG_GUSB3PIPECTL0       0xC2C0
#define PCS_SSP_SOFT_RESET      (0x1U << 31)
#define PORT_DISABLE_SUSPEND    (0x1U << 17)
#define REG_GCTL        0xC110
#define PORT_CAP_DIR    (0x3U << 12)
#define PORT_SET_HOST   (0x1U << 12)
#define PORT_SET_DEVICE (0x1U << 13)
#define GTXTHRCFG       0xC108
#define USB2_G_TXTHRCFG IO_DEVICE_ADDR(0x23100000)
#define GRXTHRCFG       0xC10C
#define USB2_G_RXTHRCFG IO_DEVICE_ADDR(0x23100000)
#define USB2_INNO_PHY_BASE_REG  IO_DEVICE_ADDR(0x10110000)
#define USB2_PHY_CLK_OUTPUT_REG 0x18
#define USB2_PHY_CLK_OUTPUT_VAL 0x0C
#define USB2_VBUS_IO_BASE_REG   IO_DEVICE_ADDR(0x10FF0000)
#define USB2_VBUS_IO_OFFSET     0x40
#define USB2_VBUS_IO_VAL        0x431
#define HS_HIGH_HEIGHT_TUNING_OFFSET    0x8
#define HS_HIGH_HEIGHT_TUNING_MASK      (0x7U << 4)
#define HS_HIGH_HEIGHT_TUNING_VAL       (0x5U << 4)
#define PRE_EMPHASIS_TUNING_OFFSET  0x0
#define PRE_EMPHASIS_TUNING_MASK    (0x7U << 0)
#define PRE_EMPHASIS_TUNING_VAL     (0x7U << 0)
#define PRE_EMPHASIS_STRENGTH_OFFSET    0x14
#define PRE_EMPHASIS_STRENGTH_MASK      (0x7U << 2)
#define PRE_EMPHASIS_STRENGTH_VAL       (0x3U << 2)
#define HS_SLEW_RATE_TUNING_OFFSET  0x74
#define HS_SLEW_RATE_TUNING_MASK    (0x7U << 1)
#define HS_SLEW_RATE_TUNING_VAL     (0x7U << 1)
#define DISCONNECT_TRIGGER_OFFSET   0x10
#define DISCONNECT_TRIGGER_MASK     (0xfU << 4)
#define DISCONNECT_TRIGGER_VAL      (0xdU << 4)
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
