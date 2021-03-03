#include "utils/includes.h"
#include "utils/common.h"
#include "common/defs.h"
#include "list.h"
#include "fst/fst.h"
#include "fst/fst_internal.h"
#include "fst_ctrl_defs.h"
#include "fst_ctrl_iface.h"
static int session_remove(const char *session_id, char *buf, size_t buflen)
{
	struct fst_session *s;
	struct fst_group *g;
	u32 id;

	id = strtoul(session_id, NULL, 0);

	s = fst_session_get_by_id(id);
	if (!s) {
		fst_printf(MSG_WARNING, "CTRL: Cannot find session %u", id);
		return os_snprintf(buf, buflen, "FAIL\n");
	}

	g = fst_session_get_group(s);
	fst_session_reset(s);
	fst_session_delete(s);
	fst_group_delete_if_empty(g);

	return os_snprintf(buf, buflen, "OK\n");
}
#ifdef CONFIG_FST_TEST
#endif /* CONFIG_FST_TEST */
#ifdef CONFIG_FST_TEST
#endif /* CONFIG_FST_TEST */
