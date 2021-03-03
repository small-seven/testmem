#include "mkimage.h"
#include <bootm.h>
#include <image.h>
#include <version.h>
static void strlist_free(struct strlist *list)
{
	int i;

	for (i = 0; i < list->count; i++)
		free(list->strings[i]);
	free(list->strings);
}
#ifdef CONFIG_FIT_SIGNATURE
#endif
