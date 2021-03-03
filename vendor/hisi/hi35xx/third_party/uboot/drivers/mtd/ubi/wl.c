#ifndef __UBOOT__
#include <linux/slab.h>
#include <linux/crc32.h>
#include <linux/freezer.h>
#include <linux/kthread.h>
#else
#include <ubi_uboot.h>
#endif
#include "ubi.h"
#include "wl.h"
#define WL_RESERVED_PEBS 1
#define UBI_WL_THRESHOLD CONFIG_MTD_UBI_WL_THRESHOLD
#define WL_FREE_MAX_DIFF (2*UBI_WL_THRESHOLD)
#define WL_MAX_FAILURES 32
static void wl_entry_destroy(struct ubi_device *ubi, struct ubi_wl_entry *e)
{
	ubi->lookuptbl[e->pnum] = NULL;
	kmem_cache_free(ubi_wl_entry_slab, e);
}
#ifdef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifdef __UBOOT__
#endif
#ifdef CONFIG_MTD_UBI_FASTMAP
#endif
#ifdef CONFIG_MTD_UBI_FASTMAP
#else
#endif
#ifndef __UBOOT__
#else
#endif
static void tree_destroy(struct ubi_device *ubi, struct rb_root *root)
{
	struct rb_node *rb;
	struct ubi_wl_entry *e;

	rb = root->rb_node;
	while (rb) {
		if (rb->rb_left)
			rb = rb->rb_left;
		else if (rb->rb_right)
			rb = rb->rb_right;
		else {
			e = rb_entry(rb, struct ubi_wl_entry, u.rb);

			rb = rb_parent(rb);
			if (rb) {
				if (rb->rb_left == &e->u.rb)
					rb->rb_left = NULL;
				else
					rb->rb_right = NULL;
			}

			wl_entry_destroy(ubi, e);
		}
	}
}
#ifdef CONFIG_MTD_UBI_FASTMAP
#ifndef __UBOOT__
#else
#endif
#endif
static void protection_queue_destroy(struct ubi_device *ubi)
{
	int i;
	struct ubi_wl_entry *e, *tmp;

	for (i = 0; i < UBI_PROT_QUEUE_LEN; ++i) {
		list_for_each_entry_safe(e, tmp, &ubi->pq[i], u.list) {
			list_del(&e->u.list);
			wl_entry_destroy(ubi, e);
		}
	}
}
#ifndef CONFIG_MTD_UBI_FASTMAP
#else
#include "fastmap-wl.c"
#endif
