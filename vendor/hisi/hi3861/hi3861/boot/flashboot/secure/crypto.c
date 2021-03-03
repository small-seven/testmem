#ifdef CONFIG_FLASH_ENCRYPT_SUPPORT
#include <hi_cipher.h>
#include "crypto.h"
#include <boot_upg_check.h>
#include <boot_upg_start_up.h>
#if defined(CONFIG_COMPRESSION_OTA_SUPPORT)
#endif
#ifdef CONFIG_FACTORY_TEST_SUPPORT
#else
#endif
#if !defined(CONFIG_COMPRESSION_OTA_SUPPORT)
#else
#endif
#endif
