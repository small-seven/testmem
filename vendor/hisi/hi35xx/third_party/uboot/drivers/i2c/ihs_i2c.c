#include <common.h>
#include <i2c.h>
#ifdef CONFIG_DM_I2C
#include <dm.h>
#include <regmap.h>
#else
#include <gdsys_fpga.h>
#endif
#include <asm/unaligned.h>
#ifdef CONFIG_DM_I2C
#define ihs_i2c_set(map, member, val) \
#define ihs_i2c_get(map, member, valp) \
#else /* !CONFIG_DM_I2C */
#ifdef CONFIG_SYS_I2C_IHS_DUAL
#define I2C_SET_REG(fld, val) \
#else
#define I2C_SET_REG(fld, val) \
#endif
#ifdef CONFIG_SYS_I2C_IHS_DUAL
#define I2C_GET_REG(fld, val) \
#else
#define I2C_GET_REG(fld, val) \
#endif
#endif /* CONFIG_DM_I2C */
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else /* CONFIG_DM_I2C */
#ifdef CONFIG_SYS_I2C_INIT_BOARD
#endif
#ifdef CONFIG_SYS_I2C_IHS_CH0
#ifdef CONFIG_SYS_I2C_IHS_DUAL
#endif
#endif
#ifdef CONFIG_SYS_I2C_IHS_CH1
#ifdef CONFIG_SYS_I2C_IHS_DUAL
#endif
#endif
#ifdef CONFIG_SYS_I2C_IHS_CH2
#ifdef CONFIG_SYS_I2C_IHS_DUAL
#endif
#endif
#ifdef CONFIG_SYS_I2C_IHS_CH3
#ifdef CONFIG_SYS_I2C_IHS_DUAL
#endif
#endif
#endif /* CONFIG_DM_I2C */
