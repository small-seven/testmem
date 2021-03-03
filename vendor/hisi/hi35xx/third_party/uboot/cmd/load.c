#include <common.h>
#include <command.h>
#include <console.h>
#include <cpu_func.h>
#include <env.h>
#include <s_record.h>
#include <net.h>
#include <exports.h>
#include <serial.h>
#include <xyzModem.h>
#if defined(CONFIG_CMD_LOADB)
#endif
#if defined(CONFIG_CMD_LOADS)
# if defined(CONFIG_CMD_SAVES)
#endif
#endif
#if defined(CONFIG_CMD_LOADS)
#ifdef	CONFIG_SYS_LOADS_BAUD_CHANGE
#endif
#ifdef	CONFIG_SYS_LOADS_BAUD_CHANGE
#else	/* ! CONFIG_SYS_LOADS_BAUD_CHANGE */
#endif	/* CONFIG_SYS_LOADS_BAUD_CHANGE */
#ifdef	CONFIG_SYS_LOADS_BAUD_CHANGE
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#if defined(CONFIG_CMD_SAVES)
#ifdef	CONFIG_SYS_LOADS_BAUD_CHANGE
#endif
#ifdef	CONFIG_SYS_LOADS_BAUD_CHANGE
#else	/* ! CONFIG_SYS_LOADS_BAUD_CHANGE */
#endif	/* CONFIG_SYS_LOADS_BAUD_CHANGE */
#ifdef	CONFIG_SYS_LOADS_BAUD_CHANGE
#endif
#define SREC3_START				"S0030000FC\n"
#define SREC3_FORMAT			"S3%02X%08lX%s%02X\n"
#define SREC3_END				"S70500000000FA\n"
#define SREC_BYTES_PER_RECORD	16
# endif
#endif
#if defined(CONFIG_CMD_LOADB)
#define XON_CHAR        17
#define XOFF_CHAR       19
#define START_CHAR      0x01
#define ETX_CHAR	0x03
#define END_CHAR        0x0D
#define SPACE           0x20
#define K_ESCAPE        0x23
#define SEND_TYPE       'S'
#define DATA_TYPE       'D'
#define ACK_TYPE        'Y'
#define NACK_TYPE       'N'
#define BREAK_TYPE      'B'
#define tochar(x) ((char) (((x) + SPACE) & 0xff))
#define untochar(x) ((int) (((x) - SPACE) & 0xff))
#define SEND_DATA_SIZE  20
#if 0
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#endif
#if defined(CONFIG_CMD_LOADS)
#ifdef	CONFIG_SYS_LOADS_BAUD_CHANGE
#else	/* ! CONFIG_SYS_LOADS_BAUD_CHANGE */
#endif	/* CONFIG_SYS_LOADS_BAUD_CHANGE */
#if defined(CONFIG_CMD_SAVES)
#ifdef	CONFIG_SYS_LOADS_BAUD_CHANGE
#else	/* ! CONFIG_SYS_LOADS_BAUD_CHANGE */
#endif	/* CONFIG_SYS_LOADS_BAUD_CHANGE */
#endif	/* CONFIG_CMD_SAVES */
#endif	/* CONFIG_CMD_LOADS */
#if defined(CONFIG_CMD_LOADB)
#endif	/* CONFIG_CMD_LOADB */
