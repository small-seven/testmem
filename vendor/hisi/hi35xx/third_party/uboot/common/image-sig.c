#ifdef USE_HOSTCC
#include "mkimage.h"
#include <time.h>
#else
#include <common.h>
#include <malloc.h>
#endif /* !USE_HOSTCC*/
#include <image.h>
#include <u-boot/rsa.h>
#include <u-boot/rsa-checksum.h>
#define IMAGE_MAX_HASHED_NODES		100
#ifdef USE_HOSTCC
#endif
#if IMAGE_ENABLE_SIGN
#endif
#if IMAGE_ENABLE_SIGN
#endif
#ifdef CONFIG_FIT_ENABLE_RSASSA_PSS_SUPPORT
#endif /* CONFIG_FIT_ENABLE_RSASSA_PSS_SUPPORT */
#if !defined(USE_HOSTCC) && defined(CONFIG_NEEDS_MANUAL_RELOC)
#if IMAGE_ENABLE_SIGN
#endif
#endif
#if !defined(USE_HOSTCC) && defined(CONFIG_NEEDS_MANUAL_RELOC)
#endif
#ifndef CONFIG_SPL_BUILD
#endif
