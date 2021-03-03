/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BASE_STARTUP_INITLITE_ADAPTER_H
#define BASE_STARTUP_INITLITE_ADAPTER_H
#define _GNU_SOURCE    // syscall function need this macro definition
#ifdef __LINUX__
#include <linux/capability.h>
#else
#include <sys/capability.h>
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#ifdef __LINUX__
extern int capset(void *a, void *b);
#endif

void RebootSystem();
int KeepCapability();

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif  // BASE_STARTUP_INITLITE_ADAPTER_H