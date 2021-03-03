#include "securecutil.h"
errno_t wmemcpy_s(wchar_t *dest, size_t destMax, const wchar_t *src, size_t count)
{
    if (destMax == 0 || destMax > SECUREC_WCHAR_MEM_MAX_LEN) {
        SECUREC_ERROR_INVALID_PARAMTER("wmemcpy_s");
        return ERANGE;
    }
    if (count > destMax) {
        SECUREC_ERROR_INVALID_PARAMTER("wmemcpy_s");
        if (dest != NULL) {
            (void)memset(dest, 0, destMax * sizeof(wchar_t));
            return ERANGE_AND_RESET;
        }
        return ERANGE;
    }
    return memcpy_s(dest, destMax * sizeof(wchar_t), src, count * sizeof(wchar_t));
}
