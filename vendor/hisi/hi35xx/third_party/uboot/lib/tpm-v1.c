#define LOG_CATEGORY UCLASS_TPM
#include <common.h>
#include <dm.h>
#include <asm/unaligned.h>
#include <u-boot/sha1.h>
#include <tpm-common.h>
#include <tpm-v1.h>
#include "tpm-utils.h"
#ifdef CONFIG_TPM_AUTH_SESSIONS
#ifndef CONFIG_SHA1
#error "TPM_AUTH_SESSIONS require SHA1 to be configured, too"
#endif /* !CONFIG_SHA1 */
#endif /* CONFIG_TPM_AUTH_SESSIONS */
#ifdef CONFIG_TPM_FLUSH_RESOURCES
#endif /* CONFIG_TPM_FLUSH_RESOURCES */
#ifdef CONFIG_TPM_AUTH_SESSIONS
#ifdef CONFIG_TPM_LOAD_KEY_BY_SHA1
#endif /* CONFIG_TPM_LOAD_KEY_BY_SHA1 */
#endif /* CONFIG_TPM_AUTH_SESSIONS */
