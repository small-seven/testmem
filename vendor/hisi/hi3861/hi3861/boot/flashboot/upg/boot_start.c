#include "boot_start.h"
#include "boot_upg_kernel.h"
#include "boot_upg_check.h"
#include "boot_upg_check_secure.h"
#ifdef CONFIG_FLASH_ENCRYPT_SUPPORT
#include <crypto.h>
#endif
#define CRYPTO_FLASH_LENGTH 4096
#if defined(CONFIG_COMPRESSION_OTA_SUPPORT)
#else
#endif
#if defined(CONFIG_FLASH_ENCRYPT_SUPPORT)
#if defined(CONFIG_COMPRESSION_OTA_SUPPORT)
#else
#endif
#endif
#ifdef CONFIG_FLASH_ENCRYPT_SUPPORT
#endif
#if defined(CONFIG_COMPRESSION_OTA_SUPPORT)
#ifdef CONFIG_FLASH_ENCRYPT_SUPPORT
#endif
#endif
#ifdef CONFIG_FLASH_ENCRYPT_SUPPORT
#else
#endif
#if defined(CONFIG_COMPRESSION_OTA_SUPPORT)
#endif
#ifdef CONFIG_FLASH_ENCRYPT_SUPPORT
#endif
