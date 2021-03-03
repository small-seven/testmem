#include "dmslite.h"
#include <pthread.h>
#include "dmslite_log.h"
#include "dmslite_msg_parser.h"
#include "dmslite_session.h"
#include "discovery_service.h"
#include "iunknown.h"
#include "ohos_errno.h"
#include "ohos_init.h"
#include "samgr_lite.h"
#define DMS_PUBLISHID 1
#define CAPABILITY "ddmpCapability"
#define CAPABILITY_DATA ""
#define CAPABILITY_DATA_LENGTH 0
#define BUNDLE_NAME "dms"
#define EMPTY_FEATURE_NAME ""
