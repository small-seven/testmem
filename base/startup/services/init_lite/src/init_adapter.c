#define _GNU_SOURCE    // syscall function need this macro definition
#include "init_adapter.h"
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/prctl.h>
#ifdef __LINUX__
#include <sys/reboot.h>
#else
#include <sys/syscall.h>
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#ifdef __LINUX__
#else
#endif
#ifdef __LINUX__
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
