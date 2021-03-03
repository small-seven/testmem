#include "drv_ioctl_otp.h"
#include "drv_osal_lib.h"
#if HI_OTP_TEST
#endif
#if HI_OTP_TEST
#endif
hi_s32 otp_memset(void *src, hi_u32 len1, int num, hi_u32 len2)
{
    if (len1 < len2) {
        hi_otp_err("len1 < len2!!!\n");
        return HI_ERR_OTP_INVALID_PARAM;
    }
    memset(src, num, len2);
    return EOK;
}
hi_s32 otp_memcpy(void *dst, hi_u32 len1, const void *src, hi_u32 len2)
{
    if (len1 < len2) {
        hi_otp_err("len1 < len2!!!\n");
        return HI_ERR_OTP_INVALID_PARAM;
    }
    memcpy(dst, src, len2);
    return EOK;
}
