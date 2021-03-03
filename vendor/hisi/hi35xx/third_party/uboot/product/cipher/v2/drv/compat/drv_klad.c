#include "cipher_adapt.h"
#include "hal_otp.h"
#define KLAD_REG_BASE_ADDR                      g_klad_base
#define KLAD_REG_KLAD_CTRL                      (KLAD_REG_BASE_ADDR + 0x00)
#define KLAD_REG_DAT_IN                         (KLAD_REG_BASE_ADDR + 0x10)
#define KLAD_REG_ENC_OUT                        (KLAD_REG_BASE_ADDR + 0x20)
#define KLAD_KEY_LEN                            4
#define CIPHER_WAIT_IDEL_TIMES                  1000
