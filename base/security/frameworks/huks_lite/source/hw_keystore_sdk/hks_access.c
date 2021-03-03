#include "hks_access.h"
#include <stdio.h>
#include <string.h>
#include "securec.h"
#include "hks_errno.h"
#include "soft_service/hks_service.h"
#include "soft_service/hks_rkc.h"
#include "soft_service/hks_storage.h"
#include "common/hks_log_utils.h"
#include "common/hks_mem.h"
#ifdef _SECURE_ENVIREMENT_NMI_
#define write_uint32(value, addr)               (*((volatile uint32_t *)(addr)) = (value))
#define NMI_REG_BASE_TRIGGER                    0x40010258
#endif /* _SECURE_ENVIREMENT_NMI_ */
#define SEC_MODE_DATA 0xe3
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#ifndef _SUPPORT_HKS_TEE_
void hks_access_destroy(void)
{
    hks_service_destroy();
}
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#ifndef _SUPPORT_HKS_TEE_
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#endif
#ifndef _SUPPORT_HKS_TEE_
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#endif
#ifndef _SUPPORT_HKS_TEE_
#ifdef _SECURE_ENVIREMENT_NMI_
#else
#endif
#else
#endif
#ifdef _SECURE_ENVIREMENT_NMI_
#endif
