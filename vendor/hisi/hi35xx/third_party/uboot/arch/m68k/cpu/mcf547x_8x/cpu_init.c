#include <common.h>
#include <MCD_dma.h>
#include <cpu_func.h>
#include <asm/immap.h>
#include <asm/io.h>
#if defined(CONFIG_CMD_NET)
#include <config.h>
#include <net.h>
#include <asm/fsl_mcdmafec.h>
#endif
#if (defined(CONFIG_SYS_CS0_BASE) && defined(CONFIG_SYS_CS0_MASK) && defined(CONFIG_SYS_CS0_CTRL))
#endif
#if (defined(CONFIG_SYS_CS1_BASE) && defined(CONFIG_SYS_CS1_MASK) && defined(CONFIG_SYS_CS1_CTRL))
#endif
#if (defined(CONFIG_SYS_CS2_BASE) && defined(CONFIG_SYS_CS2_MASK) && defined(CONFIG_SYS_CS2_CTRL))
#endif
#if (defined(CONFIG_SYS_CS3_BASE) && defined(CONFIG_SYS_CS3_MASK) && defined(CONFIG_SYS_CS3_CTRL))
#endif
#if (defined(CONFIG_SYS_CS4_BASE) && defined(CONFIG_SYS_CS4_MASK) && defined(CONFIG_SYS_CS4_CTRL))
#endif
#if (defined(CONFIG_SYS_CS5_BASE) && defined(CONFIG_SYS_CS5_MASK) && defined(CONFIG_SYS_CS5_CTRL))
#endif
#ifdef CONFIG_SYS_I2C_FSL
#endif
#if defined(CONFIG_CMD_NET) && defined(CONFIG_FSLDMAFEC)
#endif
#if defined(CONFIG_CMD_NET)
#endif
