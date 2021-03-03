#include "includes.h"
#include "common.h"
#include "defs.h"
#include "ieee802_11_defs.h"
#include "ieee802_11_common.h"
#include "hw_features_common.h"
#ifdef CONFIG_IEEE80211AC
#define VHT_CAP_CHECK(cap) \
#define VHT_CAP_CHECK_MAX(cap) \
#undef VHT_CAP_CHECK
#undef VHT_CAP_CHECK_MAX
#endif /* CONFIG_IEEE80211AC */
