#include <common.h>
#include <cli.h>
#include <malloc.h>
#include <errno.h>
#include <linux/list.h>
#include "menu.h"
static inline void *menu_item_destroy(struct menu *m,
				struct menu_item *item,
				void *extra)
{
	if (item->key)
		free(item->key);

	free(item);

	return NULL;
}
int menu_destroy(struct menu *m)
{
	if (!m)
		return -EINVAL;

	menu_items_iter(m, menu_item_destroy, NULL);

	if (m->title)
		free(m->title);

	free(m);

	return 1;
}
