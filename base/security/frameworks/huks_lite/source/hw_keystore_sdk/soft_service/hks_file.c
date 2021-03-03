#include "hks_file.h"
#include "common/hks_common.h"
#include "common/hks_mem.h"
#include "common/hks_utility.h"
#include "hks_errno.h"
#ifdef _SECURE_ENVIREMENT_NMI_
#include "hks_file_liteos.h"
#endif
#define HKS_FILE_IO_SIZE_MAX 1024
#ifdef _SECURE_ENVIREMENT_NMI_
#endif
