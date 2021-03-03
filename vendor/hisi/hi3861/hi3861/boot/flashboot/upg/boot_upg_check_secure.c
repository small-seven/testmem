#include "boot_upg_check_secure.h"
#include <hi_flashboot.h>
#ifdef CONFIG_FLASH_ENCRYPT_SUPPORT
#include <crypto.h>
#endif
#include "boot_upg_tool.h"
#ifndef FLASHBOOT_KEY_SECTION
#define FLASHBOOT_KEY_SECTION       __attribute__ ((section(".boot.data.key")))
#endif
#if (defined(CONFIG_TARGET_SIG_RSA_V15) || defined(CONFIG_TARGET_SIG_RSA_PSS))
#endif
#if defined(CONFIG_TARGET_SIG_ECC)
#endif
#if (defined(CONFIG_TARGET_SIG_RSA_V15) || defined(CONFIG_TARGET_SIG_RSA_PSS))
#endif
#if defined(CONFIG_TARGET_SIG_ECC)
#endif
#if (defined(CONFIG_TARGET_SIG_RSA_V15) || defined(CONFIG_TARGET_SIG_RSA_PSS))
#endif
#if defined(CONFIG_TARGET_SIG_ECC)
#endif
#if defined(CONFIG_TARGET_SIG_ECC)
#endif
#if (defined(CONFIG_TARGET_SIG_RSA_V15) || defined(CONFIG_TARGET_SIG_RSA_PSS))
#endif
#if defined(CONFIG_TARGET_SIG_ECC)
#endif
#if (defined(CONFIG_TARGET_SIG_RSA_V15) || defined(CONFIG_TARGET_SIG_RSA_PSS))
#endif
#if defined(CONFIG_FLASH_ENCRYPT_SUPPORT)
#else
#endif
#if defined(CONFIG_FLASH_ENCRYPT_SUPPORT)
#else
#endif
