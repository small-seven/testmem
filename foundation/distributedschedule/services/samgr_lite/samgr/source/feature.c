#include "feature.h"
#include "feature_impl.h"
#include "memory_adapter.h"
FeatureImpl *FEATURE_CreateInstance(Feature *feature)
{
    if (feature == NULL) {
        return NULL;
    }
    FeatureImpl *featureImpl = (FeatureImpl *)SAMGR_Malloc(sizeof(FeatureImpl));
    if (featureImpl == NULL) {
        return NULL;
    }
    featureImpl->feature = feature;
    featureImpl->iUnknown = NULL;
    return featureImpl;
}