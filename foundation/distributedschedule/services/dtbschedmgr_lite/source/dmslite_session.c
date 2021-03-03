#include "dmslite_session.h"
#include <unistd.h>
#include "distributed_service_interface.h"
#include "dmslite_inner_common.h"
#include "dmslite_log.h"
#include "dmslite_msg_parser.h"
#include "ohos_errno.h"
#include "session.h"
#define DMS_SESSION_NAME "dms"
#define DMS_MODULE_NAME "dms"
#define ACCEPT_SESSION_OPEN 0
