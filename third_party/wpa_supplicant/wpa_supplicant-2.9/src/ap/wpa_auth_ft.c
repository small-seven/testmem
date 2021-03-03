#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/list.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "common/ocv.h"
#include "drivers/driver.h"
#include "crypto/aes.h"
#include "crypto/aes_siv.h"
#include "crypto/aes_wrap.h"
#include "crypto/sha384.h"
#include "crypto/random.h"
#include "ap_config.h"
#include "ieee802_11.h"
#include "wmm.h"
#include "wpa_auth.h"
#include "wpa_auth_i.h"
#include "pmksa_cache_auth.h"
#ifdef CONFIG_IEEE80211R_AP
#define RRB_MIN_MSG_LEN 64
#define RRB_GET_SRC(srcfield, type, field, txt, checklength) do { \
#define RRB_GET(type, field, txt, checklength) \
#define RRB_GET_AUTH(type, field, txt, checklength) \
#define RRB_GET_OPTIONAL_SRC(srcfield, type, field, txt, checklength) do { \
#define RRB_GET_OPTIONAL(type, field, txt, checklength) \
#define RRB_GET_OPTIONAL_AUTH(type, field, txt, checklength) \
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
static void wpa_ft_rrb_seq_free(struct ft_remote_item *item)
{
	eloop_cancel_timeout(wpa_ft_rrb_seq_timeout, ELOOP_ALL_CTX, item);
	dl_list_del(&item->list);
	bin_clear_free(item->enc, item->enc_len);
	os_free(item->auth);
	os_free(item);
}
#define FT_RRB_SEQ_OK    0
#define FT_RRB_SEQ_DROP  1
#define FT_RRB_SEQ_DEFER 2
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef NEED_AP_MLME
#endif /* NEED_AP_MLME */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#endif /* CONFIG_IEEE80211R_AP */
