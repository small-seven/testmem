#include "i2c.h"
#include <hi_sem.h>
#include <hi_i2c.h>
#include <hi_time.h>
#include <hi3861_platform_base.h>
#define I2C0_BASE HI_I2C0_REG_BASE
#define I2C1_BASE HI_I2C1_REG_BASE
#define CLKEN_I2C0 14
#define CLKEN_I2C1 15
typedef struct {
    hi_u32 baudrate;
    i2c_reset_func reset_bus_func;
    i2c_prepare_func prepare_func;
    i2c_restore_func restore_func;
    hi_u16 timeout_us;
    hi_u8 scl_h : 3;
    hi_u8 scl_l : 3;
    hi_bool init : 1;
    hi_bool pad : 1;
    hi_u8 err_times;
} hi_i2c_ctrl;
