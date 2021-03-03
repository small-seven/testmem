#include <common.h>
#include <env.h>
#include <image.h>
#include <android_image.h>
#include <malloc.h>
#include <errno.h>
#include <asm/unaligned.h>
#define ANDROID_IMAGE_DEFAULT_KERNEL_ADDR	0x10008000
#if !defined(CONFIG_SPL_BUILD)
#endif
