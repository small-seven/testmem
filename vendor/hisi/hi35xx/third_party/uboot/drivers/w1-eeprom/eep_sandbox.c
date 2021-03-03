#include <common.h>
#include <linux/err.h>
#include <dm.h>
#include <w1-eeprom.h>
#include <w1.h>
#define W1_F2D_READ_EEPROM      0xf0
#define EEP_SANDBOX_SAMPLE_MEM "this is a sample EEPROM memory string."
