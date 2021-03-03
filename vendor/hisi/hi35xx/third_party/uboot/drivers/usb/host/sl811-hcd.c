#include <common.h>
#include <mpc8xx.h>
#include <usb.h>
#include "sl811.h"
#include "../../../board/kup/common/kup.h"
#ifdef __PPC__
# define EIEIO		__asm__ volatile ("eieio")
#else
# define EIEIO		/* nothing */
#endif
#define	 SL811_ADR (0x50000000)
#define	 SL811_DAT (0x50000001)
#ifdef SL811_DEBUG
#endif
#define OK(x)	len = (x); break
#ifdef SL811_DEBUG
#endif
