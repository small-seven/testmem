#include <common.h>
#include <malloc.h>
#include "dhry.h"
#ifndef REG
#define REG
#else
#endif
#ifdef TIMES
#define Too_Small_Time 120
#endif
#ifdef TIME
#define Too_Small_Time 2
#endif
#ifdef PRATTLE
#endif /* PRATTLE */
#ifdef SELF_TIMED
#ifdef TIMES
#endif
#ifdef TIME
#endif
#endif /* SELF_TIMED */
#ifdef SELF_TIMED 
#ifdef TIMES
#endif
#ifdef TIME
#endif
#endif /* SELF_TIMED */
#ifdef SELF_TIMED
#ifdef TIME
#else
#endif
#endif /* SELF_TIMED */
#ifdef  NOSTRUCTASSIGN
#endif
