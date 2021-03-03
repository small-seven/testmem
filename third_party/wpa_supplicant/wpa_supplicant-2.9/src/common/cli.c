#include "includes.h"
#include "utils/common.h"
#include "common/cli.h"
void cli_txt_list_free(struct cli_txt_entry *e)
{
	dl_list_del(&e->list);
	os_free(e->txt);
	os_free(e);
}
