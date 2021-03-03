#include "includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_common.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "bss.h"
#include "scan.h"
#include "p2p_supplicant.h"
#if defined(__CYGWIN__) || defined(CONFIG_NATIVE_WINDOWS)
#define ENOTCONN -1
#define EOPNOTSUPP -1
#define ECANCELED -1
#endif
#define MEASURE_REQUEST_LCI_LEN (3 + 1 + 4)
#define MEASURE_REQUEST_CIVIC_LEN (3 + 5)
#define MPDU_REPORT_LEN (int) (IEEE80211_MAX_MMPDU_SIZE - IEEE80211_HDRLEN - 3)
#undef MPDU_REPORT_LEN
