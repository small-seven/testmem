#include <common.h>
#include <command.h>
#include <env.h>
#include <errno.h>
#include <ide.h>
#include <malloc.h>
#include <part.h>
#include <ubifs_uboot.h>
#undef	PART_DEBUG
#ifdef	PART_DEBUG
#define	PRINTF(fmt,args...)	printf (fmt ,##args)
#else
#define PRINTF(fmt,args...)
#endif
#define PART_TYPE_ALL		-1
#ifdef CONFIG_HAVE_BLOCK_DEVICE
#else
#endif
#ifdef CONFIG_HAVE_BLOCK_DEVICE
#ifdef CONFIG_LBA48
typedef uint64_t lba512_t;
#else
typedef lbaint_t lba512_t;
#endif

/*
 * Overflowless variant of (block_count * mul_by / 2**div_by)
 * when div_by > mul_by
 */
static lba512_t lba512_muldiv(lba512_t block_count, lba512_t mul_by, int div_by)
{
	lba512_t bc_quot, bc_rem;

	/* x * m / d == x / d * m + (x % d) * m / d */
	bc_quot = block_count >> div_by;
	bc_rem  = block_count - (bc_quot << div_by);
	return bc_quot * mul_by + ((bc_rem * mul_by) >> div_by);
}
#ifdef CONFIG_LBA48
#endif
#if defined(CONFIG_SYS_64BIT_LBA)
#else
#endif
#endif
#ifdef CONFIG_HAVE_BLOCK_DEVICE
#if CONFIG_IS_ENABLED(MAC_PARTITION) || \
#endif /* any CONFIG_..._PARTITION */
#endif /* CONFIG_HAVE_BLOCK_DEVICE */
#ifdef CONFIG_HAVE_BLOCK_DEVICE
#if CONFIG_IS_ENABLED(PARTITION_UUIDS)
#endif
#ifdef CONFIG_PARTITION_TYPE_GUID
#endif
#endif /* CONFIG_HAVE_BLOCK_DEVICE */
#if CONFIG_IS_ENABLED(PARTITION_UUIDS)
#endif
#ifdef CONFIG_PARTITION_TYPE_GUID
#endif
#ifdef CONFIG_HAVE_BLOCK_DEVICE
#endif
#define PART_UNSPECIFIED -2
#define PART_AUTO -1
#ifdef CONFIG_SANDBOX
#if CONFIG_IS_ENABLED(PARTITION_UUIDS)
#endif
#ifdef CONFIG_PARTITION_TYPE_GUID
#endif
#endif
#ifdef CONFIG_CMD_UBIFS
#if CONFIG_IS_ENABLED(PARTITION_UUIDS)
#endif
#endif
