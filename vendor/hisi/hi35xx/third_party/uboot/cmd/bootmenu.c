#include <common.h>
#include <command.h>
#include <ansi.h>
#include <env.h>
#include <menu.h>
#include <watchdog.h>
#include <malloc.h>
#include <linux/string.h>
#define MAX_COUNT	99
#define MAX_ENV_SIZE	(9 + 2 + 1)
static void bootmenu_destroy(struct bootmenu_data *menu)
{
	struct bootmenu_entry *iter = menu->first;
	struct bootmenu_entry *next;

	while (iter) {
		next = iter->next;
		free(iter->title);
		free(iter->command);
		free(iter);
		iter = next;
	}
	free(menu);
}
#ifdef CONFIG_POSTBOOTMENU
#endif
#ifdef CONFIG_AUTOBOOT_MENU_SHOW
#endif
#if defined(CONFIG_BOOTDELAY) && (CONFIG_BOOTDELAY >= 0)
#endif
