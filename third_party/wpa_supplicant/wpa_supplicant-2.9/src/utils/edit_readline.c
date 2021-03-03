#include "includes.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "common.h"
#include "eloop.h"
#include "edit.h"
void edit_deinit(const char *history_file,
		 int (*filter_cb)(void *ctx, const char *cmd))
{
	rl_set_prompt("");
	rl_replace_line("", 0);
	rl_redisplay();
	rl_callback_handler_remove();
	readline_free_completions();

	eloop_unregister_read_sock(STDIN_FILENO);

	if (history_file) {
		/* Save command history, excluding lines that may contain
		 * passwords. */
		HIST_ENTRY *h;
		history_set_pos(0);
		while ((h = current_history())) {
			char *p = h->line;
			while (*p == ' ' || *p == '\t')
				p++;
			if (filter_cb && filter_cb(edit_cb_ctx, p)) {
				h = remove_history(where_history());
				if (h) {
					free(h->line);
					free(h->data);
					free(h);
				} else
					next_history();
			} else
				next_history();
		}
		write_history(history_file);
	}
}
