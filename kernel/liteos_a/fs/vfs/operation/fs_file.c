#include "fs_file.h"
#include "los_process_pri.h"
#include "fs/fd_table.h"
#include "fs/file.h"
#include "fs/fs.h"
int AllocSpecifiedProcessFd(int procFd)
{
    struct fd_table_s *fdt = GetFdTable();

    if (!IsValidProcessFd(fdt, procFd)) {
        return -EBADF;
    }

    FileTableLock(fdt);
    if (fdt->ft_fds[procFd].sysFd >= 0) {
        /* Disassociate procFd */
        fdt->ft_fds[procFd].sysFd = -1;
        FileTableUnLock(fdt);
        return OK;
    }

    if (FD_ISSET(procFd, fdt->proc_fds)) {
        /* procFd in race condition */
        FileTableUnLock(fdt);
        return -EBUSY;
    } else {
        /* Unused procFd */
        FD_SET(procFd, fdt->proc_fds);
    }

    FileTableUnLock(fdt);
    return OK;
}
void FreeProcessFd(int procFd)
{
    struct fd_table_s *fdt = GetFdTable();

    if (!IsValidProcessFd(fdt, procFd)) {
        return;
    }

    FileTableLock(fdt);
    FD_CLR(procFd, fdt->proc_fds);
    fdt->ft_fds[procFd].sysFd = -1;
    FileTableUnLock(fdt);
}
int AllocProcessFd(void)
{
    return AllocLowestProcessFd(MIN_START_FD);
}
int AllocLowestProcessFd(int minFd)
{
    struct fd_table_s *fdt = GetFdTable();

    if (fdt == NULL) {
        return VFS_ERROR;
    }

    /* minFd should be a positive number,and 0,1,2 had be distributed to stdin,stdout,stderr */
    if (minFd < MIN_START_FD) {
        minFd = MIN_START_FD;
    }

    FileTableLock(fdt);

    int procFd = AssignProcessFd(fdt, minFd);
    if (procFd == VFS_ERROR) {
        FileTableUnLock(fdt);
        return VFS_ERROR;
    }

    // occupy the fd set
    FD_SET(procFd, fdt->proc_fds);
    FileTableUnLock(fdt);

    return procFd;
}
int AllocAndAssocProcessFd(int sysFd, int minFd)
{
    struct fd_table_s *fdt = GetFdTable();

    if (fdt == NULL) {
        return VFS_ERROR;
    }

    /* minFd should be a positive number,and 0,1,2 had be distributed to stdin,stdout,stderr */
    if (minFd < MIN_START_FD) {
        minFd = MIN_START_FD;
    }

    FileTableLock(fdt);

    int procFd = AssignProcessFd(fdt, minFd);
    if (procFd == VFS_ERROR) {
        FileTableUnLock(fdt);
        return VFS_ERROR;
    }

    // occupy the fd set
    FD_SET(procFd, fdt->proc_fds);
    fdt->ft_fds[procFd].sysFd = sysFd;
    FileTableUnLock(fdt);

    return procFd;
}
int AllocAndAssocSystemFd(int procFd, int minFd)
{
    struct fd_table_s *fdt = GetFdTable();

    if (!IsValidProcessFd(fdt, procFd)) {
        return VFS_ERROR;
    }

    int sysFd = alloc_fd(minFd);
    if (sysFd < 0) {
        return VFS_ERROR;
    }

    FileTableLock(fdt);
    fdt->ft_fds[procFd].sysFd = sysFd;
    FileTableUnLock(fdt);

    return sysFd;
}
