#include "drv_otp.h"
#include "drv_osal_lib.h"
#include "hal_otp.h"
#include "drv_osal_chip.h"
#define hal_otp_read_sta0(sta)              hal_otp_read_word(OTP_USER_LOCK_STA0, sta)
#define hal_otp_read_rev_data(data)         hal_otp_read_word(OTP_USER_REV_RDATA, data)
#define hal_otp_set_rev_addr(offset)        hal_otp_write_word(OTP_USER_REV_ADDR, offset)
#define hal_otp_set_rev_data(data)          hal_otp_write_word(OTP_USER_REV_WDATA, data)
#define hal_otp_set_work_mode(mode)         hal_otp_write_word(OTP_USER_WORK_MODE, mode)
#define hal_otp_set_key_index(idx)          hal_otp_write_word(OTP_USER_KEY_INDEX, idx);
#define hal_otp_set_flag_index(idx)         hal_otp_write_word(OTP_USER_FLAG_INDEX, idx);
#define hal_otp_set_flag_value(value)       hal_otp_write_word(OTP_USER_FLAG_VALUE, value);
#define hal_otp_op_start()                  hal_otp_write_word(OTP_USER_OP_START, OTP_OP_START_VAL)
static hi_s32 hal_otp_wait_op_free(hi_void)
{
    hi_s32 ret;
    hi_u32 time_out_cnt = OTP_WAIT_TIME_OUT;
    hi_u32 sta;

    while (time_out_cnt--) {
        ret = hal_otp_read_word(OTP_USER_CTRL_STA, &sta);
        hi_otp_func_fail_return(hal_otp_read_word, ret != HI_SUCCESS, ret);

        if (((sta >> OTP_CTRL_STA_OP_BUSY) & 0x01) == 0) {
            return HI_SUCCESS;
        }
    }
    hi_otp_err("otp wait op timeout!\n");
    return HI_ERR_OTP_BUSY;
}
