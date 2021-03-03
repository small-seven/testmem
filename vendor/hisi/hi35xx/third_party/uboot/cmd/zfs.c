#include <common.h>
#include <part.h>
#include <config.h>
#include <command.h>
#include <env.h>
#include <image.h>
#include <linux/ctype.h>
#include <asm/byteorder.h>
#include <zfs_common.h>
#include <linux/stat.h>
#include <malloc.h>
#if defined(CONFIG_CMD_USB) && defined(CONFIG_USB_STORAGE)
#include <usb.h>
#endif
#if !CONFIG_IS_ENABLED(DOS_PARTITION) && !CONFIG_IS_ENABLED(EFI_PARTITION)
#error DOS or EFI partition support must be selected
#endif
#define DOS_PART_MAGIC_OFFSET	0x1fe
#define DOS_FS_TYPE_OFFSET	0x36
#define DOS_FS32_TYPE_OFFSET	0x52
