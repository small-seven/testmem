#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#include <string.h>
#include <securec.h>
#include "jsonutil.h"
#include "commonutil.h"
#include "exchange_auth_info.h"
#include "log.h"
#include "key_agreement_version.h"
void sec_clone_free_client_request(void *obj)
{
    free_single_buff(obj);
}
void sec_clone_free_client_ack(void *obj)
{
    free_single_buff(obj);
}
#else
#define DEFINE_SEC_CLONE_EMPTY_STRUCT_FUNC(name) \
#include "parsedata.h"
#endif
