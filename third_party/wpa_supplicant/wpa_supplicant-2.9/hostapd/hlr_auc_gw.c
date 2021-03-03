#include "includes.h"
#include <sys/un.h>
#ifdef CONFIG_SQLITE
#include <sqlite3.h>
#endif /* CONFIG_SQLITE */
#include "common.h"
#include "crypto/milenage.h"
#include "crypto/random.h"
#define EAP_SIM_MAX_CHAL 3
#define EAP_AKA_RAND_LEN 16
#define EAP_AKA_AUTN_LEN 16
#define EAP_AKA_AUTS_LEN 14
#define EAP_AKA_RES_MIN_LEN 4
#define EAP_AKA_RES_MAX_LEN 16
#define EAP_AKA_IK_LEN 16
#define EAP_AKA_CK_LEN 16
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef AKA_USE_FIXED_TEST_VALUES
#else /* AKA_USE_FIXED_TEST_VALUES */
#endif /* AKA_USE_FIXED_TEST_VALUES */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_SQLITE
#else /* CONFIG_SQLITE */
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
