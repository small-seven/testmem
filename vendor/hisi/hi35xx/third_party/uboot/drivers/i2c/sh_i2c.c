#include <common.h>
#include <i2c.h>
#include <asm/io.h>
#define ureg(name) u8 name; u8 __pad_##name##0; u16 __pad_##name##1;
#undef ureg
#define SH_I2C_ICCR_ICE		(1 << 7)
#define SH_I2C_ICCR_RACK	(1 << 6)
#define SH_I2C_ICCR_RTS		(1 << 4)
#define SH_I2C_ICCR_BUSY	(1 << 2)
#define SH_I2C_ICCR_SCP		(1 << 0)
#define SH_IC_BUSY	(1 << 4)
#define SH_IC_TACK	(1 << 2)
#define SH_IC_WAIT	(1 << 1)
#define SH_IC_DTE	(1 << 0)
#ifdef CONFIG_SH_I2C_8BIT
#define SH_I2C_ICIC_ICCLB8	(1 << 7)
#define SH_I2C_ICIC_ICCHB8	(1 << 6)
#endif
#ifdef CONFIG_SYS_I2C_SH_BASE1
#endif
#ifdef CONFIG_SYS_I2C_SH_BASE2
#endif
#ifdef CONFIG_SYS_I2C_SH_BASE3
#endif
#ifdef CONFIG_SYS_I2C_SH_BASE4
#endif
#define IRQ_WAIT 1000
#ifdef CONFIG_SH_I2C_8BIT
#endif
#if defined(CONFIG_SH73A0)
#else
#endif
#ifdef CONFIG_SYS_I2C_SH_BASE1
#endif
#ifdef CONFIG_SYS_I2C_SH_BASE2
#endif
#ifdef CONFIG_SYS_I2C_SH_BASE3
#endif
#ifdef CONFIG_SYS_I2C_SH_BASE4
#endif
