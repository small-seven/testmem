#include "pub_sub_implement.h"
#include "securec.h"
#include "ohos_errno.h"
#include "memory_adapter.h"
#include "thread_adapter.h"
PubSubImplement *BCE_CreateInstance(Feature *feature)
{
    g_pubSubImplement.feature = (PubSubFeature *)feature;
    return &g_pubSubImplement;
}
