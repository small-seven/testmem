#include "includes.h"
#include "common.h"
#include "pcsc_funcs.h"
#include "crypto/milenage.h"
#include "crypto/random.h"
#include "eap_peer/eap_i.h"
#include "eap_config.h"
#include "eap_common/eap_sim_common.h"
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
#ifdef PCSC_FUNCS
#endif /* PCSC_FUNCS */
#ifdef CONFIG_SIM_SIMULATOR
#endif /* CONFIG_SIM_SIMULATOR */
#ifdef CONFIG_SIM_HARDCODED
#else /* CONFIG_SIM_HARDCODED */
#endif /* CONFIG_SIM_HARDCODED */
#define CLEAR_PSEUDONYM	0x01
#define CLEAR_REAUTH_ID	0x02
#define CLEAR_EAP_ID	0x04
#ifdef TEST_FUZZ
#else /* TEST_FUZZ */
#endif /* TEST_FUZZ */
#ifdef TEST_FUZZ
#else /* TEST_FUZZ */
#endif /* TEST_FUZZ */
#ifdef TEST_FUZZ
#else /* TEST_FUZZ */
#endif /* TEST_FUZZ */
