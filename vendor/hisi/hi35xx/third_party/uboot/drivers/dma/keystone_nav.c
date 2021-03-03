#include <common.h>
#include <asm/io.h>
#include <asm/ti-common/keystone_nav.h>
struct qm_host_desc *qm_pop_from_free_pool(void)
{
	return qm_pop(qm_cfg->qpool_num);
}
