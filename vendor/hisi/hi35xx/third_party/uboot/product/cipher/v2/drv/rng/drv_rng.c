#include "cipher_adapt.h"
#define REG_RNG_BASE_ADDR                   g_rng_reg_base
#define HISEC_COM_TRNG_CTRL                 (REG_RNG_BASE_ADDR + 0x200)
#define HISEC_COM_TRNG_FIFO_DATA            (REG_RNG_BASE_ADDR + 0x204)
#define HISEC_COM_TRNG_DATA_ST              (REG_RNG_BASE_ADDR + 0x208)
