#include <config.h>
#include <common.h>
#include <blk.h>
#include <env.h>
#include <fastboot.h>
#include <fastboot-internal.h>
#include <fb_mmc.h>
#include <image-sparse.h>
#include <part.h>
#include <mmc.h>
#include <div64.h>
#include <linux/compat.h>
#include <android_image.h>
#define FASTBOOT_MAX_BLK_WRITE 16384
#define BOOT_PARTITION_NAME "boot"
#ifdef CONFIG_ANDROID_BOOT_IMAGE
#endif
#if CONFIG_IS_ENABLED(EFI_PARTITION)
#endif
#if CONFIG_IS_ENABLED(DOS_PARTITION)
#endif
#ifdef CONFIG_ANDROID_BOOT_IMAGE
#endif
