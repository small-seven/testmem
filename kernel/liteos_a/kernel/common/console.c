#include "console.h"
#include "fcntl.h"
#include "sys/ioctl.h"
#ifdef LOSCFG_FILE_MODE
#include "stdarg.h"
#endif
#include "unistd.h"
#include "securec.h"
#include "inode/inode.h"
#ifdef LOSCFG_SHELL_DMESG
#include "dmesg_pri.h"
#endif
#ifdef LOSCFG_SHELL
#include "shcmd.h"
#include "shell_pri.h"
#endif
#include "los_exc_pri.h"
#include "los_process_pri.h"
#include "user_copy.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define EACH_CHAR 1
#define UART_IOC_MAGIC   'u'
#define UART_CFG_ATTR    _IOW(UART_IOC_MAGIC, 5, int)
#define UART_CFG_PRIVATE    _IOW(UART_IOC_MAGIC, 6, int)
#define SHELL_ENTRYID_INVALID     0xFFFFFFFF
#define SHELL_TASK_PRIORITY       9
#define CONSOLE_CIRBUF_EVENT      0x02U
#define CONSOLE_SEND_TASK_EXIT    0x04U
#define CONSOLE_SEND_TASK_RUNNING 0x10U
#define MIN(a, b) ((a) < (b) ? (a) : (b))
STATIC INT32 ConsoleCtrlRightsRelease(CONSOLE_CB *consoleCB)
{
    if (ConsoleRefcountGet(consoleCB) == 0) {
        PRINT_ERR("console is free\n");
        (VOID)LOS_SemPost(consoleCB->consoleSem);
        return LOS_NOK;
    } else {
        ConsoleRefcountSet(consoleCB, FALSE);
        if ((ConsoleRefcountGet(consoleCB) == 0) &&
            (OsCurrTaskGet()->taskID != consoleCB->shellEntryId)) {
            (VOID)LOS_TaskResume(consoleCB->shellEntryId);
        }
    }
    (VOID)LOS_SemPost(consoleCB->consoleSem);
    return LOS_OK;
}
#ifdef LOSCFG_NET_TELNET
#endif
#define CONSOLE_SERIAL_1 "/dev/console1"
#define CONSOLE_TELNET_2 "/dev/console2"
#ifdef LOSCFG_NET_TELNET
#endif
#ifdef LOSCFG_SHELL
#endif
#ifdef LOSCFG_SHELL
#endif
#ifdef LOSCFG_SHELL_DMESG
#endif
#ifdef LOSCFG_SHELL_DMESG
#endif
#ifndef CONFIG_DISABLE_POLL
#endif
#ifdef LOSCFG_NET_TELNET
#endif
STATIC UINT32 OsConsoleDevDeinit(const CONSOLE_CB *consoleCB)
{
    INT32 ret;
    struct file *filep = NULL;
    struct inode *inode = NULL;
    CHAR *fullpath = NULL;
    struct inode_search_s desc;

    ret = vfs_normalize_path(NULL, consoleCB->name, &fullpath);
    if (ret < 0) {
        ret = EINVAL;
        goto ERROUT;
    }
    SETUP_SEARCH(&desc, fullpath, false);
    ret = inode_find(&desc);
    if (ret < 0) {
        ret = EACCES;
        goto ERROUT_WITH_FULLPATH;
    }
    inode = desc.node;

    filep = inode->i_private;
    if (filep != NULL) {
        (VOID)LOS_MemFree(m_aucSysMem0, filep); /* free filep what you malloc from console_init */
        inode->i_private = NULL;
    } else {
        ret = EBADF;
        goto ERROUT_WITH_INODE;
    }
    inode_release(inode);
    free(fullpath);
    (VOID)unregister_driver(consoleCB->name);
    return LOS_OK;

ERROUT_WITH_INODE:
    inode_release(inode);
ERROUT_WITH_FULLPATH:
    free(fullpath);
ERROUT:
    set_errno(ret);
    return LOS_NOK;
}
STATIC CirBufSendCB *ConsoleCirBufCreate(VOID)
{
    UINT32 ret;
    CHAR *fifo = NULL;
    CirBufSendCB *cirBufSendCB = NULL;
    CirBuf *cirBufCB = NULL;

    cirBufSendCB = (CirBufSendCB *)LOS_MemAlloc(m_aucSysMem0, sizeof(CirBufSendCB));
    if (cirBufSendCB == NULL) {
        return NULL;
    }
    (VOID)memset_s(cirBufSendCB, sizeof(CirBufSendCB), 0, sizeof(CirBufSendCB));

    fifo = (CHAR *)LOS_MemAlloc(m_aucSysMem0, TELNET_CIRBUF_SIZE);
    if (fifo == NULL) {
        goto ERROR_WITH_SENDCB;
    }
    (VOID)memset_s(fifo, TELNET_CIRBUF_SIZE, 0, TELNET_CIRBUF_SIZE);

    cirBufCB = &cirBufSendCB->cirBufCB;
    ret = LOS_CirBufInit(cirBufCB, fifo, TELNET_CIRBUF_SIZE);
    if (ret != LOS_OK) {
        goto ERROR_WITH_FIFO;
    }

    (VOID)LOS_EventInit(&cirBufSendCB->sendEvent);
    return cirBufSendCB;

ERROR_WITH_FIFO:
    (VOID)LOS_MemFree(m_aucSysMem0, cirBufCB->fifo);
ERROR_WITH_SENDCB:
    (VOID)LOS_MemFree(m_aucSysMem0, cirBufSendCB);
    return NULL;
}
STATIC VOID OsConsoleBufDeinit(CONSOLE_CB *consoleCB)
{
    CirBufSendCB *cirBufSendCB = consoleCB->cirBufSendCB;

    consoleCB->cirBufSendCB = NULL;
    (VOID)LOS_EventWrite(&cirBufSendCB->sendEvent, CONSOLE_SEND_TASK_EXIT);
}
STATIC VOID OsConsoleCBDeinit(CONSOLE_CB *consoleCB)
{
    (VOID)LOS_MemFree((VOID *)m_aucSysMem0, consoleCB->name);
    consoleCB->name = NULL;
    (VOID)LOS_MemFree((VOID *)m_aucSysMem0, consoleCB);
}
STATIC CONSOLE_CB *OsConsoleCreate(UINT32 consoleID, const CHAR *deviceName)
{
    INT32 ret;
    CONSOLE_CB *consoleCB = OsConsoleCBInit(consoleID);
    if (consoleCB == NULL) {
        PRINT_ERR("console malloc error.\n");
        return NULL;
    }

    ret = snprintf_s(consoleCB->name, CONSOLE_NAMELEN, CONSOLE_NAMELEN - 1,
                     "%s%u", CONSOLE, consoleCB->consoleID);
    if (ret == -1) {
        PRINT_ERR("consoleCB->name snprintf_s failed\n");
        goto ERR_WITH_NAME;
    }

    ret = (INT32)OsConsoleBufInit(consoleCB);
    if (ret != LOS_OK) {
        goto ERR_WITH_NAME;
    }

    ret = (INT32)LOS_SemCreate(1, &consoleCB->consoleSem);
    if (ret != LOS_OK) {
        PRINT_ERR("creat sem for uart failed\n");
        goto ERR_WITH_BUF;
    }

    ret = OsConsoleDevInit(consoleCB, deviceName);
    if (ret != LOS_OK) {
        goto ERR_WITH_SEM;
    }

    ret = OsConsoleFileInit(consoleCB);
    if (ret != LOS_OK) {
        goto ERR_WITH_DEV;
    }

    OsConsoleTermiosInit(consoleCB, deviceName);
    return consoleCB;

ERR_WITH_DEV:
    ret = (INT32)OsConsoleDevDeinit(consoleCB);
    if (ret != LOS_OK) {
        PRINT_ERR("OsConsoleDevDeinit failed!\n");
    }
ERR_WITH_SEM:
    (VOID)LOS_SemDelete(consoleCB->consoleSem);
ERR_WITH_BUF:
    OsConsoleBufDeinit(consoleCB);
ERR_WITH_NAME:
    OsConsoleCBDeinit(consoleCB);
    return NULL;
}
#ifdef LOSCFG_SHELL
#endif
#ifdef LOSCFG_SHELL
#endif
INT32 system_console_deinit(const CHAR *deviceName)
{
    UINT32 ret;
    CONSOLE_CB *consoleCB = NULL;
    UINT32 taskIdx;
    LosTaskCB *taskCB = NULL;
    UINT32 intSave;

    consoleCB = OsGetConsoleByDevice(deviceName);
    if (consoleCB == NULL) {
        return VFS_ERROR;
    }

#ifdef LOSCFG_SHELL
    (VOID)OsShellDeinit((INT32)consoleCB->consoleID);
#endif

    LOS_SpinLockSave(&g_consoleSpin, &intSave);
    /* Redirect all tasks to serial as telnet was unavailable after deinitializing */
    for (taskIdx = 0; taskIdx < g_taskMaxNum; taskIdx++) {
        taskCB = ((LosTaskCB *)g_taskCBArray) + taskIdx;
        if (OsTaskIsUnused(taskCB)) {
            continue;
        } else {
            g_taskConsoleIDArray[taskCB->taskID] = CONSOLE_SERIAL;
        }
    }
    g_console[consoleCB->consoleID - 1] = NULL;
    LOS_SpinUnlockRestore(&g_consoleSpin, intSave);

    ret = OsConsoleDelete(consoleCB);
    if (ret != LOS_OK) {
        PRINT_ERR("%s, Failed to system_console_deinit\n", __FUNCTION__);
        return VFS_ERROR;
    }

    return ENOERR;
}
#if defined (LOSCFG_DRIVERS_USB_SERIAL_GADGET) || defined (LOSCFG_DRIVERS_USB_ETH_SER_GADGET)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
