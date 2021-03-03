#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "dbus_common.h"
#include "dbus_common_i.h"
#include "dbus_new.h"
#include "dbus_new_helpers.h"
#include "dbus_new_handlers.h"
#include "dbus_dict_helpers.h"
#define MAX_SIG_LEN 256
#ifdef CONFIG_CTRL_IFACE_DBUS_INTRO
#else /* CONFIG_CTRL_IFACE_DBUS_INTRO */
#endif /* CONFIG_CTRL_IFACE_DBUS_INTRO */
#define WPA_DBUS_SEND_PROP_CHANGED_TIMEOUT 5000
