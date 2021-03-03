#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "fst/fst.h"
#include "fst/fst_internal.h"
#include "fst/fst_defs.h"
#include "fst/fst_ctrl_iface.h"
void fst_global_deinit(void)
{
	struct fst_group *group;
	struct fst_ctrl_handle *h;

	if (!fst_global_initialized)
		return;

	fst_session_global_deinit();
	while ((group = fst_first_group()) != NULL)
		fst_group_delete(group);
	while ((h = dl_list_first(&fst_global_ctrls_list,
				  struct fst_ctrl_handle,
				  global_ctrls_lentry)))
		fst_global_del_ctrl(h);
	fst_global_initialized = 0;
}
#ifndef HOSTAPD
#endif /* HOSTAPD */
#ifndef HOSTAPD
#endif /* HOSTAPD */
