#include <common.h>
#include <malloc.h>
#include <linux/stat.h>
#include <linux/time.h>
#include <linux/ctype.h>
#include <asm/byteorder.h>
#include "zfs_common.h"
#include "div64.h"
#include <zfs/zfs.h>
#include <zfs/zio.h>
#include <zfs/dnode.h>
#include <zfs/uberblock_impl.h>
#include <zfs/vdev_impl.h>
#include <zfs/zio_checksum.h>
#include <zfs/zap_impl.h>
#include <zfs/zap_leaf.h>
#include <zfs/zfs_znode.h>
#include <zfs/dmu.h>
#include <zfs/dmu_objset.h>
#include <zfs/sa_impl.h>
#include <zfs/dsl_dir.h>
#include <zfs/dsl_dataset.h>
#define	ZPOOL_PROP_BOOTFS		"bootfs"
#define	NV_ENCODE_NATIVE	0
#define	NV_ENCODE_XDR		1
#define	NV_BIG_ENDIAN			0
#define	NV_LITTLE_ENDIAN	1
#define	DATA_TYPE_UINT64	8
#define	DATA_TYPE_STRING	9
#define	DATA_TYPE_NVLIST	19
#define	DATA_TYPE_NVLIST_ARRAY	20
#define	P2PHASE(x, align)		((x) & ((align) - 1))
#define	DVA_OFFSET_TO_PHYS_SECTOR(offset)					\
#define	P2ALIGN(x, align)		((x) & -(align))
#define	ZFS_CRC64_POLY 0xC96C5795D7870F42ULL	/* ECMA-182, reflected form */
#define	ZAP_HASH_IDX(hash, n)	(((n) == 0) ? 0 : ((hash) >> (64 - (n))))
#define	CHAIN_END	0xffff	/* end of the chunk chain */
#define	ZAP_LEAF_ARRAY_BYTES (ZAP_LEAF_CHUNKSIZE - 3)
#define	ZAP_LEAF_HASH_SHIFT(bs)	(bs - 5)
#define	ZAP_LEAF_HASH_NUMENTRIES(bs) (1 << ZAP_LEAF_HASH_SHIFT(bs))
#define	LEAF_HASH(bs, h)												\
#define	ZAP_LEAF_NUMCHUNKS(bs)						\
#define	ZAP_LEAF_CHUNK(l, bs, idx)										\
#define	ZAP_LEAF_ENTRY(l, bs, idx) (&ZAP_LEAF_CHUNK(l, bs, idx).l_entry)
#ifndef	NBBY
#define	NBBY	8
#endif
typedef int zfs_decomp_func_t(void *s_start, void *d_start,
							  uint32_t s_len, uint32_t d_len);
typedef struct decomp_entry {
	char *name;
	zfs_decomp_func_t *decomp_func;
} decomp_entry_t;
typedef struct dnode_end {
	dnode_phys_t dn;
	zfs_endian_t endian;
} dnode_end_t;
