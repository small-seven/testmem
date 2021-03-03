#include "tcu_authentication.h"
#include <errno.h> /* for errno */
#include <fcntl.h>
#include <sys/ioctl.h> /* for ioctl */
#include <sys/types.h> /* for open close */
#include <unistd.h>
#include "securec.h"
#include "tc_ns_client.h"
#include "tee_client_type.h"
#include "tee_log.h"
#include "teec_compat.h"
#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG            "teec_auth_native"
#define HASH_FILE_MAX_SIZE (16 * 1024)
#define VENDOR_HASH_FILE "/vendor/bin/native_packages.xml"
