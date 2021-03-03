#include "client_factory.h"
#include <ohos_errno.h>
#include "registry.h"
#include "memory_adapter.h"
#include "thread_adapter.h"
#include "default_client.h"
typedef struct Factory Factory;
struct Factory {
    SaName key;
    Creator creator;
    Destroyer destroyer;
};
void *SAMGR_CreateIClient(const char *service, const char *feature, uint32 size)
{
    if (service == NULL) {
        return NULL;
    }

    if (g_mutex == NULL) {
        return NULL;
    }

    Factory *factory = GetFactory(service, feature);
    if (factory == NULL) {
        return NULL;
    }

    return factory->creator(service, feature, size);
}
int SAMGR_ReleaseIClient(const char *service, const char *feature, void *iClient)
{
    if (service == NULL || iClient == NULL) {
        return EC_INVALID;
    }

    if (g_mutex == NULL) {
        return EC_NOHANDLER;
    }

    Factory *factory = GetFactory(service, feature);
    if (factory == NULL) {
        return EC_NOHANDLER;
    }
    factory->destroyer(service, feature, iClient);
    return EC_SUCCESS;
}
