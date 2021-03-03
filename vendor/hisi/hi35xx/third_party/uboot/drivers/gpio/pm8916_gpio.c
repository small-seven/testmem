#include <common.h>
#include <dm.h>
#include <power/pmic.h>
#include <spmi/spmi.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <linux/bitops.h>
#define REG_OFFSET(x)          ((x) * 0x100)
#define REG_TYPE               0x4
#define REG_SUBTYPE            0x5
#define REG_STATUS             0x08
#define REG_STATUS_VAL_MASK    0x1
#define REG_CTL		0x40
#define REG_CTL_MODE_MASK       0x70
#define REG_CTL_MODE_INPUT      0x00
#define REG_CTL_MODE_INOUT      0x20
#define REG_CTL_MODE_OUTPUT     0x10
#define REG_CTL_OUTPUT_MASK     0x0F
#define REG_DIG_VIN_CTL        0x41
#define REG_DIG_VIN_VIN0       0
#define REG_DIG_PULL_CTL       0x42
#define REG_DIG_PULL_NO_PU     0x5
#define REG_DIG_OUT_CTL        0x45
#define REG_DIG_OUT_CTL_CMOS   (0x0 << 4)
#define REG_DIG_OUT_CTL_DRIVE_L 0x1
#define REG_EN_CTL             0x46
#define REG_EN_CTL_ENABLE      (1 << 7)
#define PON_INT_RT_STS                        0x10
#define KPDPWR_ON_INT_BIT                     0
#define RESIN_ON_INT_BIT                      1
