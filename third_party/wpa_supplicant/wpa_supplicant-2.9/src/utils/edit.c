#include "includes.h"
#include <termios.h>
#include "common.h"
#include "eloop.h"
#include "list.h"
#include "edit.h"
#define CMD_BUF_LEN 4096
#define HISTORY_MAX 100
#define CLEAR_END_LINE "\e[K"
void edit_deinit(const char *history_file,
		 int (*filter_cb)(void *ctx, const char *cmd))
{
	struct edit_history *h;
	if (history_file)
		history_write(history_file, filter_cb);
	while ((h = dl_list_first(&history_list, struct edit_history, list))) {
		dl_list_del(&h->list);
		os_free(h);
	}
	edit_clear_line();
	putchar('\r');
	fflush(stdout);
	eloop_unregister_read_sock(STDIN_FILENO);
	tcsetattr(STDIN_FILENO, TCSANOW, &prevt);
}
