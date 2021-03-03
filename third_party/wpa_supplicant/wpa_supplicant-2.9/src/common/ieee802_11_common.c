#include "includes.h"
#include "common.h"
#include "defs.h"
#include "wpa_common.h"
#include "drivers/driver.h"
#include "qca-vendor.h"
#include "ieee802_11_defs.h"
#include "ieee802_11_common.h"
#define C2S(x) case x: return #x;
#undef C2S
#define R2S(r) case WLAN_REASON_ ## r: return #r;
#undef R2S
#define S2S(s) case WLAN_STATUS_ ## s: return #s;
#undef S2S
