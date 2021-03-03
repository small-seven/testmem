#include "hal_otp.h"
#include "cipher_adapt.h"
#ifdef OTP_SUPPORT
typedef enum {
	OTP_USER_LOCK_STA0_TYPE,
	OTP_USER_LOCK_STA1_TYPE,
	OTP_USER_LOCK_UNKNOWN_STA,
} opt_lock_sta_type_e;
typedef enum {
	OTP_READ_LOCK_STA_MODE,
	OTP_LOCK_CIPHER_KEY_MODE,
	OTP_WRITE_KEY_ID_OR_PASSWD_MODE,
	OTP_KEY_ID_OR_PASSWD_CRC_MODE,
	OTP_SET_FLAG_ENABLE_MODE,
	OTP_WRITE_USER_ROOM_MODE,
	OTP_READ_USER_ROOM_MODE,
	OTP_UNKOOWN_MODE,
} otp_user_work_mode_e;
typedef enum {
	OTP_USER_KEY0,
	OTP_USER_KEY1,
	OTP_USER_KEY2,
	OTP_USER_KEY3,
	OTP_USER_KEY_JTAG_PW_ID,
	OTP_USER_KEY_JTAG_PW,
	OTP_USER_KEY_ROOTKEY,
	OTP_USER_KEY_UNKNOWN,
} otp_user_key_index_e;
typedef enum {
	OTP_KEY_LENGTH_64BIT,
	OTP_KEY_LENGTH_128BIT,
	OTP_KEY_LENGTH_256BIT,
	OTP_KEY_LENGTH_UNSUPPORT,
} otp_user_key_length_e;
#ifdef OTP_CRG_RESET_SUPPORT
#endif
static hi_s32 hal_otp_wait_free(hi_void)
{
	hi_u32 timeout_cnt = 0;
	hi_u32 reg_value = 0;

	while (1) {
		hal_cipher_read_reg(OTP_USER_CTRL_STA, &reg_value);
		if ((reg_value & 0x1) == 0) /* bit0:otp_op_busy 0:idle, 1:busy */
			return HI_SUCCESS;

		timeout_cnt++;
		if (timeout_cnt >= 10000) { /* 10000 count */
			hi_err_cipher("OTP_WaitFree TimeOut!\n");
			break;
		}
	}
	return HI_FAILURE;
}
#endif
