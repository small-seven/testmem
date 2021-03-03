#ifdef USE_HOSTCC
#include "mkimage.h"
#include <time.h>
#include <u-boot/crc.h>
#else
#include <linux/compiler.h>
#include <linux/kconfig.h>
#include <common.h>
#include <errno.h>
#include <mapmem.h>
#include <asm/io.h>
#include <malloc.h>
#endif /* !USE_HOSTCC*/
#include <bootm.h>
#include <image.h>
#include <bootstage.h>
#include <u-boot/crc.h>
#include <u-boot/md5.h>
#include <u-boot/sha1.h>
#include <u-boot/sha256.h>
#ifndef USE_HOSTCC
#endif /* !USE_HOSTCC */
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_FIT_PRINT)
#ifndef USE_HOSTCC
#endif
#else
#endif /* !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_FIT_PRINT) */
#ifdef CONFIG_SHA1
#else
#endif
#ifdef CONFIG_SHA256
#else
#endif
#ifdef CONFIG_MD5
#else
#endif
#ifdef CONFIG_ARM64_SUPPORT_AARCH32
#endif
#ifndef USE_HOSTCC
#endif
#if !defined(USE_HOSTCC) && !defined(CONFIG_SANDBOX)
#endif
#ifndef USE_HOSTCC
#endif
#if !defined(USE_HOSTCC) && defined(CONFIG_FIT_IMAGE_POST_PROCESS)
#endif
#ifndef USE_HOSTCC
#ifdef CONFIG_OF_LIBFDT_OVERLAY
#endif
#ifdef CONFIG_OF_LIBFDT_OVERLAY
#else
#endif
#endif
