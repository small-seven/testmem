#include <hi_stdlib.h>
#include <hi_sem.h>
#include "pwm_drv.h"
#define CLKEN1_PWM5     10
#define CLKEN1_PWM_BUS  6
#define CLKEN1_PWM      5
#define CLKEN1_PWM4     4
#define CLKEN1_PWM3     3
#define CLKEN1_PWM2     2
#define CLKEN1_PWM1     1
#define CLKEN1_PWM0     0
#define CLKEN1_PWM_ALL  ((1 << (CLKEN1_PWM0)) | (1 << (CLKEN1_PWM1)) | (1 << (CLKEN1_PWM2)) | (1 << (CLKEN1_PWM3)) | \
