#include "includes.h"
#include "common.h"
#include "crypto/md5.h"
#include "crypto/sha1.h"
#include "crypto/sha256.h"
#include "crypto/sha384.h"
#include "crypto/sha512.h"
#include "crypto/aes_wrap.h"
#include "crypto/crypto.h"
#include "ieee802_11_defs.h"
#include "defs.h"
#include "wpa_common.h"
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifndef CONFIG_FIPS
#endif /* CONFIG_FIPS */
#if defined(CONFIG_IEEE80211R) || defined(CONFIG_IEEE80211W)
#endif /* CONFIG_IEEE80211R || CONFIG_IEEE80211W */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#ifdef CONFIG_SUITEB192
#endif /* CONFIG_SUITEB192 */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#if defined(CONFIG_IEEE80211R) && defined(CONFIG_SHA384)
#endif /* CONFIG_IEEE80211R && CONFIG_SHA384 */
#define MAX_Z_LEN 66 /* with NIST P-521 */
#if defined(CONFIG_SUITEB192) || defined(CONFIG_FILS)
#else /* CONFIG_SUITEB192 || CONFIG_FILS */
#endif /* CONFIG_SUITEB192 || CONFIG_FILS */
#if defined(CONFIG_IEEE80211W) || defined(CONFIG_SAE) || defined(CONFIG_FILS)
#else /* CONFIG_IEEE80211W or CONFIG_SAE or CONFIG_FILS */
#endif /* CONFIG_IEEE80211W or CONFIG_SAE or CONFIG_FILS */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211R
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#else /* CONFIG_IEEE80211W */
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211R
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#endif /* CONFIG_IEEE80211R */
#if defined(CONFIG_FILS) || defined(CONFIG_SHA384)
#endif /* CONFIG_FILS || CONFIG_SHA384 */
#if defined(CONFIG_IEEE80211W) || defined(CONFIG_FILS)
#endif /* CONFIG_IEEE80211W || CONFIG_FILS */
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#ifdef CONFIG_SUITEB192
#endif /* CONFIG_SUITEB192 */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#if defined(CONFIG_IEEE80211R) || defined(CONFIG_FILS)
#endif /* CONFIG_IEEE80211R || CONFIG_FILS */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
