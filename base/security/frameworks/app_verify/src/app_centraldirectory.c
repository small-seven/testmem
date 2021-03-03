#include "app_centraldirectory.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "app_common.h"
#include "mbedtls/base64.h"
#include "mbedtls/md.h"
#include "mbedtls/pk.h"
#include "mbedtls/x509_crt.h"
#include "mbedtls_pkcs7.h"
#include "securec.h"
bool CreateHapBuffer(HapBuf *hapBuffer, int len)
{
    if (hapBuffer == NULL || len <= 0) {
        LOG_ERROR("create buf fail, buf is null");
        return false;
    }
    hapBuffer->buffer = APPV_MALLOC(len);
    if (hapBuffer->buffer == NULL) {
        LOG_ERROR("create buf fail");
        return false;
    }
    hapBuffer->len = len;
    return true;
}
