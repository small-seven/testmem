#include <asm/unaligned.h>
#include <common.h>
#include <command.h>
#include <fdtdec.h>
#include <ide.h>
#include <malloc.h>
#include <memalign.h>
#include <part_efi.h>
#include <linux/compiler.h>
#include <linux/ctype.h>
#include <u-boot/crc.h>
#ifdef CONFIG_HAVE_BLOCK_DEVICE
#if CONFIG_IS_ENABLED(EFI_PARTITION)
#ifdef CONFIG_PARTITION_TYPE_GUID
#endif
#if CONFIG_IS_ENABLED(PARTITION_UUIDS)
#endif
#ifdef CONFIG_PARTITION_TYPE_GUID
#endif
#if CONFIG_IS_ENABLED(PARTITION_UUIDS)
#endif
#ifdef CONFIG_PARTITION_TYPE_GUID
#endif
#ifdef CONFIG_PARTITION_TYPE_GUID
#else
#endif
#if CONFIG_IS_ENABLED(PARTITION_UUIDS)
#endif
#if defined(CONFIG_EFI_PARTITION_ENTRIES_OFF)
#endif
#if defined(CONFIG_OF_CONTROL)
#endif
#endif
#endif
