#include <common.h>
#include <dm.h>
#include <fsl_validate.h>
#include <fsl_secboot_err.h>
#include <fsl_sfp.h>
#include <fsl_sec.h>
#include <command.h>
#include <malloc.h>
#include <u-boot/rsa-mod-exp.h>
#include <hash.h>
#include <fsl_secboot_err.h>
#ifdef CONFIG_ARCH_LS1021A
#include <asm/arch/immap_ls102xa.h>
#endif
#define SHA256_BITS	256
#define SHA256_BYTES	(256/8)
#define SHA256_NIBBLES	(256/4)
#define NUM_HEX_CHARS	(sizeof(ulong) * 2)
#define CHECK_KEY_LEN(key_len)	(((key_len) == 2 * KEY_SIZE_BYTES / 4) || \
#if defined(CONFIG_FSL_ISBC_KEY_EXT)
#endif
#ifdef CONFIG_ESBC_HDR_LS
#else
#endif
#if defined(CONFIG_FSL_ISBC_KEY_EXT)
#if defined(CONFIG_MPC85xx)
#else
#endif
#if defined(CONFIG_ESBC_HDR_LS)
#else /* CONFIG_ESBC_HDR_LS */
#if defined(CONFIG_FSL_TRUST_ARCH_v1) && defined(CONFIG_FSL_CORENET)
#else
#endif
#if defined(CONFIG_MPC85xx)
#else
#endif
#endif /* CONFIG_ESBC_HDR_LS */
#endif
#ifdef CONFIG_KEY_REVOCATION
#ifdef CONFIG_ESBC_HDR_LS
#if defined(CONFIG_FSL_ISBC_KEY_EXT)
#endif
#else
#endif
#endif
#ifndef CONFIG_ESBC_HDR_LS
#endif /* CONFIG_ESBC_HDR_LS */
#if defined(CONFIG_FSL_ISBC_KEY_EXT)
#endif
#ifndef CONFIG_SPL_BUILD
#else
#endif
#ifdef CONFIG_KEY_REVOCATION
#endif
#if defined(CONFIG_FSL_ISBC_KEY_EXT)
#endif
#ifdef CONFIG_KEY_REVOCATION
#endif
#ifdef CONFIG_KEY_REVOCATION
#endif
#if defined(CONFIG_FSL_ISBC_KEY_EXT)
#endif
#ifndef CONFIG_ESBC_HDR_LS
#endif
#ifdef CONFIG_KEY_REVOCATION
#endif
#if defined(CONFIG_FSL_ISBC_KEY_EXT)
#endif
#ifndef CONFIG_ESBC_HDR_LS
#endif
#ifndef CONFIG_ESBC_HDR_LS
#endif
#if !defined(USE_HOSTCC)
#endif
#if defined(CONFIG_FSL_ISBC_KEY_EXT)
#endif
#if defined(CONFIG_FSL_ISBC_KEY_EXT)
#endif
