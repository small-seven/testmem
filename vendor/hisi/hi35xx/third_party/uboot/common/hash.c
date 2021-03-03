#ifndef USE_HOSTCC
#include <common.h>
#include <command.h>
#include <env.h>
#include <malloc.h>
#include <mapmem.h>
#include <hw_sha.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <u-boot/crc.h>
#else
#include "mkimage.h"
#include <time.h>
#include <image.h>
#endif /* !USE_HOSTCC*/
#include <hash.h>
#include <u-boot/crc.h>
#include <u-boot/sha1.h>
#include <u-boot/sha256.h>
#include <u-boot/md5.h>
#if !defined(USE_HOSTCC) && defined(CONFIG_NEEDS_MANUAL_RELOC)
#endif
#if defined(CONFIG_SHA1) && !defined(CONFIG_SHA_PROG_HW_ACCEL)
#endif
#if defined(CONFIG_SHA256) && !defined(CONFIG_SHA_PROG_HW_ACCEL)
#endif
#ifdef CONFIG_SHA1
#ifdef CONFIG_SHA_HW_ACCEL
#else
#endif
#ifdef CONFIG_SHA_PROG_HW_ACCEL
#else
#endif
#endif
#ifdef CONFIG_SHA256
#ifdef CONFIG_SHA_HW_ACCEL
#else
#endif
#ifdef CONFIG_SHA_PROG_HW_ACCEL
#else
#endif
#endif
#if defined(CONFIG_SHA256) || defined(CONFIG_CMD_SHA1SUM) || \
#define multi_hash()	1
#else
#define multi_hash()	0
#endif
#if !defined(USE_HOSTCC) && defined(CONFIG_NEEDS_MANUAL_RELOC)
#endif
#ifndef USE_HOSTCC
#if defined(CONFIG_CMD_HASH) || defined(CONFIG_CMD_SHA1SUM) || defined(CONFIG_CMD_CRC32)
#if defined(CONFIG_CRC32_VERIFY) || defined(CONFIG_SHA1SUM_VERIFY) || \
#else
#endif
#endif /* CONFIG_CMD_HASH || CONFIG_CMD_SHA1SUM || CONFIG_CMD_CRC32) */
#endif /* !USE_HOSTCC */
