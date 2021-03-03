#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdint.h>
#include "tst_test.h"
#include "tst_safe_sysv_ipc.h"
#include "libnewipc.h"
#define ALIGN_DOWN(in_addr) ((void *)(((uintptr_t)in_addr / SHMLBA) * SHMLBA))
