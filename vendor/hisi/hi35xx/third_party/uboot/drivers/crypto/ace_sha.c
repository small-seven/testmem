#include <common.h>
#include "ace_sha.h"
#ifdef CONFIG_SHA_HW_ACCEL
#include <u-boot/sha256.h>
#include <u-boot/sha1.h>
#include <linux/errno.h>
#endif /* CONFIG_SHA_HW_ACCEL */
#ifdef CONFIG_LIB_HW_RAND
#endif /* CONFIG_LIB_HW_RAND */
