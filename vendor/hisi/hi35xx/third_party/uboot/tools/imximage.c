#include "imagetool.h"
#include <image.h>
#include "imximage.h"
#include <generated/autoconf.h>
#define UNDEFINED 0xFFFFFFFF
#if !defined(CONFIG_IMX_DCD_ADDR)
#define CONFIG_IMX_DCD_ADDR 0x00910000
#endif
