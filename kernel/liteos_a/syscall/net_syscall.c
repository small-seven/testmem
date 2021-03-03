#include "los_syscall.h"
#include "los_process_pri.h"
#include "lwip/sockets.h"
#include <stdlib.h>
#include "los_vm_map.h"
#include "user_copy.h"
#include "fs_file.h"
#ifdef LOSCFG_NET_LWIP_SACK
#define SOCKET_U2K(s) do { s = GetAssociatedSystemFd(s); } while (0)
#define SOCKET_K2U(s) \
#define CHECK_ASPACE(ptr, len, ...) \
static void *DupUserMem(const void *ptr, size_t len, int needCopy)
{
    void *p = malloc(len);
    if (p == NULL) {
        set_errno(ENOMEM);
        return NULL;
    }
    if (needCopy && LOS_ArchCopyFromUser(p, ptr, len) != 0) {
        free(p);
        set_errno(EFAULT);
        return NULL;
    }
    return p;
}
#define LEN(ptr) ((ptr) ? *(ptr) : 0)
#define DUP_FROM_USER_(ptr, size, copy, ...) \
#define DUP_FROM_USER(ptr, size, ...) \
#define DUP_FROM_USER_NOCOPY(ptr, size, ...) \
#define DUP_TO_USER(ptr, size, ...) \
#define FREE_DUP(ptr) \
#define CPY_FROM_USER(ptr) \
#define CPY_TO_USER(ptr, ...) \
#define CONST_CAST(ptr) ((__typeof(ptr##_NONCONST))ptr)
#define CHECK_FIELD_ASPACE(ptr, field, len) \
#define CHECK_ARRAY_FIELD_ASPACE(ptr, arr, arrlen, field, len, ...) \
#define DUP_FIELD_FROM_USER_(ptr, field, size, copy, ...) \
#define DUP_FIELD_FROM_USER(ptr, field, size, ...) \
#define DUP_FIELD_FROM_USER_NOCOPY(ptr, field, size, ...) \
#define DUP_ARRAY_FIELD_FROM_USER_(ext, ptr, arr, arrlen, field, len, ...) \
#define DUP_ARRAY_FIELD_FROM_USER(ptr, arr, arrlen, field, len, ...) \
#define DUP_ARRAY_FIELD_FROM_USER_NOCOPY(ptr, arr, arrlen, field, len, ...) \
#define FREE_DUP_FIELD(ptr, field) \
#define FREE_DUP_ARRAY_FIELD(ptr, arr, arrlen, field) \
#define CPY_FROM_CONST_USER(NonConstType, ptr) \
#define CPY_FROM_NONCONST_USER(ptr) \
#define DUP_FIELD_TO_USER(ptr, field, size, ...) \
#define DUP_ARRAY_FIELD_TO_USER(ptr, arr, arrlen, field, len, ...) \
#endif
