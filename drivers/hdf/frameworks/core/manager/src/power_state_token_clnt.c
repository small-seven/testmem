#include "power_state_token_clnt.h"
#include "osal_mem.h"
void PowerStateTokenClntFreeInstance(struct PowerStateTokenClnt *tokenClnt)
{
    if (tokenClnt != NULL) {
        OsalMemFree(tokenClnt);
    }
}
