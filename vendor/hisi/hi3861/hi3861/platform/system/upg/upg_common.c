#include <upg_common.h>
#include <upg_check_file.h>
#include <upg_check_secure.h>
#include <upg_start_up.h>
#include <upg_check_boot_bin.h>
#include <upg_ver_update.h>
#include <flash_prv.h>
#if defined(CONFIG_FLASH_ENCRYPT_SUPPORT)
#include "kernel_crypto.h"
#endif
#if defined(CONFIG_COMPRESSION_OTA_SUPPORT)
#else
#endif
#if defined(CONFIG_COMPRESSION_OTA_SUPPORT)
#else
#endif
#if defined(CONFIG_COMPRESSION_OTA_SUPPORT)
#else
#endif
#if defined(CONFIG_COMPRESSION_OTA_SUPPORT)
#else
#endif
#if (defined(CONFIG_FLASH_ENCRYPT_SUPPORT)) && (!defined(CONFIG_COMPRESSION_OTA_SUPPORT))
#else
#endif
#if defined(CONFIG_COMPRESSION_OTA_SUPPORT)
#else
#endif
#if defined(CONFIG_COMPRESSION_OTA_SUPPORT)
#else
#endif
