#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/defs.h"
#include "fst/fst_internal.h"
#include "fst/fst_defs.h"
#include "fst/fst_ctrl_iface.h"
#ifdef CONFIG_FST_TEST
#include "fst/fst_ctrl_defs.h"
#endif /* CONFIG_FST_TEST */
#define US_80211_TU 1024
#define US_TO_TU(m) ((m) * / US_80211_TU)
#define TU_TO_US(m) ((m) * US_80211_TU)
#define FST_LLT_SWITCH_IMMEDIATELY 0
#define fst_printf_session(s, level, format, ...) \
#define fst_printf_siface(s, iface, level, format, ...) \
#define fst_printf_sframe(s, is_old, level, format, ...) \
#define FST_LLT_MS_DEFAULT 50
#define FST_ACTION_MAX_SUPPORTED   FST_ACTION_ON_CHANNEL_TUNNEL
#define foreach_fst_session(s) \
#define foreach_fst_session_safe(s, temp) \
#ifdef CONFIG_FST_TEST
#define FST_MAX_COMMAND_WORD_NAME_LENGTH 16
#endif /* CONFIG_FST_TEST */
