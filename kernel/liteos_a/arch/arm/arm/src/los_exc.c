#include "los_exc.h"
#include "los_memory_pri.h"
#include "los_printf_pri.h"
#include "los_task_pri.h"
#include "los_hw_pri.h"
#ifdef LOSCFG_SHELL_EXCINFO
#include "los_excinfo_pri.h"
#endif
#ifdef LOSCFG_EXC_INTERACTION
#include "los_exc_interaction_pri.h"
#endif
#include "los_sys_stack_pri.h"
#include "los_stackinfo_pri.h"
#ifdef LOSCFG_COREDUMP
#include "los_coredump.h"
#endif
#ifdef LOSCFG_GDB
#include "gdb_int.h"
#endif
#include "los_mp.h"
#include "los_vm_map.h"
#include "los_vm_dump.h"
#include "los_arch_mmu.h"
#include "los_vm_phys.h"
#include "los_vm_fault.h"
#include "los_vm_common.h"
#include "arm.h"
#include "los_bitmap.h"
#include "los_process_pri.h"
#include "los_exc_pri.h"
#ifdef LOSCFG_FS_VFS
#include "console.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define INVALID_CPUID  0xFFFF
#define OS_EXC_VMM_NO_REGION  0x0U
#define OS_EXC_VMM_ALL_REGION 0x1U
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#define OS_MAX_BACKTRACE    15U
#define DUMPSIZE            128U
#define DUMPREGS            12U
#define INSTR_SET_MASK      0x01000020U
#define THUMB_INSTR_LEN     2U
#define ARM_INSTR_LEN       4U
#define POINTER_SIZE        4U
#define WNR_BIT             11U
#define FSR_FLAG_OFFSET_BIT 10U
#define FSR_BITS_BEGIN_BIT  3U
#define GET_FS(fsr) (((fsr) & 0xFU) | (((fsr) & (1U << 10)) >> 6))
#define GET_WNR(dfsr) ((dfsr) & (1U << 11))
#define IS_VALID_ADDR(ptr) (((ptr) >= g_minAddr) &&       \
STATIC VOID OsDumpProcessUsedMemRegion(LosProcessCB *runProcess, LosVmSpace *runspace, UINT16 vmmFlags)
{
    LosVmMapRegion *region = NULL;
    LosRbNode *pstRbNodeTemp = NULL;
    LosRbNode *pstRbNodeNext = NULL;
    UINT32 count = 0;

    /* search the region list */
    RB_SCAN_SAFE(&runspace->regionRbTree, pstRbNodeTemp, pstRbNodeNext)
        region = (LosVmMapRegion *)pstRbNodeTemp;
        PrintExcInfo("%3u -> regionBase: 0x%08x regionSize: 0x%08x\n", count, region->range.base, region->range.size);
        if (vmmFlags == OS_EXC_VMM_ALL_REGION) {
            OsDumpExcVaddrRegion(runspace, region);
        }
        count++;
        (VOID)OsRegionOverlapCheckUnlock(runspace, region);
    RB_SCAN_SAFE_END(&space->regionRbTree, pstRbNodeTemp, pstRbNodeNext)
}
STATIC VOID OsDumpProcessUsedMemNode(UINT16 vmmFalgs)
{
    LosProcessCB *runProcess = NULL;
    LosVmSpace *runspace = NULL;

    runProcess = OsCurrProcessGet();
    if (runProcess == NULL) {
        return;
    }

    if (!OsProcessIsUserMode(runProcess)) {
        return;
    }

    PrintExcInfo("\n   ******Current process %u vmm regions: ******\n", runProcess->processID);

    runspace = runProcess->vmSpace;
    if (!runspace) {
        return;
    }

    OsDumpProcessUsedMemRegion(runProcess, runspace, vmmFalgs);
    return;
}
VOID OsDumpContextMem(const ExcContext *excBufAddr)
{
    UINT32 count = 0;
    const UINT32 *excReg = NULL;
    if (g_excFromUserMode[ArchCurrCpuid()] == TRUE) {
        return;
    }

    for (excReg = &(excBufAddr->R0); count <= DUMPREGS; excReg++, count++) {
        if (IS_VALID_ADDR(*excReg)) {
            PrintExcInfo("\ndump mem around R%u:%p", count, (*excReg));
            OsDumpMemByte(DUMPSIZE, ((*excReg) - (DUMPSIZE >> 1)));
        }
    }

    if (IS_VALID_ADDR(excBufAddr->SP)) {
        PrintExcInfo("\ndump mem around SP:%p", excBufAddr->SP);
        OsDumpMemByte(DUMPSIZE, (excBufAddr->SP - (DUMPSIZE >> 1)));
    }
}
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#else
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#ifdef LOSCFG_FS_VFS
#endif
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#ifndef LOSCFG_DEBUG_VERSION
#endif
#ifndef LOSCFG_DEBUG_VERSION
#endif
#ifdef LOSCFG_COREDUMP
#endif
#ifdef LOSCFG_GDB
#if __LINUX_ARM_ARCH__ >= 7
#endif /* __LINUX_ARM_ARCH__ */
#endif /* LOSCFG_GDB */
#if (LOSCFG_KERNEL_SMP == YES)
#define EXC_WAIT_INTER 50U
#define EXC_WAIT_TIME  2000U
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#else
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#else
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#ifdef LOSCFG_FS_VFS
#endif
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#ifdef LOSCFG_EXC_INTERACTION
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
