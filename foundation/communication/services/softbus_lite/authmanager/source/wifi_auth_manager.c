#include "wifi_auth_manager.h"
#include <stdlib.h>
#include "aes_gcm.h"
#include "auth_conn.h"
#include "auth_conn_manager.h"
#include "auth_interface.h"
#include "bus_manager.h"
#include "message.h"
#include "msg_get_deviceid.h"
#include "os_adapter.h"
#include "securec.h"
#define DEFAULT_INT_LEN 4
#define DEFAULT_LONG_LEN 8
#define AUTH_CONN_MAX_NUM 32
#ifdef SOFTBUS_DEBUG
#endif
void AuthMngDeInit(void)
{
    g_authPort = -1;
    g_sessionPort = -1;
}
#ifdef SOFTBUS_DEBUG
#endif
