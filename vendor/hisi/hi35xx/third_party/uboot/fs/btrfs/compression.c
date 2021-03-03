#include "btrfs.h"
#include <malloc.h>
#include <linux/lzo.h>
#include <linux/zstd.h>
#include <u-boot/zlib.h>
#include <asm/unaligned.h>
#define PRESET_DICT 0x20
#define ZSTD_BTRFS_MAX_WINDOWLOG 17
#define ZSTD_BTRFS_MAX_INPUT (1 << ZSTD_BTRFS_MAX_WINDOWLOG)
