#include <common.h>
#include <dm.h>
#include <regmap.h>
#include <syscon.h>
#include <dm/pinctrl.h>
#define BCM6838_CMD_LOAD_MUX            0x21
#define BCM6838_FUNC_OFFS               12
#define BCM6838_FUNC_MASK               (0x37 << BCM6838_FUNC_OFFS)
#define BCM6838_PIN_OFFS                 0
#define BCM6838_PIN_MASK                (0xfff << BCM6838_PIN_OFFS)
#define BCM6838_MAX_PIN_NAME_LEN         8
#define BCM6838_MAX_FUNC_NAME_LEN        8
