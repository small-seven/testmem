#include "pake_server.h"
#include "log.h"
#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_))
#include <securec.h>
#include "huks_adapter.h"
#include "mem_stat.h"
#ifdef DESC
#undef DESC
#endif
#define DESC(...) 1
#define HICHAIN_SPEKE_BASE_INFO       "hichain_speke_base_info"
#define HICHAIN_RETURN_KEY            "hichain_return_key"
#define HICHAIN_SPEKE_SESSIONKEY_INFO "hichain_speke_sessionkey_info"
#if DESC("interface")
void destroy_pake_server(struct pake_server *pake_server)
{
    if (pake_server == NULL) {
        return;
    }

    LOGI("Destroy pake server object %u success", pake_server_sn(pake_server));
    FREE(pake_server);
}
#endif /* DESC */
#if DESC("virtual") /* called by base class */
#endif /* DESC */
#else /* _CUT_XXX_ */
#include "stdlib_south.h"
void destroy_pake_server(struct pake_server *pake_server)
{
    LOGE("Donot support pake protocol");
    FREE(pake_server);
}
#endif /* _CUT_XXX_ */
