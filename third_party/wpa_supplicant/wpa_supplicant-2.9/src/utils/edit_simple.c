#include "includes.h"
#include "common.h"
#include "eloop.h"
#include "edit.h"
#define CMD_BUF_LEN 4096
void edit_deinit(const char *history_file,
		 int (*filter_cb)(void *ctx, const char *cmd))
{
	eloop_unregister_read_sock(STDIN_FILENO);
}
