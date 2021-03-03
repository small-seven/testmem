#include "adc_drv.h"
#include <hi_boot_rom.h>
#define hi_reg_getbits16(addr, pos, bits) ((hi_reg_read_val16(addr) >> (pos)) & (((unsigned short)1 << (bits)) - 1))
#define GLB_CTL_REFCLK_FEQ_START_BIT       0
#define GLB_CTL_REFCLK_FEQ_BITS            1
