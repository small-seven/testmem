#include "includes.h"
#include <dlfcn.h>
#include "common.h"
#include "base64.h"
#include "common/tnc.h"
#include "tncs.h"
#include "eap_common/eap_tlv_common.h"
#include "eap_common/eap_defs.h"
#ifndef TNC_CONFIG_FILE
#define TNC_CONFIG_FILE "/etc/tnc_config"
#endif /* TNC_CONFIG_FILE */
#define IF_TNCCS_START \
#define IF_TNCCS_END "\n</TNCCS-Batch>"
#define TNC_MAX_IMV_ID 10
