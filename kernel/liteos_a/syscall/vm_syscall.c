#include "sys/types.h"
#include "sys/shm.h"
#include "errno.h"
#include "unistd.h"
#include "los_vm_syscall.h"
#include "fs_file.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
void *SysMmap(void *addr, size_t size, int prot, int flags, int fd, size_t offset)
{
    /* Process fd convert to system global fd */
    fd = GetAssociatedSystemFd(fd);

    return (void *)LOS_MMap((uintptr_t)addr, size, prot, flags, fd, offset);
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
