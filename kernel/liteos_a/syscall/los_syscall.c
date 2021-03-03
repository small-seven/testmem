#define _GNU_SOURCE
#include "los_syscall.h"
#include "los_task_pri.h"
#include "los_process_pri.h"
#include "los_printf.h"
#include "time.h"
#include "utime.h"
#include "poll.h"
#include "mqueue.h"
#include "los_futex_pri.h"
#include "sys/times.h"
#ifdef LOSCFG_FS_VFS
#include "fs/fs.h"
#include "fs/file.h"
#endif
#include "dirent.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/mount.h"
#include "sys/resource.h"
#include "sys/mman.h"
#include "sys/uio.h"
#include "sys/prctl.h"
#include "sys/socket.h"
#include "sys/utsname.h"
#include "poll.h"
#include "sys/uio.h"
#ifdef LOSCFG_SHELL
#include "shmsg.h"
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#include "capability_api.h"
#endif
#include "sys/shm.h"
#define SYS_CALL_NUM    (__NR_syscallend + 1)
#define NARG_BITS       4
#define NARG_MASK       0x0F
#define NARG_PER_BYTE   2
typedef UINT32 (*SyscallFun1)(UINT32);
typedef UINT32 (*SyscallFun3)(UINT32, UINT32, UINT32);
typedef UINT32 (*SyscallFun5)(UINT32, UINT32, UINT32, UINT32, UINT32);
typedef UINT32 (*SyscallFun7)(UINT32, UINT32, UINT32, UINT32, UINT32, UINT32, UINT32);

static UINTPTR g_syscallHandle[SYS_CALL_NUM] = {0};
#define SYSCALL_HAND_DEF(id, fun, rType, nArg)                                             \
#undef SYSCALL_HAND_DEF
