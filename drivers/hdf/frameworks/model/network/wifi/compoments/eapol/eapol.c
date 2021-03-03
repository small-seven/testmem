#include "eapol.h"
#include <stdint.h>
#include "securec.h"
#include "osal_time.h"
#include "osal_mem.h"
#include "hdf_log.h"
#define HDF_LOG_TAG             HDF_WIFI_EAPOL
#define RETURN_IF_INPUT_VALID(netDevice, buff) do {                 \
