#include "secfile_load_agent.h"
#include <errno.h>
#include <sys/prctl.h>
#include "securec.h"
#include "tc_ns_client.h"
#include "teec_compat.h"
#define MAX_PATH_LEN 256
#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG        "secload_agent_teecd"
#define MAX_BUFFER_LEN (8 * 1024 * 1024)
