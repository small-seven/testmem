#include <linux/bitops.h>
#include <asm/armv7m.h>
#include <asm/armv7_mpu.h>
#include <asm/io.h>
#define V7M_MPU_CTRL_ENABLE		BIT(0)
#define V7M_MPU_CTRL_DISABLE		(0 << 0)
#define V7M_MPU_CTRL_HFNMIENA		BIT(1)
#define V7M_MPU_CTRL_PRIVDEFENA		BIT(2)
#define VALID_REGION			BIT(4)
