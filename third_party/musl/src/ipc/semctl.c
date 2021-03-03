#include <sys/sem.h>
#include <stdarg.h>
#include <endian.h>
#include <unsupported_api.h>
#include "syscall.h"
#include "ipc.h"
#if __BYTE_ORDER != __BIG_ENDIAN
#undef SYSCALL_IPC_BROKEN_MODE
#endif
#ifdef SYSCALL_IPC_BROKEN_MODE
#endif
#ifndef SYS_ipc
#else
#endif
#ifdef SYSCALL_IPC_BROKEN_MODE
#endif
#if IPC_TIME64
#endif
