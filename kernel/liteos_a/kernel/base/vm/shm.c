#include "stdio.h"
#include "string.h"
#include "time.h"
#include "sys/types.h"
#include "sys/shm.h"
#include "sys/stat.h"
#include "los_config.h"
#include "los_vm_map.h"
#include "los_vm_filemap.h"
#include "los_vm_phys.h"
#include "los_arch_mmu.h"
#include "los_vm_page.h"
#include "los_vm_lock.h"
#include "los_process.h"
#include "los_process_pri.h"
#include "user_copy.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define SYSV_SHM_LOCK()     (VOID)LOS_MuxLock(&g_sysvShmMux, LOS_WAIT_FOREVER)
#define SYSV_SHM_UNLOCK()   (VOID)LOS_MuxUnlock(&g_sysvShmMux)
#define SHM_MAX_PAGES 12800
#define SHM_MAX (SHM_MAX_PAGES * PAGE_SIZE)
#define SHM_MIN 1
#define SHM_MNI 192
#define SHM_SEG 128
#define SHM_ALL (SHM_MAX_PAGES)
#define SHM_SEG_FREE    0x2000
#define SHM_SEG_USED    0x4000
#define SHM_SEG_REMOVE  0x8000
#ifndef SHM_M
#define SHM_M   010000
#endif
#ifndef ACCESSPERMS
#define ACCESSPERMS (S_IRWXU | S_IRWXG | S_IRWXO)
#endif
#define SHM_GROUPE_TO_USER  3
#define SHM_OTHER_TO_USER   6
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif
