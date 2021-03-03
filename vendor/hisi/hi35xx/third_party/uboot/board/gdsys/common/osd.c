#ifdef CONFIG_GDSYS_LEGACY_DRIVERS
#include <common.h>
#include <i2c.h>
#include <malloc.h>
#include "ch7301.h"
#include "dp501.h"
#include <gdsys_fpga.h>
#define ICS8N3QV01_I2C_ADDR 0x6E
#define ICS8N3QV01_FREF 114285000
#define ICS8N3QV01_FREF_LL 114285000LL
#define ICS8N3QV01_F_DEFAULT_0 156250000LL
#define ICS8N3QV01_F_DEFAULT_1 125000000LL
#define ICS8N3QV01_F_DEFAULT_2 100000000LL
#define ICS8N3QV01_F_DEFAULT_3  25175000LL
#define SIL1178_MASTER_I2C_ADDRESS 0x38
#define SIL1178_SLAVE_I2C_ADDRESS 0x39
#define PIXCLK_640_480_60 25180000
#define MAX_X_CHARS 53
#define MAX_Y_CHARS 26
#ifdef CONFIG_SYS_OSD_DH
#define MAX_OSD_SCREEN 8
#define OSD_DH_BASE 4
#else
#define MAX_OSD_SCREEN 4
#endif
#ifdef CONFIG_SYS_OSD_DH
#define OSD_SET_REG(screen, fld, val) \
#else
#define OSD_SET_REG(screen, fld, val) \
#endif
#ifdef CONFIG_SYS_OSD_DH
#define OSD_GET_REG(screen, fld, val) \
#else
#define OSD_GET_REG(screen, fld, val) \
#endif
#ifdef CONFIG_SYS_ICS8N3QV01_I2C
#endif
#ifdef CONFIG_SYS_SIL1178_I2C
#endif
#ifdef CONFIG_SYS_MPC92469AC
#endif
#ifdef CONFIG_SYS_ICS8N3QV01_I2C
#endif
#ifdef CONFIG_SYS_OSD_DH
#else
#endif
#ifdef CONFIG_SYS_OSD_DH
#else
#endif
#ifdef CONFIG_SYS_MPC92469AC
#endif
#ifdef CONFIG_SYS_ICS8N3QV01_I2C
#endif
#ifdef CONFIG_SYS_CH7301_I2C
#endif
#ifdef CONFIG_SYS_SIL1178_I2C
#endif
#ifdef CONFIG_SYS_DP501_I2C
#endif
#endif /* CONFIG_GDSYS_LEGACY_DRIVERS */