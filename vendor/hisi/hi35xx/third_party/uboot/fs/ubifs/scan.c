#ifdef __UBOOT__
#include <hexdump.h>
#include <linux/err.h>
#endif
#include "ubifs.h"
void ubifs_scan_destroy(struct ubifs_scan_leb *sleb)
{
	struct ubifs_scan_node *node;
	struct list_head *head;

	head = &sleb->nodes;
	while (!list_empty(head)) {
		node = list_entry(head->next, struct ubifs_scan_node, list);
		list_del(&node->list);
		kfree(node);
	}
	kfree(sleb);
}
