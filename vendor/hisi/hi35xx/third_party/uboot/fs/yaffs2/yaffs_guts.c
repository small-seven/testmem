#include "yportenv.h"
#include "yaffs_trace.h"
#include "yaffs_guts.h"
#include "yaffs_getblockinfo.h"
#include "yaffs_tagscompat.h"
#include "yaffs_nand.h"
#include "yaffs_yaffs1.h"
#include "yaffs_yaffs2.h"
#include "yaffs_bitmap.h"
#include "yaffs_verify.h"
#include "yaffs_nand.h"
#include "yaffs_packedtags2.h"
#include "yaffs_nameval.h"
#include "yaffs_allocator.h"
#include "yaffs_attribs.h"
#include "yaffs_summary.h"
#define YAFFS_GC_GOOD_ENOUGH 2
#define YAFFS_GC_PASSIVE_THRESHOLD 4
#include "yaffs_ecc.h"
#ifdef CONFIG_YAFFS_AUTO_UNICODE
#else
#endif
void yaffs_handle_defered_free(struct yaffs_obj *obj)
{
	if (obj->defered_free)
		yaffs_free_obj(obj);
}
#ifdef CONFIG_YAFFS_AUTO_UNICODE
#endif
#ifdef CONFIG_YAFFS_AUTO_UNICODE
#endif
#ifdef CONFIG_YAFFS_CASE_INSENSITIVE
#endif
