#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "tst_test.h"
#include "lapi/mmap.h"
#define TMP_DIR "tmp_madvise"
#define TEST_FILE TMP_DIR"/testfile"
#define KSM_SYS_DIR "/sys/kernel/mm/ksm"
#define STR "abcdefghijklmnopqrstuvwxyz12345\n"
