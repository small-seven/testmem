#include "i2c_if.h"
#include "devsvc_manager_clnt.h"
#include "hdf_base.h"
#include "hdf_log.h"
#include "i2c_core.h"
#include "osal_mem.h"
#include "securec.h"
#define HDF_LOG_TAG i2c_if
#define SERVICE_NAME_LEN 32
#define I2C_BUS_MAX 8
