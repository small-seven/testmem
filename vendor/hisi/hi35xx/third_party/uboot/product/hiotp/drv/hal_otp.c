#include "hal_otp.h"
#include "drv_osal_lib.h"
#include "drv_ioctl_otp.h"
#define otp_read(addr)                  readl(addr)
#define otp_write(addr, data)           writel(data, addr)
#define hal_otp_read(offset)            otp_read((volatile hi_u8 *)(g_otp_base_vir_addr + (offset)))
#define hal_otp_write(offset, data)     otp_write((volatile hi_u8 *)(g_otp_base_vir_addr + (offset)), data)
#define hal_check_init_fail_return() \
