#include <upg_check_secure.h>
#include <brain_pool_p256r1.h>
#include <hi_efuse.h>
#include <upg_common.h>
#if defined(CONFIG_FLASH_ENCRYPT_SUPPORT)
#include "kernel_crypto.h"
#endif
#if defined(CONFIG_FLASH_ENCRYPT_SUPPORT) && (!defined(CONFIG_COMPRESSION_OTA_SUPPORT))
#else
#endif
#if (defined(CONFIG_FLASH_ENCRYPT_SUPPORT)) && (!defined(CONFIG_COMPRESSION_OTA_SUPPORT))
#endif
