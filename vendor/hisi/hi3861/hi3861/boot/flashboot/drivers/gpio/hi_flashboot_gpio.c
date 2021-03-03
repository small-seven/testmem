#include "hi_flashboot_gpio.h"
#include <hi_types.h>
#include <hi3861_platform.h>
#define GPIO_SWPORT_DR            0x00
#define GPIO_SWPORT_DDR           0x04
#define GPIO_INTEN                0x30
#define GPIO_INTMASK              0x34
#define GPIO_INTTYPE_LEVEL        0x38
#define GPIO_INT_POLARITY         0x3c
#define GPIO_INTSTATUS            0x40
#define GPIO_RAWINTSTATUS         0x44
#define GPIO_PORT_EOI             0x4c
#define GPIO_EXT_PORT             0x50
