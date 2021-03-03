#ifdef _SECURE_ENVIREMENT_NMI_
#include "hks_file_liteos.h"
#include "securec.h"
#include "hks_types.h"
#include "hks_errno.h"
#include "base/hi1131/hi_fs.h"
#include "hks_log_utils.h"
#define HKS_STORE_DIR "./hks_store/"
#define PATH_MAX_SIZE (256 + 64 + sizeof(HKS_STORE_DIR) + 1)
#endif /* _SECURE_ENVIREMENT_NMI_ */
