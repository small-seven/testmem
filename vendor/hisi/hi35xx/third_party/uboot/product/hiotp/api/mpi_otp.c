#include "hi_mpi_otp.h"
#include "sys_otp.h"
#include "user_osal_lib.h"
#include "drv_ioctl_otp.h"
#define OTP_INIT_MAX_NUM     0x7FFFFFFF
#define mpi_check_otp_not_init() \
