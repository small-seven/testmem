#include "security_auth_enhance.h"
#include <securec.h>
#include "securectype.h"
#include "tc_client_sub_driver.h"
#include "tc_ns_client.h"
#include "tc_ns_log.h"
#include "teek_client_constants.h"
#include "teek_client_type.h"
#include "tzdriver_compat.h"
#if !defined(UINT64_MAX)
#endif
#ifdef SECURITY_AUTH_ENHANCE
#define GLOBAL_CMD_ID_SSA               0x2DCB /* SSA cmdId 11723 */
#define GLOBAL_CMD_ID_MT                0x2DCC /* MT cmdId 11724 */
#define GLOBAL_CMD_ID_MT_UPDATE         0x2DCD /* MT_IPDATE cmdId 11725 */
#define TEEC_PENDING2_AGENT             0xFFFF2001
#endif
