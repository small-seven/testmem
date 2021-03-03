#include "dmslite_check_remote_permission.h"
#include <unistd.h>
#include "distributed_service_interface.h"
#include "dmslite_log.h"
#include "bundle_inner_interface.h"
#include "bundle_manager.h"
#include "ohos_errno.h"
#include "samgr_lite.h"
#include "securec.h"
#define DELIMITER_LENGTH 1
#define GET_BUNDLE_WITHOUT_ABILITIES 0
