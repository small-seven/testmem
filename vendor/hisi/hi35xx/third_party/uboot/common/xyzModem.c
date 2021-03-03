#include <common.h>
#include <xyzModem.h>
#include <stdarg.h>
#include <u-boot/crc.h>
#include <watchdog.h>
#define SOH 0x01
#define STX 0x02
#define EOT 0x04
#define ACK 0x06
#define BSP 0x08
#define NAK 0x15
#define CAN 0x18
#define EOF 0x1A		/* ^Z for DOS officionados */
#define xyzModem_CHAR_TIMEOUT            2000	/* 2 seconds */
#define xyzModem_MAX_RETRIES             20
#define xyzModem_MAX_RETRIES_WITH_CRC    10
#define xyzModem_CAN_COUNT                3	/* Wait for 3 CAN before quitting */
typedef int cyg_int32;
static int
CYGACC_COMM_IF_GETC_TIMEOUT (char chan, char *c)
{

  ulong now = get_timer(0);
  WATCHDOG_RESET();
  while (!tstc ())
    {
      if (get_timer(now) > xyzModem_CHAR_TIMEOUT)
        break;
    }
#if defined(DEBUG) && !CONFIG_IS_ENABLED(USE_TINY_PRINTF)
#define ZM_DEBUG(x) x
#else
#define ZM_DEBUG(x)
#endif
#ifdef xyzModem_zmodem
#endif
#ifdef xyzModem_zmodem
#endif
