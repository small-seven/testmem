#include <common.h>
#include <linux/errno.h>
#include "crypto.h"
#include "uboot_aes.h"
#define AES_CMAC_CONST_RB 0x87  /* from RFC 4493, Figure 2.2 */
