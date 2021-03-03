#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "hugetlb.h"
#include "tst_safe_sysv_ipc.h"
#include "tst_test.h"
#define PROTECTION		(PROT_READ | PROT_WRITE)
#define PATH_MEMINFO		"/proc/meminfo"
#define PATH_PROC_VM		"/proc/sys/vm/"
#define PATH_PROC_OVER		PATH_PROC_VM "nr_overcommit_hugepages"
#define PATH_PROC_HUGE		PATH_PROC_VM "nr_hugepages"
#define PATH_SHMMAX		"/proc/sys/kernel/shmmax"
#ifdef __ia64__
#define ADDR (void *)(0x8000000000000000UL)
#define FLAGS (MAP_SHARED | MAP_FIXED)
#define SHMAT_FLAGS (SHM_RND)
#else
#define ADDR (void *)(0x0UL)
#define FLAGS (MAP_SHARED)
#define SHMAT_FLAGS (0)
#endif
#ifndef SHM_HUGETLB
#define SHM_HUGETLB 04000
#endif
#define MOUNT_DIR "hugemmap05"
#define TEST_FILE MOUNT_DIR "/file"
