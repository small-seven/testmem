/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OHOS_DISTRIBUTEDSCHEDULE_DMSLITE_FEATURE_H
#define OHOS_DISTRIBUTEDSCHEDULE_DMSLITE_FEATURE_H

#include "distributed_service_interface.h"
#include "feature.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef struct {
    /* as a feature */
    INHERIT_FEATURE;
    /* implement the dmslite interface */
    INHERIT_IUNKNOWNENTRY(DmsLiteInterface);
    Identity identity;
} DmsLite;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif // OHOS_DISTRIBUTEDSCHEDULE_DMSLITE_FEATURE_H
