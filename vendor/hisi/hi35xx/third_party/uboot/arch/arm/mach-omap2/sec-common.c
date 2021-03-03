#include <common.h>
#include <cpu_func.h>
#include <stdarg.h>
#include <asm/arch/sys_proto.h>
#include <asm/cache.h>
#include <asm/omap_common.h>
#include <asm/omap_sec_common.h>
#include <asm/spl.h>
#include <asm/ti-common/sys_proto.h>
#include <mapmem.h>
#include <spl.h>
#include <tee/optee.h>
#ifdef CONFIG_AM33XX
#define API_HAL_KM_VERIFYCERTIFICATESIGNATURE_INDEX	(0x0000000C)
#else
#define API_HAL_KM_VERIFYCERTIFICATESIGNATURE_INDEX	(0x0000000E)
#endif
#define PPA_HAL_SERVICES_START_INDEX        (0x200)
#define PPA_SERV_HAL_TEE_LOAD_MASTER        (PPA_HAL_SERVICES_START_INDEX + 23)
#define PPA_SERV_HAL_TEE_LOAD_SLAVE         (PPA_HAL_SERVICES_START_INDEX + 24)
#define PPA_SERV_HAL_SETUP_SEC_RESVD_REGION (PPA_HAL_SERVICES_START_INDEX + 25)
#define PPA_SERV_HAL_SETUP_EMIF_FW_REGION   (PPA_HAL_SERVICES_START_INDEX + 26)
#define PPA_SERV_HAL_LOCK_EMIF_FW           (PPA_HAL_SERVICES_START_INDEX + 27)
#define HEADER_SIZE_OFFSET	(0x6D)
#if defined(CONFIG_OMAP54XX)
#else
#endif
#if	(CONFIG_TI_SECURE_EMIF_TOTAL_REGION_SIZE <  \
#error	"TI Secure EMIF: Protected size cannot be larger than total size."
#endif
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#endif
#if defined(CONFIG_OMAP54XX)
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#endif
#endif
