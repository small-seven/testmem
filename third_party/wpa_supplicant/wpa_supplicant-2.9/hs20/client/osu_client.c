#include "includes.h"
#include <time.h>
#include <sys/stat.h>
#ifdef ANDROID
#include "private/android_filesystem_config.h"
#endif /* ANDROID */
#include "common.h"
#include "utils/browser.h"
#include "utils/base64.h"
#include "utils/xml-utils.h"
#include "utils/http-utils.h"
#include "common/wpa_ctrl.h"
#include "common/wpa_helpers.h"
#include "eap_common/eap_defs.h"
#include "crypto/crypto.h"
#include "crypto/sha256.h"
#include "osu_client.h"
#ifdef ANDROID
#endif  /* ANDROID */
#define TMP_CERT_DL_FILE "tmp-cert-download"
#ifdef ANDROID
#else /* ANDROID */
#endif /* ANDROID */
#ifdef __linux__
#endif /* __linux__ */
