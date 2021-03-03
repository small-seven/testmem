#include "auth_interface.h"
#include "hichain.h"
#include "securec.h"
#include "auth_conn.h"
#include "bus_manager.h"
#include "os_adapter.h"
#include "wifi_auth_manager.h"
static void DestroyHiChain(void)
{
    SOFTBUS_PRINT("[AUTH] DestroyHiChain\n");
    if (g_hcHandle != NULL) {
        destroy(&g_hcHandle);
        g_hcHandle = NULL;
    }
}
